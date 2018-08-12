#ifndef AHRS_FEEDER_EXTERNAL_COM_STATES_H
#define AHRS_FEEDER_EXTERNAL_COM_STATES_H

enum class StateCode : uint8_t
{
    IDLE = 0x01,
    CALIBRATING = 0x02,
    ERROR = 0x03,
    CALIBRATED_FAILED = 0x04,
    MASTER_SENDING = 0x05,
    REDUNDANT_SENDING = 0x06,
    REGISTERED_USERS = 0x07,
    RESET = 0x08,
    SHUTDOWN = 0x09,
    CALIBRATED_SUCCESS= 0x10
};

#endif