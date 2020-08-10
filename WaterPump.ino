int relayPin= 8;
int trigPin = 9;
int echoPin = 10;
 #include <LiquidCrystal.h> //http://www.arduino.cc/en/Tutorial/LiquidCrystal
const int RS=A5, E=A4, D4=A3, D5=A2, D6=A1, D7=A0;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  lcd.begin(16, 2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(relayPin,OUTPUT);
  pinMode(11, OUTPUT);
}


void loop() {
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);



  if((distance<=5)) 
  {
   tone(7,500,100);
    lcd.setCursor(1, 0);
      lcd.print("high");
       lcd.print(millis() / 1000);
       digitalWrite(relayPin,HIGH);
}
   
   
   else if((distance>=10))
    
  {
   tone(7,500,100);
        lcd.setCursor(1,0 );
      lcd.print("low");
       lcd.print(millis() / 1000);
        digitalWrite(relayPin,LOW);
       
   
   }
      else 
 {
   noTone(7);
    delay(5);
  digitalWrite(relayPin,HIGH);
}

}
