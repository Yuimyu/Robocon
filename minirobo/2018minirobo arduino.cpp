
#include <PS4BT.h>
#include <usbhub.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
#include<Wire.h>

USB Usb;
BTD Btd(&Usb);
PS4BT PS4(&Btd, PAIR);
int a = 2;
int b = 3;
int sa = 0;
int sb = 0;
int c = 0;
int d = 0;
int up = 0;
int right = 0;
int down = 0;
int left = 0;
int r2 = 0;
int l2 = 0;
int r1 = 0;
int l1 = 0;

void setup()
{
  Serial.begin(115200);
#if !defined(__MIPSEL__)
  while (!Serial);
#endif
  if (Usb.Init() == -1)
  {
    Serial.print(F("\r\nOSC did not start"));
    while (1);
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  Wire.begin(0x01);
  Wire.setClock(400000);
  Wire.onRequest(requestEvent);
}

void loop()
{
  Usb.Task();

  if (PS4.connected())
  {
    if (PS4.getButtonClick(CIRCLE))
    {sa = sa^1;
      digitalWrite(a,sa);
      Serial.println(sa^1);}

    if (PS4.getButtonClick(CROSS))
    {sb = sb^1;
      digitalWrite(b,sb);
      Serial.println(sb^1);}
    
    {up = PS4.getButtonPress(UP);
      Serial.println(up);}

    {down = PS4.getButtonPress(DOWN);
      Serial.println(down);}
    
    {right = PS4.getButtonPress(RIGHT);
      Serial.println(right);}

    {left = PS4.getButtonPress(LEFT);
      Serial.println(left);}

    {c = PS4.getButtonPress(TRIANGLE);
      Serial.println(c);}
    
    {d = PS4.getButtonPress(SQUARE);
      Serial.println(d);}
    
    {l2 = PS4.getButtonPress(L2);
      Serial.println(l2);}

    {r2 = PS4.getButtonPress(R2);
      Serial.println(r2);}
    
    {r1 = PS4.getButtonPress(R1);
      Serial.println(r1);}
    
    {l1 = PS4.getButtonPress(L1);
     Serial.println(l1);}
    
    if (PS4.getButtonClick(TOUCHPAD))
    {Serial.print(F("\r\nPS"));
      PS4.disconnect();
    }
    
  }
  else
  {   c = 0;
      d = 0;
      up = 0;
      down = 0;
      right = 0;
      left = 0;
      r2 = 0;
      l2 = 0;
      r1 = 0;
      l1 = 0;
  }
}

void requestEvent()
{
  Wire.write(c);
  Wire.write(d);
  Wire.write(up);
  Wire.write(down);
  Wire.write(right);
  Wire.write(left);
  Wire.write(r2);
  Wire.write(l2);
  Wire.write(r1);
  Wire.write(l1);
}