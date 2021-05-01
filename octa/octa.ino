#define bulb1 2
#define bulb2 3
#define bulb3 4
#define bulb4 5
int  led1 = 0;
int  led2 = 0;
int  led3 = 0;
int  led4 = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("HI arduino here");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void ser()
{
  while (!Serial.available());
  led1 = Serial.readStringUntil('\t').toInt();
  led2 = Serial.readStringUntil('\t').toInt();
  led3 = Serial.readStringUntil('\t').toInt();
  led4 = Serial.readStringUntil('\n').toInt();
}

void loop() {
  ser();
  digitalWrite(bulb1, led1);
  digitalWrite(bulb2, led2);
  digitalWrite(bulb3, led3);
  digitalWrite(bulb4, led4);
  delay(100);
}
