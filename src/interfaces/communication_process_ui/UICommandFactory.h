#ifndef AHRS_UICOMMANDFACTORY_H
#define AHRS_UICOMMANDFACTORY_H

#include "UICommand.h"
#include "UICommandBuilder.h"

#include <memory>

namespace communication
{
    class UICommandFactory
    {
    public:
        UICommandFactory();
        ~UICommandFactory();

        std::unique_ptr<UICommand> createCommand(const std::vector<uint8_t> &commandInBytes);

    private:
        std::unique_ptr<UICommandBuilder> builder_;
    };
}

#endif