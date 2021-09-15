
#include "mbed.h"
#include "Motor.h"

I2C i2c(p9,p10);

Serial serial(USBTX,USBRX);

char date[10];

Motor mo1(p21,p20);
Motor mo2(p22,p19);
Motor mo3(p23,p18);
Motor mo4(p24,p17);
Motor mo5(p25,p16);
Motor mo6(p26,p15);
DigitalIn sw1(p13);
DigitalIn sw2(p14);

int c;
int d;
int up;
int down;
int right;
int left;
int r2;
int l2;
int r1;
int l1;

int main()
{
    i2c.frequency(400000);
    int address = 0x02;
    
    while(1)
    {
        i2c.read(address,date,10);
        
        c = date[0];
        d = date[1];
        up = date[2];
        down = date[3];
        right = date[4];
        left = date[5];
        r2 = date[6];
        l2 = date[7];
        r1 = date[8];
        l1 = date[9];
        
         if(c == 1)
            mo5.speed(0.3);
        
            else if(d == 1)
            {
                mo5.speed(-0.3);
            }
            
            else if(up == 1)
            {
                mo1.speed(-0.1);
                mo2.speed(0.1);
                mo3.speed(0.1);
                mo4.speed(-0.1);
                serial.printf("\r\nup = %d",up);
            }
            
            else if(down == 1)
            {
                mo1.speed(0.1);
                mo2.speed(-0.1);
                mo3.speed(-0.1);
                mo4.speed(0.1);
            }
            
            else if(right == 1)
            {
                mo1.speed(0.2);
                mo2.speed(0.2);
                mo3.speed(-0.2);
                mo4.speed(-0.2);
            }
            
            else if(left == 1)
            {
                mo1.speed(-0.2);
                mo2.speed(-0.2);
                mo3.speed(0.2);
                mo4.speed(0.2);
            }
            
            else if(r2 == 1)
            {
                mo1.speed(0.1);
                mo2.speed(0.1);
                mo3.speed(0.1);
                mo4.speed(0.1);
                serial.printf("\r\nr2 = %d",r2);
                
            }
            
            else if(l2 == 1)
            {
                mo1.speed(-0.1);
                mo2.speed(-0.1);
                mo3.speed(-0.1);
                mo4.speed(-0.1);
                serial.printf("\r\nl2 = %d",l2);
            }
            
            else if(r1 == 1)
            {if(sw1 == 1)
            mo6.speed(0);
            
            else
            mo6.speed(0.3);}
            
            else if(l1 == 1){
                if(sw2 == 1)
                    mo6.speed(0);
                else
                    mo6.speed(-0.3);}
            
            else
            {
                mo1.speed(0);
                mo2.speed(0);
                mo3.speed(0);
                mo4.speed(0);
                mo5.speed(0);
                mo6.speed(0);
            }
    }
}
