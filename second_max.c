#include <stdio.h>

int main()
{
    int arr[] = {1,5,3,4,2,100,100,64,100,100};
    
    int first_max = 0;
    int second_max=0;
    for(int i = 0; i<10; i++)
    {
        if(arr[i]>first_max)
        {
            second_max = first_max;
            first_max = arr[i];
        }
        else if(arr[i]>first_max && arr[i]!= first_max)
        {
            second_max =  arr[i];
        }
    }
    
    printf("first_max %d second_max %d", first_max, second_max);
}
