#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>


//own library
#include "DebugLogic.h"
DebugLogic debugLogic;

#include "WifiLogic.h"
WifiLogic wifiLogic(debugLogic.LogLevelError);

#include "FingerprintLogic.h"
FingerprintLogic fingerprintLogic(debugLogic.LogLevelError);

#include "DisplayLogic.h"
DisplayLogic displayLogic(debugLogic.LogLevelError);


bool success = false;


String Pretext = "";
int displaybreak = 0;
unsigned long displayTime = 0;
enum DisplayMode
{
	Drinks,
	MakingDrink,
	DrinkDone,
	ScanFinger,
	RemoveFinger
};
DisplayMode displayMode = Drinks;
void DisplayShow(String text, int timer = 0) {
  String myString = String(displayTime);
  debugLogic.Info(myString);
	if (Pretext != text && ((millis() - displayTime) > displaybreak)) {
		displaybreak = timer;
		displayTime = millis();
		Pretext = text;
		debugLogic.Info(text);
		int size = 1;
		if (text.length() > 10)size = 1;
		else if (text.length() > 7)size = 2;
		else if (text.length() > 5)size = 3;
		else if (text.length() > 4)size = 4;
		else {
			size = 5;
		}
    debugLogic.Info(text);
		DisplayShow(text);
		//display.startscrollright(0x00, 0x0F);
	}
}
void Display() {
	switch (displayMode)
	{
	case Drinks:
		DisplayShow("Drinks");
		break;
	case MakingDrink:
		DisplayShow("Please waite");
		break;
	case DrinkDone:
		DisplayShow("Get your drink");
		break;
	case ScanFinger:
		DisplayShow("Scan your finger");
		break;
	case RemoveFinger:
		DisplayShow("Remove your finger");
		break;
	default:
		break;
	}
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
      ; 
  }

  delay(100);
  success = wifiLogic.begin();

  delay(100);
  success = fingerprintLogic.begin();

  delay(100);
  success = displayLogic.begin();

  delay(100);
  //displayLogic.show("test", true);
}


void loop() {
  Display();
}

