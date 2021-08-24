#include <stdio.h>

#define ROW 2
#define COLUMN 3
int arr[ROW][COLUMN]={{1,2,3},{4,5,6}};
int arr1[COLUMN][ROW];
int main()
{
    for(int i = 0; i<COLUMN; i++)
    {
        for(int j = 0; j<ROW; j++)
        {
           arr1[i][j] = arr[j][i]; 
           printf("%d ",arr1[i][j]);
        }
         printf("\n");
    }

    return 0;
}
