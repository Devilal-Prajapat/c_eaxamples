#include <stdio.h>

int num_of_digits(int num)
{
	int count = 0;
	do{
		count++;
		num = num/10;
	}while( num!= 0);
	return count;
}

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

int sum_of_digits(int num)
{
	int sum = 0;
	while( num!= 0)
	{
		int rem = num % 10;
		sum = sum  + rem;
		num = num/10;
	}
	return sum;
}

int main()
{	
	printf("num of digits in number is %d\n", num_of_digits(0));
	printf("num of digits in number is %d\n", num_of_digits(10));
	printf("num of digits in number is %d\n", num_of_digits(123));
	
	printf("reverse of number is %d\n", reverse_of_digits(0));
	printf("reverse of number is %d\n", reverse_of_digits(10));
	printf("reverse of number is %d\n", reverse_of_digits(123));
	
	printf("sum of digits in number is %d\n", sum_of_digits(0));
	printf("sum of digits in number is %d\n", sum_of_digits(10));
	printf("sum of digits in number is %d\n", sum_of_digits(123));
	return 0;
}