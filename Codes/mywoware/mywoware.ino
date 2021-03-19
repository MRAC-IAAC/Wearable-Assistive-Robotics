#include <Servo.h>    // Using the Servo library
#include <Wire.h>    // Using the I2C library
Servo elbowJoint;     // Naming our servo ‘elbowJoint’
int EMGsig;           // Store the EMG signal value
int servoPosition;    // The position (angle) value for the servo
int threshold = 400;  // Move the servo when EMG signal is above this threshold. Remember it ranges 0–1023.
int data1, data2, data3, curr1, curr2, curr3;
String datalabel1 = "Servo Position";
String datalabel2 = "EMG Reading";
bool label = true;
byte response[2];
volatile short LDR_value; // Global Declaration
int solenoid = 3;

void setup() {
 //Wire.begin(0x8);
 //Wire.onRequest(sendData);
 Serial.begin(115200); // Starting the communication with the computer
 pinMode(EMGsig,INPUT);
 pinMode(solenoid, OUTPUT);
 elbowJoint.attach(10); // Tell the servo it is plugged into pin 9
}
void loop() {
 EMGsig = analogRead(A0); // Read the analog values of the rectified+integrated EMG signal (0–1023)
//if (EMGsig < threshold){     // If EMG signal is below the threshold
//    servoPosition = 20;       // Servo will remain at 20 degrees.
//  } else{            // If the EMG signal is above the threshold,
//   servoPosition=map(EMGsig,threshold,600,20,160); 
  // The servo angle will be mapped with the EMG signal, 
  // changing the range of 300(our threshold)-1023 into the range of 20-160 degrees.
  // 20 and 160 can be switched depending on which direction of rotation you want.

  if (EMGsig < threshold){     // If EMG signal is below the threshold
    digitalWrite(solenoid, LOW);       // Servo will remain at 20 degrees.
    } else{            // If the EMG signal is above the threshold,
      digitalWrite(solenoid, HIGH);
}
 //elbowJoint.write(servoPosition); 
  // Move the servo to the ‘servoPosition’ degree
 //Serial.print(servoPosition);
 //Serial.print('\n');
 //Serial.print(',');
 //Serial.print(" degrees, with EMG: ");
 Serial.println(EMGsig); 
  // Display the servo and EMG values.
 delay(100); 
  // 1 second (1000ms) delay to not cause it to move as frantically. But this can be adjusted as you like.
}

void sendData(){
  LDR_value=analogRead(EMGsig);
  // Arduino returns 10bit data but we need to convert it to 8bit 
  LDR_value=map(LDR_value,0,1023,0,255);
  response[0]=(byte)LDR_value;
  Wire.write(response,2); // return data to PI
}
