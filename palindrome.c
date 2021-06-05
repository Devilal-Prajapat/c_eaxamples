#include <stdio.h>

int reverse_of_digits(int num)
{
	int reverse = 0;
	while( num!= 0)
	{
		int rem = num % 10;
		reverse = (reverse*10) + rem;
		num = num/10;
	}
	return reverse;
}

int main()
{	
	int num1 = 123;
	int num2 = 1331;
	
	int num3 = reverse_of_digits(num1);
	int num4 = reverse_of_digits(num2);
	
	if(num3 == num1 )
	{
		printf("Palindrom\n");
	}
	else
	{		
		printf("not a Palindrom\n");
	}
	if(num4 == num2 )
	{
		printf("Palindrom\n");
	}
	else
	{		
		printf("not a Palindrom\n");
	}
	return 0;
}