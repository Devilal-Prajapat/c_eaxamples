#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
  char data[50]={0};
  int a , b;
  printf("Hello world!!!\nThis is my first program!!\n");
  printf("Enter your name\n");
  scanf("%s", data);
  printf("you entered : %s\n",data);
  
  printf("Enter number for addition\n");
  scanf("%d %d",&a, &b);
 
  printf("sum of %d and %d is : %d\n", a, b, (a+b));
  //EXIT(0);
  return 0;
}