#define PIN_BUTTON 10
int solenoidPin = 9;                    //This is the output pin on the Arduino

void setup() 
{
  pinMode(solenoidPin, OUTPUT);          //Sets that pin as an output
  pinMode(PIN_BUTTON, INPUT_PULLUP);

}

void loop() 
{ 
  if (digitalRead(PIN_BUTTON) == LOW){
    digitalWrite(solenoidPin, HIGH);      //Switch Solenoid ON
    delay(1000);                          //Wait 1 Second
    digitalWrite(solenoidPin, LOW);       //Switch Solenoid OFF
    delay(1000);                        //Wait 1 Second  
  }
}
