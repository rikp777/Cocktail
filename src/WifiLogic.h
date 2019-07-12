#ifndef WIFILOGIC_H
#define WIFILOGIC_H


#if(ARDUINO >= 100)
    #include "Arduino.h" 
    #include "DebugLogic.h"
#else
    #include "WProgram.h"
#endif




class WifiLogic {
    private:
        DebugLogic debugLogic;
        String _ssid;
        String _pass;
        int _status;
        int _attemps = 1;

    public:
        //constructor
        WifiLogic(int logLevel);

        //methods
        bool begin();


};


#endif