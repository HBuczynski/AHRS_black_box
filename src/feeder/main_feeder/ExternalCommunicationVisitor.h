#ifndef AHRS_EXTERNALCOMMUNICATIONVISITOR_H
#define AHRS_EXTERNALCOMMUNICATIONVISITOR_H

#include <interfaces/communication_process_feeder/FeederCommandVisitor.h>
#include <interfaces/communication_process_feeder/FeederNotificationVisitor.h>
#include <logger/Logger.h>

namespace main_process
{
    class ExternalCommunicationVisitor final : virtual public communication::FeederCommandVisitor, virtual public communication::FeederNotificationVisitor
    {
    public:
        ExternalCommunicationVisitor();
        ~ExternalCommunicationVisitor();

        virtual void visit(const communication::CalibrateMgnDemandCommand& command) override ;
        virtual void visit(const communication::CalibrationStatusNotification& command) override;

    private:
        utility::Logger& logger_;
    };
}

#endif