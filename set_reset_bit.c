#include <stdio.h>
#include <stdint.h>

int set_reset_bit(uint32_t num, uint32_t pos, uint8_t val)
{
    if(val == 0)
	{
		num &= ~(1<<pos);
	}
	else
	{
		num |= (1<<pos);
	}
    return num;
}

int main()
{
    printf("Hello World");
    printf("\nset_reset_bit: %d", set_reset_bit(7, 2, 0));
	printf("\nset_reset_bit: %d", set_reset_bit(3, 2, 1));
    return 0;
}
