#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

int main(void)
{
    int SerialPortOne = serialOpen("/dev/ttyS0", 9600);
    int SerialPortTwo = serialOpen("/dev/ttyAMA1", 9600);
    if((SerialPortOne < 0) || (SerialPortTwo < 0))
    {
        printf("Error while opening serial port\n");
    }
    else
    {
        
    }
    printf("Hello world");
    return 0;
}
