#include <stdio.h>
#include <string.h>

void rev_string(char *str)
{
	int len = 0;
	while(str[len]!= '\0')
	{
		len++;
	}
	for(int i = 0; i<len/2;i++)
	{
		char temp = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = temp;
	}
	printf("%s\n",str);
	
}

int main()
{
	char str[100] = {0};
	char new_str[5][100];
	printf("Enter your name\n");
	gets(str);
	rev_string(str);	
	char *tok = " ";
	int i = 0;
	char *start = &str[0];
	char *ptr = strtok(str,tok);	
	while(ptr != NULL)
	{
		rev_string(ptr);
		ptr = strtok(0,tok);
		i++;
		//printf("count %d \n", i);
		
	}
	
}
