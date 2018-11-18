#ifndef AHRS_PLANEORIENTATION_H
#define AHRS_PLANEORIENTATION_H

#include <logger/Logger.h>
#include <hal/include/LSM9DS1.h>

#include "MadgwickAHRS.h"

namespace telemetry
{
    class PlaneOrientation
    {
    public:
        PlaneOrientation();
        ~PlaneOrientation();

        void initDataAcquisition();

        void readData();

        float getPitch();
        float getRoll();
        float getYaw();

    private:

        Madgwick madgwick_;

        LSM9DS1 lsm9DS1Driver_;
        utility::Logger& logger_;
    };
}

#endif
