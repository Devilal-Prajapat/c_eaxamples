#include <stdio.h>
#define SIZE 5
int arr[SIZE];
void push(int val);
void pop(void);
int top = -1;
int main()
{
    printf("Hello, World!\n");
    printf("Enter value\n");
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(6);
    push(7);
    pop();
    push(6);
    pop();
    push(7);

    return 0;
}

void push(int val){
  if(top == SIZE -1){
    printf("stack is over FLOW\n");
  }
  else{
    top++;
    arr[top] = val;
    printf("item inserted at %d is %d\n", top , val);
  }
  
}

void pop(void){
  int val;
  if(top == -1){
    printf("stack is under FLOW\n");
  }
  else{
    printf("item remove at %d is %d\n", top, val);
    val = arr[top];
    top--; 
    
  }
  
}