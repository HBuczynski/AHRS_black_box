#ifndef AHRS_BLACK_BOX_WAIC_CLIENT_H
#define AHRS_BLACK_BOX_WAIC_CLIENT_H

#include <atomic>
#include <queue>
#include <thread>
#include <mutex>

#include <logger/Logger.h>
#include <packet/SendStreamTCP.h>
#include <interfaces/wireless_commands/Command.h>
#include <interfaces/wireless_responses/ResponseFactory.h>

#include <time_manager/TimerInterrupt.h>
#include "ResponseHandlerVisitor.h"

namespace communication
{
    class ClientTCP final : public utility::TimerInterruptNotification
    {
    public:
        ClientTCP(uint16_t portIn, std::string addressIn);
        ~ClientTCP();

        bool connectToServer();

        void stopCommandSending();
        void startCommandSending();

        void sendCommand(std::unique_ptr<Command> command);

    private:
        bool isCommandQueueEmpty();
        std::unique_ptr<Command> getFromCommandQueue();

        void executeCommands();
        void catchExceptions(std::string exception, bool isEndConnectionSent, uint8_t commandSendingCounter);

        void interruptNotification(timer_t timerID);

        uint16_t port_;
        std::string address_;

        std::unique_ptr<SendStreamTCP> socket_;

        std::atomic<bool> executeCommandsFlag_;
        std::thread executeCommandThread_;

        std::mutex commandQueueMutex_;
        std::queue<std::unique_ptr<Command>> commandQueue_;

        ResponseHandlerVisitor responseHandler_;
        ResponseFactory responseFactory_;

        utility::TimerInterrupt keepAliveTimer_;
        const uint8_t COMMAND_SENDING_REPETITION = 3;
        const uint16_t KEEP_ALIVE_INTERVAL_MS = 5000;

        utility::Logger& logger_;
    };

}
#endif
