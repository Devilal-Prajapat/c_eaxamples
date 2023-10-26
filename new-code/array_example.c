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

int main()
{
    struct Array arr = {{1, 2, 5, 7, 9},10, 5};    
    display(arr);
    append(&arr, 81);
    display(arr);
    insert(&arr, 0 ,8);
    display(arr);
    
    return 0;
}
