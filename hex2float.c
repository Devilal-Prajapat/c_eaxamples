#include <stdio.h>
#include <stdint.h>

// 1. first method
float hex2float(uint8_t *val, int len)
{
    uint32_t temp=0 ;
    float fval;
    temp = val[3] | temp;
    temp = val[2] << 8 | temp;
    temp = val[1] << 16 | temp;
    temp = val[0] << 24 | temp;
    fval = *(float *)&temp;
    printf("%f\n",fval);
}

// 2. second method
float hex2Float(uint8_t *val)
{
  uint32_t temp = 0;
  float out = 0.0;
  char tempS[32] = {0};
  uint32_t num = 0;
  temp = val[3] | temp;
  temp = val[2] << 8 | temp;
  temp = val[1] << 16 | temp;
  temp = val[0] << 24 | temp;
  sprintf(tempS, "%lx", temp);
  sscanf(tempS, "%lx", &num);
  out = *((float *)&num);
  printf("%f\n",out);
  return out;
}

uint8_t arr1[] = {0x42, 0xf7 ,0x00 ,0x00};
//42f70000 // 123.5
uint8_t arr2[] = {0x43, 0x47 ,0xfc ,0xac};
//0x4347fcac // 199.987
int main()
{
    printf("Hello World\n");
    hex2float(arr1,4);
    hex2Float(arr1);
    
     hex2float(arr2,4);
    hex2Float(arr2);

    return 0;
}
