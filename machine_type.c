#include <stdio.h>


int main()
{
	union {
		int a;
		char c[sizeof(int)];
	}var;
	var.a = 1;
	if(var.c[0] == 1)
	{
		printf("Little Endian\n");
	}
	else
	{
		printf("Big Endian\n");
	}

	return 0;
}