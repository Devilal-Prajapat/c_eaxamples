#include <stdio.h>
#define SIZE 5
int arr[SIZE];
void disp(void);
void insertionSort(void);
void search(int val);
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
    printf("Enter Value to serach\n");
    int a;
    scanf("%d", &a);
    search(a);

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

void search(int val){
  int mid;
  int lb = 0;
  int ub = SIZE -1;
  
  while(lb<=ub){
    mid = (lb+ub)/2;
    if(val == arr[mid]){
      printf("found %d at %d location\n", val,mid);
      break;
    }
    else if(val<arr[mid]){
      ub = mid-1;
    }
    else if(val>=arr[mid]){
      lb = mid+1;
    }  
  }
  if(lb>ub){
    printf("Not found");
  }
}

