#ifndef INTERCLIENTTCP_H
#define INTERCLIENTTCP_H

#include <atomic>
#include <queue>
#include <thread>
#include <mutex>

#include <logger/Logger.h>
#include <packet/SendStreamTCP.h>

#include <interfaces/ethernet_feeder/EthFeederCommand.h>
#include <interfaces/ethernet_feeder/EthFeederResponseFactory.h>

#include "InterResponseVisitor.h"

namespace communication
{
    class InterClientTCP
    {
    public:
        InterClientTCP(uint16_t portIn, std::string addressIn);
        ~InterClientTCP();

        bool connectToServer();

        void stopCommandSending();
        void startCommandSending();

        void sendCommand(std::unique_ptr<EthFeederCommand> command);

    private:
        bool isCommandQueueEmpty();
        std::unique_ptr<EthFeederCommand> getFromCommandQueue();

        void executeCommands();
        void catchExceptions(std::string exception, bool isEndConnectionSent, uint8_t commandSendingCounter);

        uint16_t port_;
        std::string address_;

        std::unique_ptr<SendStreamTCP> socket_;

        std::atomic<bool> executeCommandsFlag_;
        std::thread executeCommandThread_;

        std::mutex commandQueueMutex_;
        std::queue<std::unique_ptr<EthFeederCommand>> commandQueue_;

        EthFeederResponseFactory responseFactory_;
        InterResponseVisitor responseHandler_;

        const uint8_t COMMAND_SENDING_REPETITION = 5;

        utility::Logger& logger_;
    };

}


#endif // INTERCLIENTTCP_H