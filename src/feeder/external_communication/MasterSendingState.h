#ifndef AHRS_MASTERSENDINGSTATE_H
#define AHRS_MASTERSENDINGSTATE_H

#include "AbstractState.h"

namespace communication
{
    class MasterSendingState : public AbstractState
    {
    public:
        MasterSendingState();
        ~MasterSendingState();

        void acceptedUsers(ClientUDPManager &clientUDPManager);
        void startCalibration(ClientUDPManager &clientUDPManager);
        void startDataSending(ClientUDPManager &clientUDPManager);
        void restartProcess(ClientUDPManager &clientUDPManager);
        void shutdownProcess(ClientUDPManager &clientUDPManager);

    };
}

#endif