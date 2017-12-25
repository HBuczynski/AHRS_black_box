#include "AckResponse.h"

using namespace std;
using namespace communication;

AckResponse::AckResponse(AckType type)
    : type_(type),
      Response(10, ResponseType::ACK)
{}

AckResponse::~AckResponse()
{}

vector<uint8_t> AckResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));
    frame.push_back(static_cast<uint8_t>(type_));

    return frame;
}

string AckResponse::getName()
{
    return string("AckResponse");
}

AckType AckResponse::getAckType() const
{
    return type_;
}

void AckResponse::setAckType(AckType type)
{
    type_ = type;
}

void AckResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_);
    dataSize += sizeof(type_);

    setDataSize(dataSize);
}
