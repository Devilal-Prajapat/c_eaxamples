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

int BinarySerach(struct Array arr, int key)
{
    int l = 0;
    int h = arr.len - 1;
    int mid;
   while(l<=h)
   {
        mid = (l + h) / 2;
        
        if(key == arr.A[mid])
        {
            return mid;
        }
        else if(key < arr.A[mid])
        {
            h = mid - 1;
        }
        else if(key > arr.A[mid])
        {
            l = mid + 1;
        }   
   }
   return -1;
}

int RBinSerach( int A[], int l, int h, int key)
{
   int mid;
   while(l<=h)
   {
        mid = (l + h) / 2;
        
        if(key == A[mid])
        {
            return mid;
        }
        else if(key < A[mid])
        {
            return RBinSerach(A,l, mid-1, key);
        }
        else if(key > A[mid])
        {
           return RBinSerach(A, mid+1, h, key);;
        }   
   }
   return -1;
}


void Set(struct Array *arr, int idx, int x)
{
    if(idx>=0 && idx < arr->len)
    {
        arr->A[idx] = x;
    }
}

int Get(struct Array arr, int idx)
{
    if(idx>=0 && idx < arr.len)
    {
        return arr.A[idx];
    }
    return -1;
}

int Max(struct Array arr)
{
    int max = arr.A[0];
    for(int i = 1; i<arr.len ; i++)
    {
        if(arr.A[i]>max)
        {
            max = arr.A[i];
        }
    }
    return max;
}


int Min(struct Array arr)
{
    int min = arr.A[0];
    for(int i = 1; i<arr.len ; i++)
    {
        if(arr.A[i]<min)
        {
            min = arr.A[i];
        }
    }
    return min;
}


int main()
{
    struct Array arr = {{1, 2, 5, 7, 9},10, 5};
    
    display(arr);
    append(&arr, 81);
    display(arr);
  //  insert(&arr, 0 ,8);
    display(arr);
    delete( &arr, 1);
    display(arr);
    printf("\r\nElelment found at idx = %d",LinerSearch(&arr, 81));
    display(arr);
    printf("\r\nElelment found at idx = %d",LinerSearch(&arr, 81));
    display(arr);
    
    // required sorted array for binary searching
    printf("\r\nElelment found at idx = %d",BinarySerach(arr, 1));
    display(arr);
    printf("\r\nElelment found at idx = %d",BinarySerach(arr, 8));
    display(arr);
    
     // required sorted array for binary searching
    printf("\r\nElelment found at idx = %d",RBinSerach(arr.A, 0, 6, 5 ));
    display(arr);
    printf("\r\nElelment found at idx = %d",RBinSerach(arr.A, 0, 6, 9));

    printf("\r\nMin element = %d",Min(arr));
    printf("\r\nMax element = %d",Max(arr));
    Set(&arr, 1, 6);
    printf("\r\n set element at idx %d",1);
    printf("\r\n element at idx %d is %d",1, Get(arr,1));
    
    
    return 0;
}
