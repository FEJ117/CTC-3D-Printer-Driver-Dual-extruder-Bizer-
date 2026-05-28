#define LED_1 36
#define LED_2 37
#define LED_3 40
#define LED_DEBUG 13

#define X_DIR A0
#define X_STP A1
#define X_EN A2
#define X_POT A3

#define Y_DIR A4
#define Y_STP A5
#define Y_EN A6
#define Y_POT A7

#define Z_DIR A8
#define Z_STP A9
#define Z_EN A10
#define Z_POT A11

#define A_DIR 24
#define A_STP 25
#define A_EN 26
#define A_POT 27

#define B_DIR 28
#define B_STP 29
#define B_EN 39





void setup() {
  Serial.begin(9600);
  pinMode(LED_DEBUG, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);

  pinMode(B_DIR, OUTPUT);
  pinMode(B_STP, OUTPUT);
  pinMode(B_EN, OUTPUT);


}

void loop() {

  bool dir = true;
  
  digitalWrite(B_EN, LOW);
  digitalWrite(B_DIR, dir);
  digitalWrite(B_STP, LOW);

  
  while(true)
  {
    waitForSerial();
    steps(3200);
    dir = !dir;
    digitalWrite(B_DIR, dir);
    waitForSerial();
    steps(1600);
    dir = !dir;
    digitalWrite(B_DIR, dir);
    waitForSerial();
    steps(6400);
    dir = !dir;
    digitalWrite(B_DIR, dir);
    waitForSerial();
    steps(800);
    dir = !dir;
    digitalWrite(B_DIR, dir);
    waitForSerial();
    steps(800);
    dir = !dir;
    digitalWrite(B_DIR, dir);
    waitForSerial();
    dir = !dir;
    digitalWrite(B_DIR, dir);
  }

}

void waitForSerial()
{
  while(!Serial.available()){}
  while(Serial.available()){Serial.read();}
}

void steps(int n)
{
  for(int i = 0; i < n; i++)
  {
    digitalWrite(B_STP, HIGH);
    digitalWrite(LED_1, HIGH);
    delayMicroseconds(200);
    digitalWrite(B_STP, LOW);
    digitalWrite(LED_1, LOW);
    delayMicroseconds(200);
  }
}
