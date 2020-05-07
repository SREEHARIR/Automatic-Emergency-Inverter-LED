const int Res = A0; // pin A0 to measure resistance
const int Supply = 12; // pin 12 to rectified DC
bool ON_Check = HIGH;
int Imped = 0; // 0 = open(Switch is open, Mains may or may not be present) | 1023 = short (Switch is closed, Mains is not present)
const int Imped_Thresh = 255;
int Sw_pin = 13; // pin 13 to battery LED
bool Sw = LOW;

void setup() {
  pinMode(Res,INPUT);
  pinMode(Supply,INPUT);
  pinMode(Sw_pin,OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int ON_Check = digitalRead(Supply);
  if(ON_Check == HIGH)
  {
    //do nothing
    Serial.println("Supply is there");
    
    Imped = analogRead(Res);
    Serial.println(Imped);
  }
  else
  {
    Serial.println("No Supply");
    //measure impedance
    Imped = analogRead(Res);
    Serial.println(Imped);
    //turn battery ON using condition
    if(Imped > Imped_Thresh)
    {
      Sw = LOW; // turn Battery OFF
    }
    else 
    {
      Sw = HIGH; // turn Battery ON
    }
    
    digitalWrite(Sw_pin,Sw);

  }


}
