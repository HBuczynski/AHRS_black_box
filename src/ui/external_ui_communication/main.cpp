#include <iostream>
#include <memory>
#include <chrono>
#include <fstream>

#include "ProcessManager.h"

using namespace std;
using namespace chrono;
using namespace utility;
using namespace communication;

int main(int argc , char *argv[])
{
    Logger &logger = Logger::getInstance("UI_External");
    InitLogStructure struc;
    struc.debugLog = true;
    struc.errroLog = true;
    struc.informationLog = true;
    struc.warningLog = true;
    struc.writeLogsInSeparetFiles = true;
    struc.writeOnConsole = true;

    logger.initLogger(struc);

    if(logger.isInformationEnable())
    {
        const string message = "Main External Process: Inititialized process. Process id: " + to_string(getpid()) + ". Parent process id: " + to_string(getppid()) + ".";
        logger.writeLog(LogType::INFORMATION_LOG, message);
    }

    if(argc < 2)
    {
        string msg("Invalid argument number");
        logger.writeLog(LogType::ERROR_LOG, msg.c_str());

        return 0;
    }

    uint8_t mode = static_cast<uint8_t >(atoi(argv[1]));
    ProcessManager processManager(mode);

    if(processManager.initialize())
    {
        processManager.startCommunication();
    }
    else
    {
        if(logger.isErrorEnable())
        {
            const string message = string("main :: Initialization failed !!");
            logger.writeLog(LogType::ERROR_LOG, message);
        }
    }

    return 0;
}