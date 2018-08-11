#ifndef AHRS_CALIBRATEMAGNETOMETERBUILDER_H
#define AHRS_CALIBRATEMAGNETOMETERBUILDER_H

#include "FeederCommandBuilder.h"

namespace communication
{
    class CalibrateMagnetometerBuilder final : public FeederCommandBuilder
    {
    public:
        CalibrateMagnetometerBuilder();
        ~CalibrateMagnetometerBuilder();

        std::unique_ptr<FeederCommand> create(const std::vector<uint8_t> &commandInBytes) override;

    private:
        const uint16_t INIT_DATA_POSITION_IN_FRAME = 7;
    };
}
#endif