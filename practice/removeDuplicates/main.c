#include <stdio.h>
#include "removeDuplicates.c"

int nums[] = {0,0,1,1,1,2,2,3,3,3,3,4,5,5,6,7,7,7};
//int nums[] = {1,1,2};
size_t n = sizeof(nums)/sizeof(nums[0]);

int main() {
  printf("array: ");
  for (int i=0; i<n; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
  printf("n: %zd\n",n);
  printf("length returned: %d\n", removeDuplicates(nums, n));
  printf("array after function call:\n");
  for (int i=0; i<n; i++) {
    printf("%d ", nums[i]);
  }
  printf("\n");
}
