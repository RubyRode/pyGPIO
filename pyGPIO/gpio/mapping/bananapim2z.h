/*
 *
 * This file is part of pyA20.
 * mapping.h is python GPIO extension.
 *
 * Copyright (c) 2014 Stefan Mavrodiev @ OLIMEX LTD, <support@olimex.com>
 *
 * pyA20 is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 * mapping.h from: https://github.com/wdmomoxx/orangepi_ZERO_gpio_pyH2
 *
 */

#ifndef __MAPPING_H
#define __MAPPING_H

#include "gpio_lib.h"

/**
Structure that describe all gpio
*/
typedef struct _pin {
	char name[10];          // The processor pin
	int offset;             // Memory offset for the pin
	int pin_number;         // Number on the connector
}pin_t;

typedef struct _gpio {
	char connector_name[10];
	pin_t pins[41];
}gpio_t;


gpio_t gpio[] = {

/*
Description of Pinheader, please don't change pinnumer to keep this library consistent! A 'RPi compatible'
pin header (40pin) looks like the following:
 +-----+-----+---------+------+---+--Pi-M2Z--+---+------+---------+-----+-----+
 | BPI | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BPI |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 |     |     |    3.3v |      |   |  1 || 2  |   |      | 5v      |     |     |
 |  12 |   8 |   SDA.1 | ALT5 | 0 |  3 || 4  |   |      | 5v      |     |     |
 |  11 |   9 |   SCL.1 | ALT5 | 0 |  5 || 6  |   |      | 0v      |     |     |
 |   6 |   7 | GPIO. 7 | ALT3 | 0 |  7 || 8  | 0 | ALT4 | TxD     | 15  | 13  |
 |     |     |      0v |      |   |  9 || 10 | 0 | ALT4 | RxD     | 16  | 14  |
 |   1 |   0 | GPIO. 0 | ALT5 | 0 | 11 || 12 | 0 | ALT3 | GPIO. 1 | 1   | 16  |
 |   0 |   2 | GPIO. 2 | ALT5 | 0 | 13 || 14 |   |      | 0v      |     |     |
 |   3 |   3 | GPIO. 3 | ALT3 | 0 | 15 || 16 | 0 | ALT3 | GPIO. 4 | 4   | 15  |
 |     |     |    3.3v |      |   | 17 || 18 | 0 | ALT3 | GPIO. 5 | 5   | 68  |
 |  64 |  12 |    MOSI | ALT4 | 0 | 19 || 20 |   |      | 0v      |     |     |
 |  65 |  13 |    MISO | ALT4 | 0 | 21 || 22 | 0 | ALT3 | GPIO. 6 | 6   | 2   |
 |  66 |  14 |    SCLK | ALT4 | 0 | 23 || 24 | 0 | ALT4 | CE0     | 10  | 67  |
 |     |     |      0v |      |   | 25 || 26 | 0 | ALT3 | CE1     | 11  | 71  |
 |  19 |  30 |   SDA.0 | ALT3 | 0 | 27 || 28 | 0 | ALT3 | SCL.0   | 31  | 18  |
 |   7 |  21 | GPIO.21 | ALT3 | 0 | 29 || 30 |   |      | 0v      |     |     |
 |   8 |  22 | GPIO.22 | ALT3 | 0 | 31 || 32 | 0 | ALT3 | GPIO.26 | 26  | 354 |
 |   9 |  23 | GPIO.23 | ALT3 | 0 | 33 || 34 |   |      | 0v      |     |     |
 |  10 |  24 | GPIO.24 | ALT3 | 0 | 35 || 36 | 0 | ALT3 | GPIO.27 | 27  | 356 |
 |  17 |  25 | GPIO.25 | ALT3 | 0 | 37 || 38 | 0 | ALT3 | GPIO.28 | 28  | 21  |
 |     |     |      0v |      |   | 39 || 40 | 0 | ALT3 | GPIO.29 | 29  | 20  |
 +-----+-----+---------+------+---+----++----+---+------+---------+-----+-----+
 | BPI | wPi |   Name  | Mode | V | Physical | V | Mode | Name    | wPi | BPI |
 +-----+-----+---------+------+---+--Pi-M2Z--+---+------+---------+-----+-----+

(*) on the RPi those two pins are used for official HATS (read out eeprom), since this is never depoyed 
on SUNXI boards we can use this GPIOs too. ;)
replace XZ with the pin which is wired out on this position (e.g. PA10, PG11 etc.) 
*/  
	{"GPIO",
		{
			// left side
      {   "GPIO3",  SUNXI_GPA(12),   3   }, // TWI0-SDA PA12-ENT12
      {   "GPIO5",  SUNXI_GPA(11),   5   }, // TWI0-SCK PA11-ENT11
      {   "GPIO7",  SUNXI_GPA(6),    7   }, // PWM1 PA6-ENT6
      {   "GPIO11",  SUNXI_GPA(1),   11  }, // UART2-RX PA1-ENT1
      {   "GPIO13",  SUNXI_GPA(0),   13  }, // UART2-TX PA0-ENT0
      {   "GPIO15",  SUNXI_GPA(3),   15  }, // UART2-CTS PA3-ENT3
      {   "GPIO19",  SUNXI_GPC(0),   19  }, // SPI0-MOSI PC0
      {   "GPIO21",  SUNXI_GPC(1),   21  }, // SPI0-MISO PC1
      {   "GPIO23",  SUNXI_GPC(2),   23  }, // SPI0-CLK PC2
      {   "GPIO27",  SUNXI_GPA(19),  27  }, // TWI1-SDA PA19-ENT19
      {   "GPIO29",  SUNXI_GPA(7),   29  }, // PA7-EINT7 
      {   "GPIO31",  SUNXI_GPA(8),   31  }, // PA8-EINT8 
      {   "GPIO33",  SUNXI_GPA(9),   33  }, // PA9-EINT9
      {   "GPIO35",  SUNXI_GPA(10),  35  }, // PA10-EINT10
      {   "GPIO37",  SUNXI_GPA(17),  37  }, // PA17-EINT17 SPDIF-OUT
      // right side
      {   "GPIO8",  SUNXI_GPA(13),   8   }, // UART3-TX PA13
      {   "GPIO10",  SUNXI_GPA(14),  10  }, // UART3-RX PA14
      {   "GPIO12",  SUNXI_GPA(16),  12  }, // UART3-CTS PA16
      {   "GPIO16",  SUNXI_GPA(15),  16  }, // UART3-RTS PA15
      {   "GPIO18",  SUNXI_GPC(4),   18  }, // PC4  
      {   "GPIO22",  SUNXI_GPA(2),   22  }, // UART2_RTS PA2
      {   "GPIO24",  SUNXI_GPC(3),   24  }, // SPI0-CS PC3
      {   "GPIO26",  SUNXI_GPC(7),   26  }, // PC7 
      {   "GPIO28",  SUNXI_GPA(18),  28  }, // TWI1-SCK PA18      
      {   "GPIO32",  SUNXI_GPL(2),   32  }, // PL2-S-EINT2
      {   "GPIO26",  SUNXI_GPL(4),   36  }, // PL4-ENT4
      {   "GPIO38",  SUNXI_GPA(21),  38  }, // PA21-EINT21
      {   "GPIO40",  SUNXI_GPA(20),  40  }, // PA20-EINT20
      {
          {   0,  0,  0}
      },
		}
	},

  /*
    #define PIN_PG0		SUNXI_GPG(0)
*/
	{"LED",
		{
			{   "POWER_LED",  SUNXI_GPL(10),  1   },
			{
				{   0,  0,  0}
			},
		}
	},
};

#endif
