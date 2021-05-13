#include <stdio.h>

void lcm(int a, int b)
{
    int min;
    int lcm;
    if(a>b)
    {
        min = b;
    }
    else{
        min = a;
    }
    
    lcm = min;
    while((lcm%a || lcm%b) != 0){
        lcm++;
    }
    printf("\nlcm is %d",lcm);
}

void hcf(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
            a = a-b;
        else
            b =b-a;
    }
    printf("\nhcf is %d",a);
}


int main()
{
    int a,b;
    printf("Enter two number\n");
    scanf("%d %d",&a,&b);
    lcm(a,b);
	hcf(a,b);
    return 0;
}