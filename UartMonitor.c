#include <stdio.h>
#include <wiringPi.h>
#include <wiringSerial.h>

/* TXD1: GPIO_14
   RXD1: GPIO_15
   TXD2: GPIO_0
   RXD2: GPIO_1
 */

int main(void)
{
    int SerialPortOne = serialOpen("/dev/ttyS0", 9600);
    int SerialPortTwo = serialOpen("/dev/ttyAMA1", 9600);
    if((SerialPortOne < 0) || (SerialPortTwo < 0))
    {
        printf("Error while opening serial port: %d, %d\n", SerialPortOne<0, SerialPortTwo<0);
    }
    else
    {
        char PrintLabelOne = 1;
        char PrintLabelTwo = 1;
        while(1)
        {
            char SerialOneData;
            char SerialTwoData;
            if(serialDataAvail(SerialPortOne) != 0)
            {
                if(PrintLabelOne != 0)
                {
                    printf("(S1:)");
                    PrintLabelOne = 0;
                }
                SerialOneData = serialGetchar(SerialPortOne);
                printf("%c",SerialOneData);
                fflush(stdout);
                if(SerialOneData == '\n')
                {
                    PrintLabelOne = 1;
                    PrintLabelTwo = 1;
                }
            }
            if(serialDataAvail(SerialPortTwo) != 0)
            {
                if(PrintLabelTwo != 0)
                {
                    printf("(S2:)");
                    PrintLabelTwo = 0;
                }
                SerialTwoData = serialGetchar(SerialPortTwo);
                printf("%c", SerialTwoData);
                fflush(stdout);
                if(SerialTwoData == '\n')
                {
                    PrintLabelOne = 1;
                    PrintLabelTwo = 1;
                }
            }
        }
    }
    return 0;
}
