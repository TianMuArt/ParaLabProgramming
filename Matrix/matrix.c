#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int generate_random_array(int **arr,int n);
int multipy_matrix(int **A, int **B, int **C, int rows);
int print_array(int **arr,int n);


int main()
{
    int rows, cols;
    int **arrA, **arrB, **arrC;
    clock_t start_time, end_time;
    double elapsed_time;


    printf("Enter amount of rows: ");
    scanf("%d", &rows);

    printf("Enter amount of columns: ");
    scanf("%d", &cols);

    if (rows != cols){
        printf("2D array is not suitable");
        exit(1);
    }

    int i, j;
    arrA = (int **)malloc(rows*sizeof(int*));
    arrB = (int **)malloc(rows*sizeof(int*));

    for (i = 0; i < rows; i++)
    {
        arrA[i] = (int*)malloc(cols * sizeof(int));
        arrB[i] = (int*)malloc(cols*sizeof(int));
    }

    generate_random_array(arrA,rows);
    generate_random_array(arrB,rows);

    //print_array(arrA,rows);
    //print_array(arrB,rows);

    arrC = (int**)malloc(rows*sizeof(int*));
    for (i = 0; i < rows; i++)
    {
        arrC[i] = (int*)malloc(cols * sizeof(int));
    }

    for(i=0;i<rows;i++){
        for(j=0;j<rows;j++){
            arrC[i][j] = 0;
        }
    }

    start_time = clock();
    multipy_matrix(arrA,arrB,arrC,rows);
    end_time = clock();

    elapsed_time = 1.0*((double)(end_time)-start_time)/CLOCKS_PER_SEC;

    //print_array(arrC,rows);
    printf("The amount of time: %.3lf seconds",elapsed_time);

    free(arrA);
    free(arrB);
    free(arrC);

    return 0;
}


int generate_random_array(int **arr,int n){
    int i,j;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
           //arr[i][j]= rand()%n;
           arr[i][j]=1;
        }
    }
    return 0;
}

int print_array(int **arr,int n){
    printf("The array is:\n");
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int multipy_matrix(int **A, int **B, int **C, int rows){
    int i, j, k;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < rows; j++)
        {
            for (k = 0; k < rows; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 0;
}
