
#include <stdio.h>
#include <stdint.h>
char hexStr[256];
void hex2str(char *data, uint8_t data_len)
{   
    unsigned char * pin = data;
    const char * hex = "0123456789ABCDEF";
    char * pout = hexStr;
    uint8_t i = 0;
  
    for(; i < data_len- 1; ++i)
          {
              *pout++ = hex[(*pin>>4)&0xF];
              *pout++ = hex[(*pin++)&0xF];
          }
          *pout++ = hex[(*pin>>4)&0xF];
          *pout++ = hex[(*pin)&0xF];
          pout = hexStr;
        printf("%s",pout);
}

int main()
{
    char data[] ={0x97,0x31,0x30,0x31,0x30,0x31};
    hex2str(data,6);
    // const char * hex = "0123456789ABCDEF";
    // char data1[] = {hex[(0x97>>4) & 0x0F],hex[(0x97) & 0x0F]};
    // printf(" %s",data1);
    return 0;
}
