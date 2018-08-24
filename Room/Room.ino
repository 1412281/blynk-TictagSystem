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

void           (*resetFunc)(void) = 0; //declare reset function at address 0

byte           tokenHasSet = 0;

char TOKEN_DEFAULT[] = "0f1add3742174f88bc8f93f37486c3b9";

BLYNK_WRITE(V0)
{
    Serial.println("WebHook data:");
    Serial.println(param.asStr());
}

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
    Serial.begin(9600);

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

void loop()
{
    Blynk.run();
}
