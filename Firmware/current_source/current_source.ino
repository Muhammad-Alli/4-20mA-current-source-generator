#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

//Declaration of variables
const int CoarseUpPin = 7;       
const int CoarseDownPin = 8 ;   
const int FineUpPin = 13;       
const int FineDownPin = 10;  
const int PwmPin = 6;
float SetVoltage = 1;     
float SetCurrent;         
int count = 1;

void setup() {

// initialize inputs and outputs:
pinMode(CoarseUpPin, INPUT);
pinMode(CoarseDownPin, INPUT);
pinMode(FineUpPin, INPUT);
pinMode(FineDownPin, INPUT);
pinMode(PwmPin, OUTPUT);

lcd.begin(16, 2);                                                   // Initialize lcd communication:
 
lcd.setCursor(0, 0);
lcd.print("SETPOINT:"); 
lcd.setCursor(14, 0);                                               // Start the letters "mA" at coloumn 14 of row 0 to allow adequate space for values 
lcd.print("mA"); 

lcd.setCursor(0, 1);
lcd.print("MEASURED:"); 
lcd.setCursor(14, 1);                                               // Start letters "mA" directly below mA of setpoint
lcd.print("mA"); 

}
 
void loop() {
  
 //Increasing coarse adjustment  
  if(digitalRead(CoarseUpPin)== HIGH){
    
    count++; //increment count by 1
   
    if(count==1) 
      SetVoltage = 1; 
    else if(count==2) 
      SetVoltage = 2; 
    else if(count==3) 
      SetVoltage = 3; 
    else if(count==4) 
      SetVoltage = 4; 
    else if(count==5) 
      SetVoltage = 5; 
    else if(count == 6){ 
      count = 5; 
      SetVoltage = 5;
    }
  }
  
  //Decreasing coarse adjustment
  if(digitalRead(CoarseDownPin)== HIGH){
   
    count--; //decrement count by 1
   
    if(count==1) 
      SetVoltage = 1; 
    else if(count==2) 
      SetVoltage = 2; 
    else if(count==3) 
      SetVoltage = 3; 
    else if(count==4) 
      SetVoltage = 4; 
    else if(count==5) 
      SetVoltage = 5; 
    else if(count == 0){ 
      count = 1; 
      SetVoltage = 1;
    }
  }
  
  //Increasing Fine adjustment
  if(digitalRead(FineUpPin)== HIGH){
  
    SetVoltage = SetVoltage + 0.025;                                // A change of 0.025 V results in a change of 0.1 mA
      
    if(SetVoltage > 5) 
      SetVoltage = 5;
  }
  
  //Decreasing Fine adjustment
  if(digitalRead(FineDownPin)== HIGH){
  
    SetVoltage = SetVoltage - 0.025;                                                                    
    if(SetVoltage < 1) 
    SetVoltage = 1;
  }
  
  SetCurrent = 20 - 4*((5 - SetVoltage));
  
  analogWrite(PwmPin,51*SetVoltage);                                // 51 because total duty cycle is 255. For setpoint values of 1-5V, pwm value is 51-255
  
  float RawADC = analogRead(A1);                                    // Read the FeedBack signal in raw data format
  float FeedBackVoltage = 5 *RawADC/1023 ;                          // Convert it to a voltage value
  float FeedBackCurrent = 20 - (4*(5 - FeedBackVoltage));           // Similar formula as Setpoint to calculate the measured current value
  
  lcd.setCursor(10, 0);
  lcd.print("    ");                                                // To clear the space after current reaches double digits to omit the zero that appears next to the "mA" when the current returns to single digits 
  lcd.setCursor(10, 0);
  lcd.print(SetCurrent,1); 
  
  lcd.setCursor(10, 1);
  lcd.print("    "); 
  lcd.setCursor(10, 1);
  lcd.print(FeedBackCurrent,1); 
  
  delay(200);
}

