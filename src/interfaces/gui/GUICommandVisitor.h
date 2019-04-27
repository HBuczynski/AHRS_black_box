#ifndef AHRS_GGUICommandVISITOR_H
#define AHRS_GGUICommandVISITOR_H

#include "GUIWindowCommand.h"
#include "GUIInformationWindowCommand.h"
#include "GUIPlanesSetCommand.h"
#include "GUICallibrationCommand.h"

namespace communication
{
    class GUICommandVisitor
    {
    public:
        GUICommandVisitor(){};
        virtual ~GUICommandVisitor(){};

        virtual void visit(GUIWindowCommand& command) = 0;
        virtual void visit(GUIInformationWindowCommand& command) = 0;
        virtual void visit(GUIPlanesSetCommand& command) = 0;
        virtual void visit(GUICallibrationCommand& command) = 0;
    };
}

#endif
