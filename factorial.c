#include <stdio.h>

int factorial_recursion(int num)
{
	if(num == 1)
	{
		return 1;
	}
	
	return (num * factorial_recursion(num - 1));
}

int factorial(int num)
{
	int fact = 1;
	for(int i = 1; i <= num; i++)
	{
		fact = fact * i;
	}
	return fact;
}

int main()
{
	printf("factorial recursion %d\r\n", factorial_recursion(7));
	printf("factorial normal %d\r\n", factorial(5));
	return 0;
}