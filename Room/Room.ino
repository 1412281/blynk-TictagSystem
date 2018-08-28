/*************************************************************
   Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

   Blynk is a platform with iOS and Android apps to control
   Arduino, Raspberry Pi and the likes over the Internet.
   You can easily build graphic interfaces for all your
   projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

   Blynk library is licensed under MIT license
   This example code is in public domain.

*************************************************************

   This example shows how to fetch data using WebHook GET method

   App project setup:
    WebHook widget on V0, method: GET, url: /pin/
*************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT              Serial
#define TOKEN_HAS_SET_ADDRESS    0
#define TOKEN_ADDRESS            1
#define TOKEN_LENGTH             33

// Allow for receiving messages up to 512 bytes long
//#define BLYNK_MAX_READBYTES 512
#include <EEPROM.h>
#include <UIPEthernet.h>
#include <BlynkSimpleUIPEthernet.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).

//chân ST_CP (Chân 12) của 74HC595
int latchPin1 = 4;
int latchPin2 = 5;
int latchPin3 = 6;
//chân SH_CP (Chân 11) của 74HC595
int clockPin = 3;
//Chân DS (chân 14) của 74HC595
int dataPin = 2;
//Trạng thái của LED, hay chính là byte mà ta sẽ gửi qua shiftOut

void           (*resetFunc)(void) = 0; //declare reset function at address 0

byte           tokenHasSet = 0;

char TOKEN_DEFAULT[] = "0f1add3742174f88bc8f93f37486c3b9";
char buffer[50];
byte ledStatus1 = 0b00000000;
byte ledStatus2 = 0b00000000;
byte ledStatus3 = 0b00000000;

int relay;
int state1;
byte state2;
int state[25]={0,0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000,0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000,0b00000001,0b00000010,0b00000100,0b00001000,0b00010000,0b00100000,0b01000000,0b10000000};
//...............................................

BLYNK_WRITE(V0)
{
    Serial.println("WebHook data:");
    Serial.println(param.asStr());
}
BLYNK_WRITE(V1)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 1 ;
    Relay_Control(relay,state1);
}
BLYNK_WRITE(V2)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 2 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V3)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 3 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V4)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 4 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V5)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 5 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V6)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 6 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V7)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 7 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V8)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 8 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V9)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 9 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V10)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 10 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V11)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 11 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V12)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 12 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V13)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 13 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V14)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 14 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V15)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 15 ;
    Relay_Control(relay,state1);  
}BLYNK_WRITE(V16)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 16 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V17)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 17 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V18)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 18 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V19)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 19 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V20)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 20 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V21)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 21 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V22)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 22 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V23)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 23 ;
    Relay_Control(relay,state1);  
}
BLYNK_WRITE(V24)
{
//    Serial.println("WebHook data:");
//    Serial.println(param.asInt());
    int state1 = param.asInt();
    relay = 24 ;
    Relay_Control(relay,state1);  
}
//..............................
BLYNK_WRITE(V31)
{
    Serial.print("New token:");
    String temp = param.asStr();
    Serial.println(temp);

    Serial.println(temp.length());

    if (temp.length() == 32) {
        char newToken[TOKEN_LENGTH];
        temp.toCharArray(newToken, TOKEN_LENGTH);
        Serial.println(newToken);

        EEPROM.write(TOKEN_HAS_SET_ADDRESS, 1);

        for (byte i = 0; i < TOKEN_LENGTH; i++)
        {
            // auth[i] = newToken[i];
            EEPROM.write(TOKEN_ADDRESS + i, newToken[i]);
        }
        delay(5);
        Blynk.disconnect();
        delay(5);
        // Blynk.begin(auth, "smarthome.tictag.vn", 8080);
        resetFunc();
    }

}

void setup()
{
    // Debug console
    //Bạn BUỘC PHẢI pinMode các chân này là OUTPUT
    pinMode(latchPin1, OUTPUT);
    pinMode(latchPin2, OUTPUT);
    pinMode(latchPin3, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    
    Serial.begin(9600);

    digitalWrite(latchPin1, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ledStatus1);  
    digitalWrite(latchPin1, HIGH);//các đèn LED sẽ sáng với trạng thái vừa được cập nhật
    digitalWrite(latchPin2, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ledStatus2);  
    digitalWrite(latchPin2, HIGH);//các đèn LED sẽ sáng với trạng thái vừa được cập nhật
    digitalWrite(latchPin3, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, ledStatus3);  
    digitalWrite(latchPin3, HIGH);//các đèn LED sẽ sáng với trạng thái vừa được cập nhật

    tokenHasSet = EEPROM.read(TOKEN_HAS_SET_ADDRESS);
    Serial.print("====== token has set value: ");
    Serial.println(tokenHasSet);

    if (!tokenHasSet)
    {
        Serial.println("====== USE TOKEN_DEFAULT");
        Blynk.begin(TOKEN_DEFAULT, "smarthome.tictag.vn", 8080);
    }
    else
    {
        char auth[TOKEN_LENGTH];
        for (byte i = 0; i < TOKEN_LENGTH; i++)
        {
            auth[i] = EEPROM.read(TOKEN_ADDRESS + i);
            // Serial.print(auth[i]);
        }
        // auth[TOKEN_LENGTH] = '\n';
        Serial.print("Token: ");
        Serial.println(auth);
        Blynk.begin(auth, "smarthome.tictag.vn", 8080);
    }

//      Blynk.virtualWrite(V0, "http://192.168.100.3:3000/user/123/gate/1");

    //Blynk.begin(auth, IPAddress(192,168,1,100), 8080);
}
//...............................................
void Relay_Control (int relay,int state1)
{
  if(relay<=8)
  {
  state2 = bitRead(ledStatus1,relay - 1);
  Serial.print(state1);
  Serial.println(state2);
  if(state2 == state1)
  {
  Serial.print(relay);
  Serial.println(state1);
  }
  else
  {
  ledStatus1 ^= state[relay];
  digitalWrite(latchPin1, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, ledStatus1);  
  digitalWrite(latchPin1, HIGH);//các đèn LED sẽ sáng với trạng thái vừa được cập nhật
  Serial.print(relay);
  Serial.println(state1);
  printBinary(ledStatus1);
  Serial.println("TH1");
  }
  }
  else if(relay>=9 and relay<=16)
  {
  state2 = bitRead(ledStatus2,relay - 9);
  Serial.print(state1);
  Serial.println(state2);
  if(state2 == state1)
  {
  Serial.print(relay);
  Serial.println(state1);
  }
  else
  {
  ledStatus2 ^= state[relay];
  digitalWrite(latchPin2, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, ledStatus2);  
  digitalWrite(latchPin2, HIGH);//các đèn LED sẽ sáng với trạng thái vừa được cập nhật 
  Serial.print(relay);
  Serial.println(state1);
  printBinary(ledStatus2);
  Serial.println("TH2");
  }
  }
  else if(relay>=17 and relay<=24)
  {
  state2 = bitRead(ledStatus3,relay - 17);
  Serial.print(state1);
  Serial.println(state2);
  if(state2 == state1)
  {
  Serial.print(relay);
  Serial.println(state1);    
  }
  else
  {  
  ledStatus3 ^= state[relay];
  digitalWrite(latchPin3, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, ledStatus3);  
  digitalWrite(latchPin3, HIGH);//các đèn LED sẽ sáng với trạng thái vừa được cập nhật 
  Serial.print(relay);
  Serial.println(state1);
  printBinary(ledStatus3);
  Serial.println("TH3"); 
  }
  }
}
//................................................................
void printBinary(byte inByte)
{
  for (int b = 7; b >= 0; b--)
  {
    Serial.print(bitRead(inByte, b));
  }
}
void loop()
{
    Blynk.run();
}
