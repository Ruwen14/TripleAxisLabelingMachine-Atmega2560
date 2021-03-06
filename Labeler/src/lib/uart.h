/*
 * uart.h
 *
 * Created: 24.05.2022 10:49:28
 *  Author: Oli & ruwen
 */ 


#ifndef UART_H_
#define UART_H_

#include "constants.h"

// see https://github.com/arduino/ArduinoCore-avr/blob/24e6edd475c287cdafee0a4db2eb98927ce3cf58/cores/arduino/HardwareSerial.cpp HardwareSerial::begin()


// Es funktioniert nur mit UART0 (von 4) keine Ahnung warum
void uart_init(void);

// ToDo: Overflow check
void uart_send(unsigned char data);

void uart_send_16bit(uint16_t data);

unsigned char uart_rec(void);





typedef enum
{
	INPUT_INCOMPLETED,
	INPUT_COMPLETED
} UserInputHandler_Status;

typedef struct
{
	uint8_t bufidx;
	uint8_t second_row_at;
	UserInputHandler_Status status;
	char input_buffer[33];
} UserInputHandler;


void UserInputHandler_poll_input(UserInputHandler* handler);

void UserInputHandler_reset_input(UserInputHandler* handler);


#endif /* UART_H_ */