#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);


//////////////////////////////Solar voltage1////////////////

float correctionfactor1 = 0; 
int analogInput1 = A0; 
float vout1 = 0.0; 
float vin1 = 0.0; 
 
// two resistors 30K and 7.5k ohm
float R1_1 = 30000;  //   
float R2_1 = 7500; //  
float value1 = 0.0;
///////////////////////////////////////////////////////

////////////////////////battery voltage///////////////////

float correctionfactor2 = 0; 
int analogInput2 = A5; 
float vout2 = 0.0; 
float vin2 = 0.0; 
 
// two resistors 30K and 7.5k ohm
float R1_2 = 30000;  //   
float R2_2 = 7500; //  
int value2 = 0; 

//////////////////////// voltage///////////////////

float correctionfactor3 = 0; 
int analogInput3 = A2; 
float vout3 = 0.0; 
float vin3 = 0.0; 
 
// two resistors 30K and 7.5k ohm
float R1_3 = 30000;  //   
float R2_3 = 7500; //  
int value3 = 0; 
/////////////////////


int x,y,z;

int R;



int vin1_1,vin3_1;

int s;


void setup()
{

     /*******************************/
      Serial.begin(9600);
      lcd.begin (16,2);  
      /*******************************/
      lcd.setCursor(0,0);
      lcd.print("LUO Converter");
      lcd.setCursor(0,1);
      lcd.print("EV Battery Application");
      delay(3000);
      lcd.clear();
      /**********************************************/
        
    pinMode(A0,INPUT);  //Solar voltage
          
    pinMode(A5,INPUT);  //battery
         
    pinMode(A2,INPUT);  // voltage
        
                 
}

/*****************************************************************/
void loop() 
{


voltage1();

voltage3();
   delay(100);
voltage2();

    Serial.println("V");
    Serial.println(vin1); 
   delay(100);
 
      Serial.println("P");
   Serial.println(vin1_1); 
   delay(100);

        Serial.println("S");
   Serial.println(vin2); 
   delay(100);

       Serial.println("W");
   Serial.println(vin3); 
   delay(100);
         
}

void voltage1()
{

    value1 = analogRead(analogInput1); 
    vout1 = (value1 * 5) / 1023.0; // see text 
    vin1 = vout1 / (R2_1/(R1_1+R2_1));
 
    vin1 = vin1+1 - correctionfactor1; 
    
    lcd.setCursor(0,0);
    lcd.print("BV:");
    lcd.setCursor(3,0);
    lcd.print(vin1);
    

vin1_1=((vin1/12)*100);

delay(1000);

  lcd.setCursor(0,0);

    lcd.print(vin1_1);
  
    lcd.print("%    ");
     
}


void voltage2()
{

   value2 = analogRead(analogInput2); 
    vout2 = (value2 * 5) / 1023.0; // see text 
    vin2 = vout2 / (R2_2/(R1_2+R2_2));
 
    vin2 = vin2 - correctionfactor2;  

  
    
    lcd.setCursor(0,1);
 lcd.print("SV:");
 lcd.setCursor(3,1);
lcd.print(vin2);


}



void voltage3()
{

   value3 = analogRead(analogInput3); 
    vout3 = (value3 * 5) / 1023.0; // see text 
    vin3 = vout3 / (R2_3/(R1_3+R2_3));
 
    vin3 = vin3 - correctionfactor3;  

  
    
    lcd.setCursor(8,1);
 lcd.print("EBV:");
 lcd.setCursor(12,1);
lcd.print(vin3);

delay(1000);
    lcd.setCursor(8,1);
 lcd.print("    ");
vin3_1=((vin3/12)*100);

  lcd.setCursor(12,1);
 

    lcd.print(vin3_1);

    lcd.print("%    ");

}
