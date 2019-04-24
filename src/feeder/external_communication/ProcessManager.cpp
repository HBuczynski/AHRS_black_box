#include "ProcessManager.h"

#include <boost/interprocess/sync/named_mutex.hpp>
#include <config_reader/ConfigurationReader.h>
#include <interfaces/communication_process_feeder/CalibrationStatusNotification.h>
#include <iostream>

using namespace std;
using namespace utility;
using namespace config;
using namespace communication;
using namespace boost::interprocess;

ProcessManager::ProcessManager(const string &name, const hsm::TransitionTable &transitionTable, std::shared_ptr<hsm::State> rootState)
    :   hsm::HSM(name, transitionTable, rootState),
        feederExternalWirelessParameters_(ConfigurationReader::getFeederExternalWireless(FEEDER_PARAMETERS_FILE_PATH)),
        messageQueuesParameters_(ConfigurationReader::getFeederMessageQueues(FEEDER_PARAMETERS_FILE_PATH)),
        feederType_(ConfigurationReader::getFeederType(FEEDER_TYPE_FILE_PATH)),
        runConfigurationProcess_(true),
        logger_(Logger::getInstance())
{}

bool ProcessManager::initialize()
{
    bool isSuccess = true;

    isSuccess = isSuccess & initializeMessageQueueCommunication();
    isSuccess = isSuccess & initializeExternalCommunication();

    return isSuccess;
}

bool ProcessManager::initializeExternalCommunication()
{
    clientUDPManager_ = make_shared<ClientUDPManager>();

    switch (feederType_.processNumber)
    {
        case 1 :
        {
            server_ = make_shared<ServerTCP>(feederExternalWirelessParameters_.firstPort, feederExternalWirelessParameters_.maxUserNumber, clientUDPManager_);
            server_->startUserActivation();
            break;
        }
        case 2 :
        {
            server_ = make_shared<ServerTCP>(feederExternalWirelessParameters_.secondPort, feederExternalWirelessParameters_.maxUserNumber, clientUDPManager_);
            server_->startUserActivation();
            break;
        }
        default:
        {
            if(logger_.isErrorEnable())
            {
                const string message = "-MAIN- ProcessManager: Inappropriate process communication type.";
                logger_.writeLog(LogType::ERROR_LOG, message);
            }

            return false;
        }
    }

    if(logger_.isInformationEnable())
    {
        const string message = "-MAIN- ProcessManager: Initialized external communication process. Process type: " + to_string(static_cast<int>(feederType_.mode));
        logger_.writeLog(LogType::INFORMATION_LOG, message);
    }

    return true;
}

bool ProcessManager::initializeMessageQueueCommunication()
{
    try
    {
        receivingMessageQueue_ = make_shared<MessageQueueWrapper>(messageQueuesParameters_.externalCommunicationQueueName, messageQueuesParameters_.messageSize);
        sendingMessageQueue_ = make_shared<MessageQueueWrapper>(messageQueuesParameters_.mainProcessQueueName, messageQueuesParameters_.messageSize);
    }
    catch(interprocess_exception &ex)
    {
        if(logger_.isErrorEnable())
        {
            const string message = string("-MAIN- ProcessManager :: ") + ex.what();
            logger_.writeLog(LogType::ERROR_LOG, message);
        }

        return false;
    }

    return true;
}

void ProcessManager::start()
{
    while(runConfigurationProcess_)
    {
        try
        {
            const auto packet = receivingMessageQueue_->receive();
            const auto frameType = static_cast<FrameType>(packet[Frame::FRAME_TYPE]);

            if(frameType == FrameType::COMMAND)
            {
                const auto command = commandFactory_.createCommand(packet);
                command->accept(messageVisitor_);
            }
            else if (frameType == FrameType::NOTIFICATION)
            {
                const auto notification = notificationFactory_.createNotification(packet);
                notification->accept(messageVisitor_);
            }
            else
            {
                if(logger_.isErrorEnable())
                {
                    const string message = string("-MAIN- ProcessManager :: Rceived wrong type of message");
                    logger_.writeLog(LogType::ERROR_LOG, message);
                }
            }
        }
        catch(exception &ex)
        {
            if(logger_.isErrorEnable())
            {
                const string message = string("-MAIN- ProcessManager :: ") + ex.what();
                logger_.writeLog(LogType::ERROR_LOG, message);
            }
        }

        this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void ProcessManager::stop()
{
    runConfigurationProcess_ = false;
}




