/* The function below iterates from 0 to n.
   It also iterates from i to n when it has to shifts elements left.
   As such, this function's complexity is somewhere between O(n) and O(n^2).
   There is a better way to do this (below).
   I put this alternative (worse) way of doing it above so that it is
   overwritten by the function definition below.
   */
int removeDuplicates(int *nums, int numsSize) {
  // Special case, numSize = 0
  if (numsSize == 0) return 0;

  int length = 1;

  // Inspect each element in the array
  // (since we compare nums[i] to nums[i+1], we only need to iterate until
  // we are at the second to last element) 
  for (int i=0; i<numsSize-1; i++) {

    // If current element is equal to next element
    if (nums[i] == nums[i+1]) {

      /* Then, "overwrite" current element by shifting all elements to the 
        right of the current element LEFT one position. */
      for (int j=i; j<numsSize-1; j++) {
        nums[j] = nums[j+1];
      }
      /* Due to shifting all elements which are to the right of the current
         element LEFT one position, we have essentially "removed" the current
         element. Because of this, we need to decrease our "i" counter
         because we now need to check the same position again. We also need
         to decrease the "size" of the array by one, since we have "removed"
         an element. */
      i--; numsSize--;

    /* Because we know the array is sorted, if the adjacent elements are not
     * equal, the only other option is that the current element is less than
     * the next element. In this case, we are not removing a duplicate, and
     * we should increment our counter to indicate that we have another
       unique element. */
    } else {
      length++;
    }
  }
  return length;
}

int removeDuplicates(int *nums, int numsSize) {
  if (numsSize == 0) return 0;

  /* We will add each unique element (but not any duplicates).
   * The variable, a, the "index at which to add new unique element",
   * starts at 1 because we eliminated the case of an empty list above. 
   * a will also serve as the length value which is returned by the function.
   */
  int a = 1;

  for (int i=1; i<numsSize; i++) {

    if (nums[i] > nums[i-1]) {
      nums[a] = nums[i];
      a++;
    } else if (nums[i] == nums[i-1]) {
      ; // equivalent to python's "pass"
    } else {
      ;
      // should never get here...
    }
  }  
  return a;
}


// This is close to the function above but without print statements and the
// logic structure slightly re-arranged and simplified.
int removeDuplicatesAttemptTwo(int *nums, int numsSize) {
  int length = 0;

  for (int i=0; i<numsSize-1; i++) {
    printf("i: %d, ", i);
    printf("nums[i]: %d, ", nums[i]);
    printf("nums[i+1]: %d\n", nums[i+1]);

    if (nums[i] == nums[i+1]) {

      printf("Shifting...\n");
      for (int j=i; j<numsSize-1; j++) {
        nums[j] = nums[j+1];
      }
    }

    if (nums[i] < nums[i+1]) {
      length++;
      printf("Length: %d\n", length);
    }
    else {
      i--; numsSize--;
    }

    printf("array: ");
    for (int i=0; i<numsSize; i++) {
      printf("%d ", nums[i]);
    }
    printf("\n\n");
  }
}

/* Eventually I abandoned this attempt after realizing I was doing
 * unnecessary things (e.g. storing the current element in a variable).
 * This function worked for the initial test case, but then failed for others.
*/
int removeDuplicatesAttemptOne(int* nums, int numsSize) {
  int curValue = nums[0];
  int length = 1;
  printf("size: %d\n", numsSize);
  
  for (int i=0; i<numsSize; i++) {
    printf("i: %d, ", i);
    printf("cur: %d, ", curValue);
    printf("nums[i]: %d\n", nums[i]);
    
    /* If next element is greater than current value we are checking...
       set a new current value
      (this may occur immediately after shifting) */
    if (curValue < nums[i]) {
      printf("New Current Value: %d\n", nums[i]);
      curValue = nums[i];
      length++;
    }

    // If duplicate, shift elements left
    else if (curValue == nums[i]) {
      printf("Shifting...\n");
      for (int j=i; j<numsSize-1; j++) {
        nums[j] = nums[j+1];
      }
    }

    printf("array: ");
    for (int i=0; i<numsSize; i++) {
      printf("%d ", nums[i]);
    }
    printf("\n");
    printf("len: %d\n\n", length);
  }
  return length;
}
