

int sensorPin = A0;    // select the input pin for the potentiometer
     // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
int peakValue = 0;
int threshold = 50;   //set your own value based on your sensors
int noise = 5; 
int sendvar = 0;
int sendvar_ex = 0;


void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  
  if (sensorValue > peakValue) {
    peakValue = sensorValue;
  }
  if (sensorValue <= threshold - noise ) {
    
    if (peakValue > threshold + noise) {
      // you have a peak value:
      //Serial.println(peakValue);
      // reset the peak value:
      peakValue = 0;
      return;
    }
  }

  
  sendvar = map(analogRead(sensorPin),0,1023,0,360);
  
//Serial.println(sendvar);

    

    int diff = abs((sendvar - sendvar_ex));

    if (diff>=5 && diff <=3){
    //if (diff>=3){

      Serial.println(sendvar_ex);
      
      
      }else {

        sendvar_ex = sendvar;
        Serial.println(sendvar);
        }
  
  delay(50);
  
  
}
