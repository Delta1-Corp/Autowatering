#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей
int avalue=0;
int amount=0;
//bool light=true;
unsigned long lastTimeWork=0;
unsigned long lastWater=0;
void setup()
{
  pinMode(2, OUTPUT);
//  pinMode(3, INPUT);
  digitalWrite(2,HIGH);
  pinMode(4, INPUT);
  Serial.begin(9600);
  lcd.init();                     
  lcd.backlight();// Включаем подсветку дисплея
  lcd.setCursor(0, 0);
 
  lcd.print("mint"); 
 lcd.setCursor(6, 0);
  lcd.print("W-0");
 lcd.setCursor(0, 1);
  lcd.print("TL");
   lcd.setCursor(3, 1);
  
    lcd.print(millis()/86400000);
    lcd.print("d");
    lcd.setCursor(6, 1);
    lcd.print(millis()/3600000);
    lcd.print("h");
   lcd.setCursor(9, 1);
   lcd.print("AW");
     lcd.setCursor(12, 1);
    lcd.print(amount);
    
}

void ReadFromSens(){
 
    
    lastTimeWork=millis();
   
    avalue=digitalRead(4);
   
    
  }

void doWater(){
  if(avalue==1){
  if(millis()-lastWater> (unsigned long)25*60*1000 || millis()<60000  ){
    lastWater=millis();
    
      lcd.setCursor(6,0);
  lcd.print("W-!");
        digitalWrite(2,LOW);
        amount++;
        delay(5000);
        digitalWrite(2,HIGH); 
         lcd.setCursor(6, 0);
  lcd.print("W-0");
      }
    ReadFromSens();
    }
  }
void loop()
{  
  /////////////////////////////////////////////////////

  //////////////////////////////////LCD Scann////////////////////////////////////
//  if(digitalRead(3) && millis()%1000==0 ||millis()<60000  ){light=!light;lcd.setCursor(15,0);
//  lcd.print(light);
//  }

  ///////////////////////////////LCD////////////////////////////////////////
//  if(light ){
//    lcd.setCursor(12,0);
//  lcd.print("on ") ;
//    lcd.backlight();
//    }else{
//      lcd.setCursor(12,0);
//  lcd.print("off") ;
//      lcd.noBacklight();
//      }
//  
    /////////////////////////////////////Scanner //////////////////////////////////
    if(millis()- lastTimeWork >(unsigned long) 5*360*1000 || millis()<60000 ){ 
    
  ReadFromSens();
    }
 ////////////////////////////////////INFO OUT///////////////////////////////////////
 
  
  doWater();
   lcd.setCursor(0, 1);
   lcd.print("TL");
   lcd.setCursor(3, 1);
  
    lcd.print(millis()/86400000);
    lcd.print("d");
    lcd.setCursor(6, 1);
    lcd.print(millis()/3600000);
    lcd.print("h");
   lcd.setCursor(9, 1);
   lcd.print("AW");
     lcd.setCursor(12, 1);
    lcd.print(amount);
 
   
    /////////////////////////////////////////////////////////////////////////////////
    if(millis()%25*60*1000==0 ){ 
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 0);
 
  lcd.print("mint"); 
 lcd.setCursor(6, 0);
  lcd.print("W-0");
    }
    /////////////////////////////////////////////////////////////////////////////////
}
