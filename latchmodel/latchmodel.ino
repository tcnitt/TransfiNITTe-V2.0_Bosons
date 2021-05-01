#define powrpin 5
#define l1pin 6
#define l2pin 7
#define outpin 8
#define statpin 9
//#define outputac 10


int powr, l1, l2, out, stat;


void setup() {

  pinMode(powrpin, INPUT_PULLUP);
  pinMode(l1pin, INPUT);
  pinMode(l2pin, INPUT);
  pinMode(outpin, INPUT);
  pinMode(statpin, OUTPUT);
  Serial.begin(9600);
  stat = 1;
}

void loop() {
  digitalWrite(statpin, stat);
  powr = (digitalRead(powrpin));
  //Serial.println(powr);
  l1 = digitalRead(l1pin);
  l2 = digitalRead(l2pin);
  out = digitalRead(outpin);
  //
  //Serial.println(powr);
  if (out == 0) {
    Serial.println(out);
    if ((l1 == 0 || l2 == 0)  && powr == 0) {
      stat = 1;
    }
    else {
      stat = 0;
    }
  }

  else {
    if (powr == 0) {
      stat = 1;
    }
    else
      stat = 0;

  }

  /* if (powr == 0)
    {
     stat = 0;

    }
    else {
     if (
    }
    if (l1 == 1 || l2 == 1)
    {
     stat = 1;

    }

    if (powr == 1 && !(l1 == 1 || l2 == 1) && out == 1)
    {
     stat = 0;

    }

    if (powr == 1 && !(l1 == 1 || l2 == 1) && out == 0)
    {
     stat = 1;

    }
  */


}
