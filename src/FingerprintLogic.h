#ifndef FINGERPRINTLOGIC_H
#define FINGERPRINTLOGIC_H


#if(ARDUINO >= 100)
    #include "Arduino.h"
    #include "DebugLogic.h"
#else
    #include "WProgram.h"
#endif


class FingerprintLogic {
    private:
        DebugLogic debugLogic;


    public:
        //constructor
        FingerprintLogic(int logLevel);

        //methods
        bool begin();

    
};

#endif