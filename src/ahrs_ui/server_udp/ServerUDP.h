#ifndef WAIC_SERVER_H
#define WAIC_SERVER_H

#include <ahrs_ui/server_udp/DataHandlerVisitor.h>
#include <protocol/Command.h>
#include <logger/Logger.h>
#include <packet/ListenDatagramUDP.h>
#include <protocol/MeasuringDataFactory.h>

#include <map>
#include <list>
#include <atomic>
#include <memory>
#include <utility>
#include <thread>

namespace communication
{
    class ServerUDP
    {
    public:
        ServerUDP(uint16_t port);
        ~ServerUDP();

        void startListening();
        void stopListening();

    private:
        void listen();

        uint16_t port_;

        std::thread listenThread_;
        std::atomic<bool> runListenThread_;

        std::unique_ptr<ListenDatagramUDP> socket_;
        MeasuringDataFactory dataFactory_;
        DataHandlerVisitor dataVisitor_;

        utility::Logger& logger_;
    };
}
#endif