#ifndef AHRS_CALIBRATINGSTATUSRESPONSE_H
#define AHRS_CALIBRATINGSTATUSRESPONSE_H

#include "Response.h"

namespace communication
{
    enum CalibrationStatus : uint8_t
    {
        PASSED = 0x01,
        FAILED = 0x02,
        START_CALIBARTION = 0x03,
        IS_NOT_CALIBRATING = 0x04,
        IN_THE_PROCESS = 0x05,
        IS_CALIBRATED = 0x06
    };

    struct CalibrationConfiguration
    {
        uint8_t progress;
        CalibrationStatus status;

        struct
        {
            float minX, maxX;
            float minY, maxY;
            float minZ, maxZ;
        } accelerometer;

        struct
        {
            float minX, maxX;
            float minY, maxY;
            float minZ, maxZ;
        } magnetometer;

        struct
        {
            uint16_t quadrant_1;
            uint16_t quadrant_2;
            uint16_t quadrant_3;
            uint16_t quadrant_4;
            uint16_t quadrant_5;
            uint16_t quadrant_6;
            uint16_t quadrant_7;
            uint16_t quadrant_8;
        } ellipsoid;
    };

    class CalibratingStatusResponse final : public Response
    {
    public:
        CalibratingStatusResponse(CalibrationConfiguration configuration, uint8_t mode);
        ~CalibratingStatusResponse();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(ResponseVisitor& visitor) override;

        CalibrationConfiguration getCalibrationConfiguration() const;
        void setCalibrationConfiguration(const CalibrationConfiguration &status);

        uint8_t getMode() const noexcept;
        void setMode(uint8_t mode) noexcept;

    private:
        virtual void initializeDataSize() override;

        uint8_t mode_;
        CalibrationConfiguration calibrationConfiguration_;
    };
}

#endif
