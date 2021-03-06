#ifndef AHRS_GUICOMMUNICATIONVISITOR_H
#define AHRS_GUICOMMUNICATIONVISITOR_H

#include <interfaces/gui/GUIResponseVisitor.h>
#include <logger/Logger.h>

namespace main_process
{
    class UIApplicationManager;

    class GUIInterprocessVisitor final : public communication::GUIResponseVisitor
    {
    public:
        GUIInterprocessVisitor(UIApplicationManager *uiApplicationManager);
        ~GUIInterprocessVisitor();

        void visit(communication::GUIPlaneResponse& data);
        void visit(communication::GUIWindowResponse& data);
        void visit(communication::GUIWirelessComWrapperResponse& data);
        void visit(communication::GUIStartAcqResponse& data);
        void visit(communication::GUIStopAcqResponse& data);
        void visit(communication::GUIRestartResponse& data);
        void visit(communication::GUIShutdownResponse& data);

    private:
        UIApplicationManager* uiApplicationManager_;
        utility::Logger& logger_;
    };
}

#endif
