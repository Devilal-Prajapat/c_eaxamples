#include<stdio.h>
#include<math.h>

/* convert decimal num to binary */
int dec_to_bin(int n);

/* convert binary num to decimal */
int bin_to_dec(int n);

int dec_to_bin(int n)
{
    int bin =0; int rem = 0;
    int i = 1;
    while(n!=0)
    {
        rem = n%2;
        n = n/2;
        bin += rem*i;
        i = i*10;
    }
    printf("%d\n",bin);
}

int bin_to_dec(int n)
{
    int dec =0; int rem = 0;
    int i = 0;
    while(n!=0)
    {
        rem = n%10;
        n = n/10;
        dec += rem*pow(2,i);
        i++;
    }
    printf("%d\n",dec);
}

int main()
{
  dec_to_bin(15); /* expected output b'1111 */
  bin_to_dec(1101); /* expected output 13 */
  return 0;
  
}
