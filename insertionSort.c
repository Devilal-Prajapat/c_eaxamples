#include <stdio.h>
#define SIZE 5
int arr[SIZE];
void disp(void);
void insertionSort(void);

int main()
{
    printf("Hello, World!\n");
    printf("Enter value\n");
    for (int i = 0; i<SIZE; i++)
    {
        scanf("%d", &arr[i]);
        //printf("%d\n", arr[i]);
    }
    insertionSort();
    disp();

    return 0;
}

void disp(void){
   for (int i = 0; i<SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
}
void insertionSort(void){
  for(int i = 1;i<SIZE;i++){
    for(int j = 0;j<i;j++){
      if(arr[j]>arr[i]){
        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp; 
      }
    }
  }
}
