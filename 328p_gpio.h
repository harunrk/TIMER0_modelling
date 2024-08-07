#ifndef _328P_GPIO_H_
#define _328P_GPIO_H_

#ifndef __STDINT_H_
#include <stdint.h>
#endif

/* Register Adresses Of GPIO Ports */
#define  REG_ADDR_PINB			0x23
#define  REG_ADDR_DDRB			0x24
#define  REG_ADDR_PORTB			0x25

#define  REG_ADDR_PINC			0x26
#define  REG_ADDR_DDRC			0x27
#define  REG_ADDR_PORTC			0x28

#define  REG_ADDR_PIND			0x29
#define  REG_ADDR_DDRD			0x2A
#define  REG_ADDR_PORTD			0x2B

/* Standard Definitions Of GPIO */
//#define _REG_PINB				(*(volatile uint8_t*) REG_ADDR_PINB)
//#define _REG_DDRB				(*(volatile uint8_t*) REG_ADDR_DDRB)
//#define _REG_PORTB				(*(volatile uint8_t*) REG_ADDR_PORTB)
//
//#define _REG_PINC				(*(volatile uint8_t*) REG_ADDR_PINC)
//#define _REG_DDRC				(*(volatile uint8_t*) REG_ADDR_DDRC)
//#define _REG_PORTC				(*(volatile uint8_t*) REG_ADDR_PORTC)
//
//#define _REG_PIND				(*(volatile uint8_t*) REG_ADDR_PIND)
//#define _REG_DDRD				(*(volatile uint8_t*) REG_ADDR_DDRD)
//#define _REG_PORTD				(*(volatile uint8_t*) REG_ADDR_PORTD)

typedef struct{
	uint8_t pin0:1;
	uint8_t pin1:1;
	uint8_t pin2:1;
	uint8_t pin3:1;
	uint8_t pin4:1;
	uint8_t pin5:1;
	uint8_t pin6:1;
	uint8_t pin7:1;
} pin_t, *pin_ptr_t;

typedef union{								// De�er verilen eleman d���ndakileri ge�ersiz k�lar.
	pin_t pins;								// �stenirse pinlere tek tek ula��l�r
	volatile uint8_t port;					// �stenirse t�m pinlere ula��l�r 
} port_t, *port_ptr_t;

/* PORT UNIONS */
#ifdef USE_GPIO_B
#define PINB_UNION				(*(port_ptr_t) REG_ADDR_PINB)
#define DDRB_UNION				(*(port_ptr_t) REG_ADDR_DDRB)
#define PORTB_UNION				(*(port_ptr_t) REG_ADDR_PORTB)
#endif

#ifdef USE_GPIO_C
#define PINC_UNION				(*(port_ptr_t) REG_ADDR_PINC)
#define DDRC_UNION				(*(port_ptr_t) REG_ADDR_DDRC)
#define PORTC_UNION				(*(port_ptr_t) REG_ADDR_PORTC)
#endif

#ifdef USE_GPIO_D
#define PIND_UNION				(*(port_ptr_t) REG_ADDR_PIND)
#define DDRD_UNION				(*(port_ptr_t) REG_ADDR_DDRD)
#define PORTD_UNION				(*(port_ptr_t) REG_ADDR_PORTD)
#endif

#define PIN_INPUT				0
#define PIN_OUTPUT				1
#define PORT_ALL_INPUT			0x00
#define PORT_ALL_OUTPUT			0xFF
#define PIN_LOW					0
#define PIN_HIGH				1
#define PORT_ALL_LOW			0x00
#define PORT_ALL_HIGH			0xFF
#define PIN_PULLUP_ON			1
#define PIN_PULLUP_OFF			0
#define PORT_ALL_PULLUP_ON		0xFF
#define PORT_ALL_PULLUP_OFF		0x00

#endif /* _328P_GPIO_H_ */