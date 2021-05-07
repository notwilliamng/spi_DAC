#include "msp.h"
#include "spi_DAC.h"
#define SPI_CS BIT4
#define SPI_SCLK BIT5
#define SPI_SIMO BIT6

/**
 * main.c
 * P2.4 = chip select
 * P1.5 = UCB0CLK SCLK
 * P1.6 = UCS0SIMO SDI
 */
void main(void)
{
    uint16_t spi_data;
    //uint8_t hibyte, lobyte;

    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    spi_init();// configure SPI

    while(1) {
        for (spi_data =0; spi_data<=4095; spi_data++){ //sawtooth wave
            spi_send(spi_data);
        }
        for (spi_data =4095; spi_data >0; spi_data--){ //triangle wave
            spi_send(spi_data);
        }
//        if(spi_data==0){                                              //square wave
//            spi_data = 4095;
//            spi_send(spi_data);
//            __delay_cycles(500000); //delay before sending next value
//        }
//        else{
//            spi_data =0;
//            spi_send(spi_data);
//            __delay_cycles(500000); //delay before sending next value
//        }

    }

}
