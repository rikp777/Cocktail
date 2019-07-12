#include "DisplayLogic.h"
#include <Adafruit_SSD1306.h>


Adafruit_SSD1306 display(128, 64, &Wire, -1);

DisplayLogic::DisplayLogic(int logLevel){
    debugLogic.SetLevel(logLevel);
}

bool DisplayLogic::begin(){
    debugLogic.Info("Display Logic Setup: ");

    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        return false;
    }

    display.display();
    delay(100);
    display.clearDisplay();

    display.setTextSize(2); // Draw 2X-scale text
    display.setTextColor(WHITE);
    display.setCursor(10, 0);
    display.println(F("Cocktail Machine"));
    display.display();      // Show initial text
    delay(100);

    // Scroll in various directions, pausing in-between:
    display.startscrollright(0x00, 0x0F);

    return true;
}

void DisplayLogic::show(String message, bool clear){
    if(clear){
        display.stopscroll();
        display.clearDisplay();  
    }

    display.setTextSize(3);
    display.setTextColor(WHITE);
    display.setCursor(0, 15);
    display.println(message);
    display.display();
}