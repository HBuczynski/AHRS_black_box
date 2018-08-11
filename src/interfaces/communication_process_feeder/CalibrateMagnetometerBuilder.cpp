#include "CalibrateMagnetometerBuilder.h"
#include "CalibrateMagnetometerCommand.h"

#include <utility/BytesConverter.h>

using namespace std;
using namespace utility;
using namespace communication;

CalibrateMagnetometerBuilder::CalibrateMagnetometerBuilder()
{}

CalibrateMagnetometerBuilder::~CalibrateMagnetometerBuilder()
{}

unique_ptr<FeederCommand> CalibrateMagnetometerBuilder::create(const vector<uint8_t> &commandInBytes)
{
    uint8_t currentPosition = INIT_DATA_POSITION_IN_FRAME;
    string planeName = BytesConverter::fromVectorOfUINT8toString(commandInBytes, currentPosition);

    auto command = make_unique<CalibrateMagnetometerCommand>(planeName);

    return move(command);
}