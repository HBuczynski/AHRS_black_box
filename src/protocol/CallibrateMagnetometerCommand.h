#ifndef AHRS_CALLIBRATEMAGNETOMETERDATA_H
#define AHRS_CALLIBRATEMAGNETOMETERDATA_H

#include "Command.h"

#include <string>

namespace communication
{
    class CallibrateMagnetometerCommand : public Command
    {
    public:
        CallibrateMagnetometerCommand();
        ~CallibrateMagnetometerCommand();

        virtual std::vector<uint8_t > getFrameBytes() override;
        virtual std::string getName() override;
        virtual void accept(CommandVisitor& visitor) override;

        void setNewPlaneName(const std::string &name);
        const std::string &getNewPlaneName() const;

    private:
        std::string newPlaneName_;
    };
}
#endif