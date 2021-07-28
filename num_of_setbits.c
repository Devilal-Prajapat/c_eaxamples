#include <stdio.h>
#include <stdint.h>

int num_of_set_bits(uint32_t num )
{
    uint32_t bit_count = 0;
    for(int i = 0;i<32; i++)
    {
        if((num>>i)& 0x01 == 0x01)
        {
            bit_count++;
        }
    }
    return bit_count;
}

int main()
{
    printf("Hello World");
    printf("\nnum_of_set_bits: %d",num_of_set_bits(15));
	printf("\nnum_of_set_bits: %d",num_of_set_bits(7));
	printf("\nnum_of_set_bits: %d",num_of_set_bits(5));
	printf("\nnum_of_set_bits: %d",num_of_set_bits(3));
    return 0;
}
