float max = 0;
float min = 0;

void setup() {
  // initialize the serial communication:
  Serial.begin(9600);
  pinMode(10, INPUT); // Setup for leads off detection LO +
  pinMode(11, INPUT); // Setup for leads off detection LO -

}

void loop() {
  
  if((digitalRead(10) == 1)||(digitalRead(11) == 1)){
    Serial.println('!');
  }
  else{
    // send the value of analog input 0:
    float val = analogRead(A0)* (10.0 / 1023.0)-3.25;
    if(val > max) {max = val;}
    if(val < min) {min = val;}
    Serial.print(-5); // To freeze the lower limit
    Serial.print(" ");
    Serial.print(5); // To freeze the upper limit
    Serial.print(" ");
    Serial.print(val);
    /*Serial.print(" ");
    Serial.print(max);
    Serial.print(" ");
    Serial.print(min);*/
    Serial.println();
  }
  //Wait for a bit to keep serial data from saturating
  delay(1);
}
