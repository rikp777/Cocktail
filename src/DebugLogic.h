#ifndef DEBUGLOGIC_H
#define DEBUGLOGIC_H


#if(ARDUINO >= 100)
    #include "Arduino.h"
#else
    #include "WProgram.h"
#endif


class DebugLogic {
    private:
        byte _logLevel = LogLevelInfo;

    public:
        const byte LogLevelError = 0;
        const byte LogLevelWarning = 1;
        const byte LogLevelInfo = 2;
        const byte LogLevelNone = 3;

    public:
        //constructor
        DebugLogic();

        //methods
        void SetLevel(byte logLevel);

        void Error(String message);
        void Warning(String message);
        void Info(String message);

};


#endif