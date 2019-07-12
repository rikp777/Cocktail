#include "DebugLogic.h"


DebugLogic::DebugLogic(){
    
}


void DebugLogic::SetLevel(byte logLevel){
    _logLevel = logLevel;
}

void DebugLogic::Error(String message){
    if(_logLevel <= LogLevelError){
        String info = "[Error] : ";
        String msg = info + message;
        Serial.println(msg);
    }
}
void DebugLogic::Warning(String message){
    if(_logLevel <= LogLevelWarning){
        String info = "[Warning] : ";
        String msg = info + message;
        Serial.println(msg);
    }
}
void DebugLogic::Info(String message){
    if(_logLevel <= LogLevelInfo){
        String info = "[Info] : ";
        String msg = info + message;
        Serial.println(msg);
    }
}