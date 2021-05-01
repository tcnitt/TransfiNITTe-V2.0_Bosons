#define pir 2
#define pin 13
#define high 12

void setup() {
  // put your setup code here, to run once:
  pinMode(pir , INPUT);
  pinMode(pin , OUTPUT);
  Serial.begin(9600);
  digitalWrite(high,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  int pir_a = digitalRead(pir);
  while (pir_a == 1) {
    Serial.println(pir_a);
    pir_a = digitalRead(pir);
    digitalWrite(pin , HIGH);
    delay(10);
  }
  Serial.println("OUT!!");
  digitalWrite(pin, LOW);
  delay(5);
  Serial.println(pir_a);
}
