#include <stdio.h>
int sum_of_digits(int num)
{
    int res = 0;
    while(num != 0)
    {
        res += (num % 10);
        num = num /10;
    }
    return res;
}

int fact(int num)
{
    if(num == 1)
    {
        return 1;
    }
    return num *fact(num -1);
}

int main()
{
    printf("%d", sum_of_digits(123));
    printf("\r\n%d", fact(5));

    return 0;
}