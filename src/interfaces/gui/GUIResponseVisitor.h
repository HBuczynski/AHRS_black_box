#ifndef AHRS_GUIRESPONSEVISITOR_H
#define AHRS_GUIRESPONSEVISITOR_H

#include "GUIPlaneResponse.h"

namespace communication
{
    class GUIResponseVisitor
    {
    public:
        GUIResponseVisitor() {};
        virtual ~GUIResponseVisitor() {};

        virtual void visit(GUIPlaneResponse& data) = 0;
    };
}

#endif