#include <stdio.h>
#include <stdlib.h>

int binarySearch(int array[], int x, int low, int high) {
  
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (array[mid] == x)
      return mid;

    if (array[mid] < x)
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}

int main(void) {
  int n, x;

  
  printf("Enter the number of elements: ");
  scanf("%d", &n);

  
  int *array = (int*)malloc(n * sizeof(int));

  
  printf("Enter %d elements in sorted order: ", n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &array[i]);
  }

  
  printf("Enter the element to search for: ");
  scanf("%d", &x);

  
  int result = binarySearch(array, x, 0, n - 1);
  
  if (result == -1)
    printf("Not found\n");
  else
    printf("Element is found at index %d\n", result);


  free(array);

  return 0;
}

