#include <iostream>
#include <memory>
#include <chrono>
#include <fstream>

#include "ProcessManager.cpp"

using namespace chrono;
using namespace utility;
using namespace communication;

void initializeLogger(Logger &logger);
void initializeProcessManager(std::shared_ptr<ProcessManager> processManager, char *argv[]);

int main(int argc , char *argv[])
{
    Logger &logger = Logger::getInstance();
    initializeLogger(logger);

    if(argc < 4)
    {
        string msg("Invalid argument number");
        logger.writeLog(LogType::ERROR_LOG, msg.c_str());

        throw std::invalid_argument(msg.c_str());
    }

    string mode = string(argv[3]);
    string msg = string("Child process initialized.") + mode;
    logger.writeLog(LogType::INFORMATION_LOG, msg.c_str());

    return 0;
}

void initializeLogger(Logger &logger)
{
    InitLogStructure struc;
    struc.debugLog = true;
    struc.errroLog = true;
    struc.informationLog = true;
    struc.warningLog = true;
    struc.writeLogsInSeparetFiles = true;
    struc.writeOnConsole = true;

    logger.initLogger(struc);
}

void initializeProcessManager(std::shared_ptr<ProcessManager> processManager, char *argv[])
{
    std::string managementQueueName = argv[1];
    std::string sharedMemoryName = argv[2];

    cout << managementQueueName << endl;

    CommunicationProcessMode status;
    if(string(argv[3]) == "MAIN")
    {
        status = CommunicationProcessMode ::MAIN;

        cout << "MAIN" << endl;
    }
    else if(string(argv[3]) == "REDUNDANT")
    {
        status = CommunicationProcessMode ::REDUNDANT;
    }

    processManager = make_shared<ProcessManager>(managementQueueName, sharedMemoryName, status);
}