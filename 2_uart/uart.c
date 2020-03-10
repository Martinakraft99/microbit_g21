#include "uart.h"
#include "gpio.h"


void uart_init(){
  UART->BAUDRATE = (0x00275000);
  UART->PSELRTS = (0xFFFFFFFF);
  UART->PSELCTS = (0xFFFFFFFF);
  UART->ENABLE = (4);
  UART->STARTRX = (1);
}


void uart_send(char letter){
  UART->STARTTX = 1;
  UART->TXD = letter;
  /*
  for(int i = 0; i< 8;i++){
    UART->TXD = letter[i];
  }*/
  UART->STOPTX = 1;
}

char uart_read(){
  UART->RXDRDY = 0;
  char temp = UART->RXD;
  if(temp){
    return temp;
  }
  return ('\0');
}
