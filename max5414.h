// @File		MAX5414.H		 		
// @Author		JOSIMAR PEREIRA LEITE
// @country		BRAZIL
// @Date		16/03/24
//
//
// Copyright (C) 2024 JOSIMAR PEREIRA LEITE
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//

#ifndef MAX5414_H
#define MAX5414_H

#define MAX5414_SCK PORTCbits.RC0
#define MAX5414_DIN PORTCbits.RC1
#define MAX5414_CS PORTCbits.RC3

#define MAX5414_SCK_TRIS TRISCbits.RC0
#define MAX5414_DIN_TRIS TRISCbits.RC1
#define MAX5414_CS_TRIS TRISCbits.RC3

// B8: POT: 0:POT A, 1: POT B 
// B7: DATA BIT7
// B6: DATA BIT6
// B5: DATA BIT5
// B4: DATA BIT4
// B3: DATA BIT3
// B2: DATA BIT2
// B1: DATA BIT1
// B0: DATA BIT0
static const void SPI_transfer(unsigned int data)
{     
    for(unsigned int mask = 0x100; mask; mask >>= 1)
    {
        if(data & mask) MAX5414_DIN = 1; else MAX5414_DIN = 0;
            
         __asm__ __volatile__("nop");
         MAX5414_SCK = 1;
         __asm__ __volatile__("nop");
         MAX5414_SCK = 0;
         __asm__ __volatile__("nop");    
    }
}

void MAX5414_Write(unsigned char pot, unsigned int value)
{
    value |= (unsigned int) (pot << 8);
    
    MAX5414_CS = 0;
    SPI_transfer(value);
    MAX5414_CS = 1;
}

void MAX5414_Init(void)
{
    MAX5414_SCK_TRIS = 0;
    MAX5414_DIN_TRIS = 0;
    MAX5414_CS_TRIS = 0;
    
    MAX5414_CS = 1;
}

#endif 
