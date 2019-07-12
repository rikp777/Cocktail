#include "WifiLogic.h"
#include <wifi101.h>


WifiLogic::WifiLogic(int logLevel){
    debugLogic.SetLevel(logLevel);
    _ssid = "Rikkerd";
    _pass = "Rikp2018";
}

bool WifiLogic::begin(){
    
    debugLogic.Info("Wifi Logic Setup: ");

    if (WiFi.status() == WL_NO_SHIELD) {                                // check for the presence of the shield:
        debugLogic.Error("WiFi shield not present");
        return false;                                                 // don't continue:
    }
   
    while ( _status != WL_CONNECTED) {
        String message = "Attempting to connect to WPA SSID: " + _ssid;
        debugLogic.Warning(message); 


        message =  "Attempt: " + _attemps;
        debugLogic.Warning(message);                          
        
        _status = WiFi.begin(_ssid, _pass);                                // Connect to WPA/WPA2 network:
    
        delay(5000);                                                    // wait 5 seconds for connection:

        if(_attemps >= 5){
            message = "Can't connect to " + _ssid + "";
            debugLogic.Warning(message);
            return false;
        }
        _attemps = _attemps + 1;
    }
    debugLogic.Info("You're connected to the network");
    return true;
}