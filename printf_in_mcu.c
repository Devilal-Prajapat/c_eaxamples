#include <stdio.h>
struct __FILE {int handle;/* Add whatever you need here */};

FILE __stdout;
FILE __stdin;

void UART_SendChar(char ch);
void mcu_init(void);

int fputc(int ch, FILE *f)
{
  UART_SendChar(ch);
  return(ch);
}

void UART_SendChar(char ch)
{
  // Send Over Uart Implement
}

void mcu_init(void)
{
  //1. System Clock Initialization
  //2. Uart Initialization
}
int main()
{
  mcu_init(); // dummy
  printf("Hello from MCU\r\n");
  return 0;
}
