#include <stdio.h>

int getMax(int array[], int n) {
  int max = array[0];
  int i;
  for (i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;
  int i;
  
  for (i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];

  for (i = 0; i < max; ++i)
    count[i] = 0;

  for (i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
    
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (i = 0; i < size; i++)
    array[i] = output[i];
}

void radixsort(int array[], int size) {
  int max = getMax(array, size);
  int place;
  for (place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main() {
  int n,i;
  printf("Enter size of array : ");
  scanf("%d",&n);
  
  int array[n];
  for(i=0;i<n;i++)
  	scanf("%d",&array[i]);
  
  radixsort(array, n);
  printf("Sorted array : ");
  printArray(array, n);
}
