#include "DebugLog.h"

using namespace std;
using namespace utility;

DebugLog::DebugLog(bool writeToFile)
	: LogInterface(DEBUG_LOG, writeToFile)
{
    if(writeToFile_)
    {
        string fileName = getName() + "_" + TimeManager::getTimeAndDate() + ".txt";

        file_.open(fileName.c_str());
        if (file_.fail())
        {
            logic_error("DebugLogger: Log file was not created.");
        }
    }
}

DebugLog::~DebugLog()
{
}

void DebugLog::writeMessage(const string &time, const string &message)
{
    if(writeToFile_)
    {
        file_ << time << "\t" << getName() << ":\t" << message << endl;
    }
}

string DebugLog::getName()
{
    return string("Debug");
}
