#include <stdio.h>

void reverse_string(char *ptr)
{
    int len = 0;
	char *ptr1 = ptr;
	while(*ptr1 != '\0')
	{
		len++;
		ptr1++;
	}	
	printf("%d", len);

    for(int i = 0;i<len/2; i++)
    {
        char temp = ptr[i];
		ptr[i] = ptr[len-i-1];
		ptr[len-i-1]= temp;				
    }	
}

int main()
{
	printf("Hello World");
	char arr[] = "Hello World1";
	reverse_string(arr);
	printf("\n%s",arr);

	return 0;
}
