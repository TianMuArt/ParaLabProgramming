#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>


int bubbleSorting(int arr[], int n) {
  int i, j, temp;
  for (i = 0; i < n-1; i++) {       
    for (j = 0; j < n-i-1; j++) {  
      if (arr[j] > arr[j+1]) {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = temp;
      }
    }
  }
  return 0;
}


int shellSorting(int arr[], int n) {
  int gap, i, j, temp;
  for (gap = n/2; gap > 0; gap /= 2) {
    for (i = gap; i < n; i++) {
      temp = arr[i];
      for (j = i; j >= gap && arr[j-gap] > temp; j -= gap) {
        arr[j] = arr[j-gap];
      }
      arr[j] = temp;
    }
  }
  return 0;
}

void quickSort(int arr[], int low_border, int high_border) {
  int i, j, pivot, temp;
  if (low_border < high_border) {
    pivot = low_border;
    i = low_border;
    j = high_border;
    while (i < j) {
      while (arr[i] <= arr[pivot] && i < high_border) {
        i++;
      }
      while (arr[j] > arr[pivot]) {
        j--;
      }
      if (i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
    temp = arr[pivot];
    arr[pivot] = arr[j];
    arr[j] = temp;
    quickSort(arr, low_border, j-1);
    quickSort(arr, j+1, high_border);
  }
}


void print_array(int arr[], int n){
    int i = 0;
    for(i=0;i<n;i++){
        printf(" %d",arr[i]);
    }
    printf("\n");
}

int generate_random(int arr[], int size_of_array){
  srand(time(NULL));
  for (int i = 0; i < size_of_array; i++) {
        arr[i] = rand() % size_of_array;
  }
  return 0;
}


int main(){
    srand(time(NULL));
    int size_of_array = 0;
    clock_t start_time, end_time;
    double elapsed_time;


    printf("Enter array size: ");
    scanf("%d",&size_of_array);
    
    int *array = (int*)malloc(sizeof(int)*size_of_array);
    
    generate_random(array,size_of_array);

    start_time = clock();
    quickSort(array,0,size_of_array-1);
    end_time = clock();
    elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Amount of elements: %d",size_of_array);
    printf("\n_______________________________________________________");
    printf("\nQuicksort Sorting time: %.7f seconds\n", elapsed_time);

    generate_random(array,size_of_array);

    start_time = clock();
    bubbleSorting(array,size_of_array);
    end_time = clock();

    elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nBubble sort sorting time: %.7f seconds\n", elapsed_time);

    generate_random(array,size_of_array);

    start_time = clock();
    shellSorting(array,size_of_array);
    end_time = clock();

    elapsed_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nShell sort sorting time: %.7f seconds\n", elapsed_time);


    printf("_______________________________________________________");
    free(array);

    return 0;
}




