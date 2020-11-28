int irPin = 4;
char sign;
int flag;
int pump = 10;
void setup() 
{
      Serial.begin(9600);
      pinMode(pump, OUTPUT);
      pinMode(irPin, INPUT);
      digitalWrite(irPin, LOW);
      
}

void loop() 
{
      while(Serial.available())
      {
            sign = Serial.read();
            if(sign == '1')
            {
                  delay(1000);
                  flag = digitalRead(irPin);
                  if(flag == 0)
                  {
                    Serial.write("done");
                    digitalWrite(pump, HIGH);
                    digitalWrite(13,HIGH);
                    delay(250);
                    digitalWrite(pump, LOW);
                    
                  }
            }  
            Serial.flush();  //New added
             
      }
}
