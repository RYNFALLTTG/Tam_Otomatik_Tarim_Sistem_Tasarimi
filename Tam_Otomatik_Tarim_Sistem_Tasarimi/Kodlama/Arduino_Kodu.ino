#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(32 , 16, 2);

int gaz=A0;
int toprak=A1;
int direnc=A2;

int role=2;
int motor=3;
int buzzer=4;
int l12=5;
int l13=6;
int tus=8;
int l21=9;
int l22=10;
int l23=11;

int tusdurum;
int gasdurum;
int toprakdurum;
int lambadurum;
/////////////////////////////////

void setup() {

Serial.begin(9600);

pinMode(2,OUTPUT);
pinMode(4,OUTPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(8,INPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(3,OUTPUT);

  
lcd.init();
lcd.backlight(); 
lcd.setCursor(0, 0); 
lcd.print("Sistem  basliyor");
delay(250);                   
lcd.clear();
     
}

////////////////////////////////////////
void loop() {
gasdurum=analogRead(A0);
gasdurum=map(gasdurum,0,706,0,99); 
tusdurum=digitalRead(8);
toprakdurum=analogRead(A1); 
toprakdurum=map(toprakdurum,0,539,0,99);
lambadurum=analogRead(A2);
lambadurum=map(lambadurum,5,641,0,99);  
  
  if(tusdurum==1){
 
 /////////////////////////////////////// 

  if(analogRead(A2)<=30){
   
   lcd.setCursor(8, 0); 
   lcd.print("ISIK :");
   lcd.setCursor(14, 0); 
   lcd.print((99-lambadurum)); 
   
   //
   digitalWrite(2,HIGH);
   analogWrite(9,255);
   analogWrite(11,255);
  }
  if(analogRead(A2)>=31){
   digitalWrite(2,LOW);
   analogWrite(9,0);
   analogWrite(11,0);
   //                       
   lcd.setCursor(8, 0); 
   lcd.print("ISIK :");
   lcd.setCursor(14, 0); 
   lcd.print((99-lambadurum)); 
   } 
 //////////////////////////////////////// 
  
  if(toprakdurum<=18){
   digitalWrite(3,255);
   analogWrite(10,255);
   lcd.setCursor(0, 0); 
   lcd.print("NEM :");
   lcd.setCursor(5, 0); 
   lcd.print(toprakdurum);     
   //
   lcd.setCursor(14, 1); 
   lcd.print("1"); 
   
  }  
  if(toprakdurum>=18){
   digitalWrite(3,0);
   analogWrite(10,0);
   lcd.setCursor(0, 0); 
   lcd.print("NEM :");
   lcd.setCursor(5, 0); 
   lcd.print(toprakdurum);   
   //
   lcd.setCursor(14, 1); 
   lcd.print("0"); 
   

   }
    
  if(analogRead(A1)>=0){
   lcd.setCursor(0, 0); 
   lcd.print("NEM :");
   lcd.setCursor(5, 0); 
   lcd.print(toprakdurum); 
     
   lcd.setCursor(8, 1); 
   lcd.print("Pompa:");
    
    }
    
 //////////////////////////////////////// 

  if(gasdurum>= 61){
    tone(4,200,100);
    digitalWrite(6,255);
    digitalWrite(5,255);
    
    lcd.setCursor(0, 1); 
    lcd.print("Gaz :");
    lcd.setCursor(5, 1); 
    lcd.print(gasdurum);  
   }
  
   if(gasdurum<= 60){ 
    
    noTone(3);
    digitalWrite(6,0);
    digitalWrite(5,0);
     
    lcd.setCursor(0, 1);
    lcd.print("Gaz :");  
    lcd.setCursor(5, 1);
    lcd.print(gasdurum); 
     }
 /////////////////////////////////////// 
  
  }
  else{
    
  digitalWrite(2,0);
  analogWrite(9,0);
  analogWrite(11,0);
  digitalWrite(3,LOW);  
 } 
  Serial.println(toprakdurum);
 } 
