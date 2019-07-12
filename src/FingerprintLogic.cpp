#include "FingerprintLogic.h"
#include <Adafruit_Fingerprint.h>


SoftwareSerial mySerial(19, 18);
Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

FingerprintLogic::FingerprintLogic(int logLevel){
    debugLogic.SetLevel(logLevel);
}

bool FingerprintLogic::begin(){
    debugLogic.Info("Fingerprint Logic Setup: ");

    finger.begin(57600);

    if (finger.verifyPassword()) {
        debugLogic.Info("Found fingerprint sensor!");
    } else {
        debugLogic.Error("Did not find fingerprint sensor");
        return false;
    }

    return true;
}