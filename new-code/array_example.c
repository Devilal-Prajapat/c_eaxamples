/******************************************************************************

                              Online C++ Debugger.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Debug" button to debug it.

*******************************************************************************/

#include <stdio.h>

struct Array{
    int A[10];
    int size;
    int len;
};

void display(struct Array arr)
{
    printf("\r\nElements: ");
    for(int i = 0; i < arr.len; i++)
    printf("%d ",arr.A[i]);
}

void append(struct Array *arr,int x)
{
    if(arr->len < arr->size)
    {
        arr->A[arr->len] = x;
        arr->len += 1;
        
    }
}

void insert(struct Array *arr,int idx, int x)
{
    if(idx >= 0 && idx <= arr->len)
    {
        for(int i = arr->len; i > idx; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[idx] = x;
        arr->len += 1;
    }
}

void delete(struct Array *arr,int idx)
{
    if(idx >= 0 && idx < arr->len)
    {
        for(int i=idx; i < arr->len -1 ; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->len -= 1;
    }
}


void swap(int *x, int *y)
{
    int temp = *x;
    *x= *y;
    *y = temp;
}


int LinerSearch(struct Array *arr, int key)
{
    for(int i = 0; i < arr->len; i++)
    {
        if(key == arr->A[i])
        {
            //swap(&arr->A[i], &arr->A[i-1]); // Transposition
            //swap(&arr->A[i], &arr->A[0]);  // Move to head
            return i;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 5, 7, 9},10, 5};
    
    display(arr);
    append(&arr, 81);
    display(arr);
    insert(&arr, 0 ,8);
    display(arr);
    delete( &arr, 1);
    display(arr);
    printf("\r\nElelment found at idx = %d",LinerSearch(&arr, 81));
    display(arr);
    printf("\r\nElelment found at idx = %d",LinerSearch(&arr, 81));
    display(arr);
    
    return 0;
}
