#ifndef AHRS_RESPONSEVISITOR_H
#define AHRS_RESPONSEVISITOR_H

#include "AckResponse.h"
#include "DataResponse.h"
#include "CalibratingStatusResponse.h"

namespace communication
{
    class ResponseVisitor
    {
    public:
        ResponseVisitor() {};
        virtual ~ResponseVisitor() {};

        virtual void visit(AckResponse& data) = 0;
        virtual void visit(DataResponse& data) = 0;
        virtual void visit(CalibratingStatusResponse& data) = 0;
    };
}

#endif //AHRS_RESPONSEVISITOR_H
