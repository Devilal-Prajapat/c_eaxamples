#include <stdio.h>
#include <stdlib.h>

int main(){
   int x, y;
   printf("Hello World!!!\n");
   printf("Enter the value of x and y\n");
   scanf("%d %d", &x, &y);
   printf("value before swap x : %d y : %d\n", x, y);
   /* using multipication and division*/
   x = x*y;
   y = x/y;
   x= x/y;
   printf("value after swap x : %d y : %d\n", x, y);
  
  /* using Addition and subtraction*/
   x = x+y;
   y = x-y;
   x= x-y;
   printf("value after swap x : %d y : %d\n", x, y);
   
   /* using xor operator*/
   x = x^y;
   y = x^y;
   x= x^y;
   printf("value after swap x : %d y : %d\n", x, y);
   return 0;
}
