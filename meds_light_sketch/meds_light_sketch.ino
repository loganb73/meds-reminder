int redLedPin = 12;
int redBtn = 2;
int greenLedPin = 8;
int greenBtn = 4;
unsigned long redTime = 0;
unsigned long greenTime = 32400000; //nine hours away from turn on time (on at 9pm this blink happens at 6am)
unsigned long onInterval = 86400000; //turn each light on every interval ms
unsigned long startTime = millis();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(redLedPin, OUTPUT);
  pinMode(redBtn, INPUT);
  digitalWrite(redLedPin, HIGH);

  pinMode(greenLedPin, OUTPUT);
  pinMode(greenBtn, INPUT);
  digitalWrite(greenLedPin, LOW);
}

void loop() {

  unsigned long currentTime = millis();

  //turn on red led every 24 hours starting from device plugin time, typically 9pm for me (onInterval ms)
  if(currentTime >= redTime + onInterval) {
    //turn on led
    digitalWrite(redLedPin, HIGH);

    //update time
    redTime = currentTime;
  }

  //turn on green led every 24 hours at 6am (onInterval ms)
  if(currentTime >= greenTime + onInterval) {
    //turn on led
    digitalWrite(greenLedPin, HIGH);

    //update time
    greenTime = currentTime;
  }

  //turn off red led when red btn pressed
  if(digitalRead(redBtn) == 0) {
    digitalWrite(redLedPin, LOW);
  }

  //turn off green led when green btn pressed
  if(digitalRead(greenBtn) == 0) {
    digitalWrite(greenLedPin, LOW);
  }

}

