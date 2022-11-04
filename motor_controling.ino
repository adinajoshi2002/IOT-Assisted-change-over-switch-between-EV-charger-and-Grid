
  //Motor A
const int inputPin1  = 15;    // Pin 15 of L293D IC
const int inputPin2  = 13;    // Pin 10 of L293D IC
void setup()
{ pinMode(inputPin1, OUTPUT);
    pinMode(inputPin2, OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, LOW);
    delay(1000);
    digitalWrite(inputPin1, LOW);
    digitalWrite(inputPin2, HIGH);
    delay(1000);
    digitalWrite(inputPin1, HIGH);
    digitalWrite(inputPin2, HIGH);
    
    
  // put your main code here, to run repeatedly:

}
