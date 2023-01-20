float max = 0;
float min = 0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -
  pinMode(12, INPUT); // Setup for leads off detection LO +
  pinMode(13, INPUT); // Setup for leads off detection LO -

}

void loop() {
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)||(digitalRead(12) == 1)||(digitalRead(13) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
    float Aval = analogRead(A0)* (10.0 / 1023.0)-3.25;
    float Bval = analogRead(A1)* (10.0 / 1023.0)-3.25
    Serial.print(-10); // To freeze the lower limit
    Serial.print(" ");
    Serial.print(10); // To freeze the upper limit
    Serial.print(" ");
    Serial.print(Aval);
    /*Serial.print(" ");
    Serial.print(max);
    Serial.print(" ");
    Serial.print(min);*/
    Serial.println();
  }
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
