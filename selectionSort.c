#include <stdio.h>
#define SIZE 5
int arr[SIZE];
void disp(void);
void selectionSort(void);

int main()
{
    printf("Hello, World!\n");
    printf("Enter value\n");
    for (int i = 0; i<SIZE; i++)
    {
        scanf("%d", &arr[i]);
        //printf("%d\n", arr[i]);
    }
    selectionSort();
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
void selectionSort(void){
  for(int i = 0;i<SIZE;i++){
    for(int j = i+1;j<SIZE;j++){
      if(arr[i]>arr[j]){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp; 
      }
    }
  }
}
