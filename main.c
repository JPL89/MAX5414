// @File		MAIN.C		 		
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
#include "utils.h"
#include "max5414.h"

void main(void)
{
    __delay_ms(500);   
    
    Pic18f2520_init();
    
    MAX5414_Write(1, 255);
    MAX5414_Write(0, 0);
    
    while(1)
    {  
        
    }    
    
    return;
}
