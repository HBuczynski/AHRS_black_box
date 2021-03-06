#include "SendDatagramUDP.h"

#include <stdexcept>
#include <arpa/inet.h>

#include <utility/BytesConverter.h>
#include <checksum/Checksum.h>

using namespace std;
using namespace utility;
using namespace communication;

SendDatagramUDP::SendDatagramUDP(uint16_t port, std::string address)
    : port_(port),
      address_(address)

{
    createSocket();
}

void SendDatagramUDP::createSocket()
{
    sock_ = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock_ == -1)
    {
        throw invalid_argument("Cannot open socket.");

    }

    sockAddress_.sin_family = AF_INET;
    sockAddress_.sin_addr.s_addr = inet_addr(address_.c_str());
    sockAddress_.sin_port = htons(port_);
}

SendDatagramUDP::~SendDatagramUDP()
{
    close(sock_);
}

void SendDatagramUDP::sendData(vector<uint8_t>& message)
{
    auto parityBit = Checksum::parityBit(message);
    const auto crc32 = Checksum::crc32(message);

    message.push_back(parityBit);
    BytesConverter::appendUINT32toVectorOfUINT8(crc32, message);

    if ( sendto(sock_, reinterpret_cast<char*>(message.data()), sizeof(uint8_t)*message.size(),0, (struct sockaddr *) &sockAddress_, sizeof(sockAddress_)) <=0 )
    {
        throw logic_error("Cannot send packet.");
    }
}

