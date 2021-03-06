#include "GUIWirelessComWrapperResponse.h"
#include "GUIResponseVisitor.h"

using namespace std;
using namespace communication;

GUIWirelessComWrapperResponse::GUIWirelessComWrapperResponse(config::UICommunicationMode mode, const vector<uint8_t> &data)
    : GUIResponse(10, GUIResponseType::WRAPPER),
      mode_(mode),
      data_(data)
{}

GUIWirelessComWrapperResponse::~GUIWirelessComWrapperResponse()
{}

vector<uint8_t> GUIWirelessComWrapperResponse::getFrameBytes()
{
    initializeDataSize();

    vector<uint8_t > frame = getHeader();
    frame.push_back(static_cast<uint8_t>(responseType_));
    frame.push_back(static_cast<uint8_t>(mode_));
    frame.insert(frame.end(), data_.begin(), data_.end());

    return frame;
}

string GUIWirelessComWrapperResponse::getName()
{
    return string("GUIWirelessComWrapperCmmand");
}

void GUIWirelessComWrapperResponse::accept(GUIResponseVisitor &visitor)
{
    visitor.visit(*this);
}

const vector<uint8_t> &GUIWirelessComWrapperResponse::getDataFrame() const
{
    return data_;
}

void GUIWirelessComWrapperResponse::setDataFrame(const vector<uint8_t> &data)
{
    data_ = data;
}

void GUIWirelessComWrapperResponse::initializeDataSize()
{
    uint16_t dataSize = sizeof(responseType_) + sizeof(mode_);
    dataSize += data_.size();

    setDataSize(dataSize);
}

config::UICommunicationMode GUIWirelessComWrapperResponse::getMode() const
{
    return mode_;
}

void GUIWirelessComWrapperResponse::setMode(const config::UICommunicationMode &mode)
{
    mode_ = mode;
}
