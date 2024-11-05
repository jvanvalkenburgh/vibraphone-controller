#include <Button.h>
#include <SevSeg.h>
#include <Smoothed.h>

#define BUTTON_PIN_1 4  // ESP32 pin GPIO18, which connected to button
#define BUTTON_PIN_2 15
#define ON_OFF_BUTTON_PIN 16
#define LED_PIN_1 13      //13      // ESP32 pin GPIO21, which connected to led
#define LED_PIN_2 14      //12     // ESP32 pin GPIO21, which connected to led
#define LED_PIN_ONOFF 12  //17  // ESP32 pin GPIO21, which connected to led
#define TEST_PIN 32

Button button1(BUTTON_PIN_1, LED_PIN_1);  // create ezButton object that attach to pin 7;
Button button2(BUTTON_PIN_2, LED_PIN_2);
Button onOff(ON_OFF_BUTTON_PIN, LED_PIN_ONOFF);

SevSeg sevseg;

const int SENSOR_INPUT_PIN = 27;
Smoothed <int> mySensor;

void setup() {
  Serial.begin(9600);  // initialize serial

  button1.setDebounceTime(50);  // set debounce time to 50 milliseconds
  button2.setDebounceTime(50);  // set debounce time to 50 milliseconds
  onOff.setDebounceTime(50);    // set debounce time to 50 milliseconds

  pinMode(34, INPUT);

  pinMode(TEST_PIN, OUTPUT);
  //digitalWrite(TEST_PIN, HIGH);

  byte numDigits = 3;
  byte digitPins[] = { 26, 25, 33 };
  byte segmentPins[] = { 17, 5, 18, 19, 21, 3, 1 };
  bool resistorsOnSegments = false;      // 'false' means resistors are on digit pins
  byte hardwareConfig = COMMON_ANODE;  // See README.md for options
  bool updateWithDelays = true;         // Default 'false' is Recommended
  bool leadingZeros = false;             // Use 'true' if you'd like to keep the leading zeros
  bool disableDecPoint = true;           // Use 'true' if your decimal point doesn't exist or isn't connected. Then, you only need to specify 7 segmentPins[]

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(100);

  mySensor.begin(SMOOTHED_AVERAGE, 20);
}

int testNum;
long timeAtLastSwitch = millis();
long timeAllowed = 100; // Light must be stable for more than 0.1 seconds to be registered

void loop() {
  onOff.loop();

  //int readNum = map(analogRead(27), 0, 4095, 0, 100);

  if (onOff.isPressed()) {
    //Serial.println("The on off button is pressed");

    onOff.flipState();
    if (onOff.isOn()) {
      button1.reloadState();
      button2.reloadState();
    }
  }

  if (onOff.isOn()) {
    button1.loop();  // MUST call the loop() function first
    button2.loop();

    if (!buttonFunc(button1, button2)) 
    buttonFunc(button2, button1);

    mySensor.add(map(analogRead(SENSOR_INPUT_PIN), 0, 4095, 40, 140));

    sevseg.setNumber(mySensor.get());
    sevseg.refreshDisplay();
    //}
  } else {
    sevseg.blank();
    button1.setState(LOW);
    button2.setState(LOW);
  }

  //delay(1);
}

bool buttonFunc(Button& but1, Button& but2) {
  if (but1.isPressed()) {
    but1.flipState();

    if (but2.isOn() && but1.isOn()) {
      but2.flipState();
      return true;
    }
  }
  return false;
}