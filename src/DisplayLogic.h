#ifndef DISPLAYLOGIC_H
#define DISPLAYLOGIC_H


#if(ARDUINO >= 100)
    #include "Arduino.h"
    #include "DebugLogic.h"
#else
    #include "WProgram.h"
#endif



class DisplayLogic {
    private:
        DebugLogic debugLogic;

    public:
        //constructor
        DisplayLogic(int logLevel);

        //methods
        bool begin();


        void show(String message, bool clear);

};


#endif