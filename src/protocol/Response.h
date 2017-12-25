#ifndef AHRS_BLACK_BOX_WAICRESPONSE_H
#define AHRS_BLACK_BOX_WAICRESPONSE_H

#include "Frame.h"

namespace communication
{
    enum ResponseType : uint8_t
    {
        DATA = 10,
        ACK = 20
    };

    class Response : public Frame
    {
    public:
        Response(uint8_t dataSizeIn, ResponseType commandTypeIn);
        virtual ~Response();

        virtual std::vector<uint8_t > getFrameBytes() = 0;
        virtual std::string getName() = 0;

        const ResponseType& getResponseType() const;

    protected:
        virtual void initializeDataSize() = 0;

        ResponseType responseType_;

    };
}

#endif
