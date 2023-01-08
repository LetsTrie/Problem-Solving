// Use-of: Binary Search
// 1. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/A
// 2. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/B
// 3. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/C
// 4. https://codeforces.com/edu/course/2/lesson/6/1/practice/contest/283911/problem/D

int binarySearch(int array[], int arraySize, int target) {
  int low = 0;
  int high = arraySize - 1;
  int index = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] == target) index = mid;
    else if (array[mid] < target) low = mid + 1;
    else high = mid - 1;
    
    if (array[mid] == target) break;
  }

  return index;
}

// Key-point: Maximum index of an array element not greater than the target!
int closestToLeft(int array[], int arraySize, int target) {
  int low = 0;
  int high = arraySize - 1;
  int index = -1;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] <= target) {
      index = mid;
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return index;
}

// Key-point: Minimum index of an array element not less than the target!
int closestToRight(int array[], int arraySize, int target) {
  int low = 0;
  int high = arraySize - 1;
  int index = arraySize;

  while (low <= high) {
    int mid = low + (high - low) / 2;
    if (array[mid] >= target) {
      index = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  return index + 1;
}
