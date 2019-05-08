#include <stdio.h>
#define SIZE 5
int arr[SIZE];
void disp(void);
void bubbleSort(void);

int main()
{
    printf("Hello, World!\n");
    printf("Enter value\n");
    for (int i = 0; i<SIZE; i++)
    {
        scanf("%d", &arr[i]);
        //printf("%d\n", arr[i]);
    }
    bubbleSort();
    disp();

    return 0;
}

void disp(void){
   for (int i = 0; i<SIZE; i++)
    {
        //scanf("%d", &arr[i]);
        printf("%d\n", arr[i]);
    }
}
void bubbleSort(void){
  for(int i = 1;i<SIZE;i++){
    for(int j = 0;j<SIZE-i;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp; 
      }
    }
  }
}
