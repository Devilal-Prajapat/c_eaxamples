#include <stdio.h>

#define ROWS     2
#define COLS     2

int main()
{ 
    int i, j, mat[ROWS][COLS], mat1[COLS][ROWS];
    for(i = 0; i<ROWS; i++)
    {
        printf("Enter %d Row elements\r\n", i);
        for(j = 0; j<COLS; j++)
        {
            scanf("%d", &mat[i][j]);
            mat1[j][i] = mat[i][j];
        }
    }
    printf("Transpose Matrix\r\n");
    for(i = 0; i<COLS; i++)
    {
        for(j = 0; j<ROWS; j++)
        {
          printf(" %d",mat1[i][j]);
        }
        printf("\r\n");
    }
    return 0;
}
