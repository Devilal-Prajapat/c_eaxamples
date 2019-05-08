#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
 
  int amt , rate, year;
  float interest;
  printf("Hello world!!!\nThis is my first program!!\n");
  
  printf("Enter principal amount\n");
  scanf("%d", &amt);
  
  printf("Enter rate and Years to For interest\n");
  scanf("%d %d",&rate, &year);
  printf("you have entered\namount : %d rate : %d year  %d\n",amt, rate, year);
  interest = (amt*rate*year)/100;
 
  printf("Total Interset is : %f \n", interest);
  //EXIT(0);
  return 0;
}