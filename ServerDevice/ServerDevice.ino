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
#define BLYNK_PRINT Serial
// Allow for receiving messages up to 512 bytes long
//#define BLYNK_MAX_READBYTES 512

#include <UIPEthernet.h>
#include <BlynkSimpleUIPEthernet.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "31c6d5bfa5344992b9b50be85d606047";

BLYNK_WRITE(V1)
{
  Serial.println("WebHook data:");
  Serial.println(param.asStr());
//    Blynk.virtualWrite(V0, "http://smarthome.tictag.vn:3000/user/123/gate/1");

}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, "smarthome.tictag.vn", 8080);
//      Blynk.virtualWrite(V0, "http://192.168.100.3:3000/user/123/gate/1");

  //Blynk.begin(auth, IPAddress(192,168,1,100), 8080);

}

void loop()
{
  Blynk.run();
}

