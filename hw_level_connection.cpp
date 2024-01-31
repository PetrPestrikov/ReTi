/*
 * hw_level_connection.cpp
 *
 *  Created on: 20 ГѓВ¬ГѓВ ГѓВї 2022 ГѓВЈ.
 *      Author: 79141
 */


#include "hw_level_connection.h"





void HardwareSetup(void)
{
       // Enable lazy stacking for interrupt handlers.  This allows floating-point
       // instructions to be used within interrupt handlers, but at the expense of
       // extra stack usage.
       FPULazyStackingEnable();


       //SysCtlClockSet( SYSCTL_SYSDIV_5 | SYSCTL_OSC_INT ); //40 MHz

       SysCtlClockSet( SYSCTL_SYSDIV_4 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN); // 50MHz

       uint32_t test = SysCtlClockGet();


       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOG);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOK);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOL);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOM);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOP);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOH);
       //SysCtlPeripheralEnable(SYSCTL_PERIPH_SSI0);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_EEPROM0);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C1);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C2);


       //We are waiting for the readiness of each periphery !
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOC)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOD)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOE)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOG)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOJ)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOK)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOL)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOM)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPION)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOP)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOH)) {  }
       //while(!SysCtlPeripheralReady(SYSCTL_PERIPH_SSI0)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_EEPROM0)) { }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C0)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C1)) {  }
       while(!SysCtlPeripheralReady(SYSCTL_PERIPH_I2C2)) {  }

}






