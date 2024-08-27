int count = 0;
int value;
int temp = 1;
int valueA = 1;
void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(2);
  if (value == valueA) {
    if (value == 1) { //rising edge ON --> 1 , falling edge OFF --> 0
      count = count + 1;
      Serial.println(count);
      digitalWrite(12, temp);
      temp=!temp;
    }
    valueA = !value;
    delay(100);
  }
}
