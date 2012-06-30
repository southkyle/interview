#include <iostream>
#include <cassert>
using namespace std;

void Swap(int* a, int* b) {
  assert(a != NULL && b != NULL);
  int temp = *a;
  *a = *b;
  *b = temp;
}

void QuickSort1(int array[], int left, int right) {
  if (left >= right) {
    return;
  }

  int pivot = array[left];

  int i = left;          // important here
  int j = right + 1;     // important here
  while (true) {
    while (++i < j && array[i] < pivot) {}  // important here
    while (array[--j] > pivot) {}
    if (i < j) {
      Swap(&array[i], &array[j]);
    } else {
      break;
    }
  }

  Swap(&array[j], &array[left]);
  QuickSort1(array, left, j - 1);   // important here
  QuickSort1(array, j + 1, right);
}

const int kCutOff = 3;

int MedianOfArray(int array[], int left, int right) {
  int mid = left + (right - left) / 2;
  if (array[left] > array[mid]) {
    Swap(&array[left], &array[mid]);
  }
  
  if (array[mid] > array[right]) {
    Swap(&array[mid], &array[right]);
  }
  
  if (array[left] > array[mid]) {
    Swap(&array[left], &array[mid]);
  }
  
  Swap(&array[mid], &array[right - 1]);
  return array[right - 1];
}

void QuickSort2(int array[], int left, int right) {
  if (right - left <= kCutOff) {
    // Insertion Sort
    return;
  }

  int pivot = MedianOfArray(array, left, right);
  int i = left;
  int j = right - 1;
  while (true) {
    while (array[++i] < pivot) {}
    while (array[--j] > pivot) {}
    if (i < j) {
      Swap(&array[i], &array[j]);
    } else {
      break;
    }
  }

  QuickSort2(array, left, i - 1);
  QuickSort2(array, i + 1, right);
}

void MergeSort(int array[], int left, int right) {
  if (left >= right) return;

  int mid = (left + right) / 2;
  MergeSort(array, left, mid);
  MergeSort(array, mid, right);
  Merge(array, temp_array, left, mid, right);
}

void Merge(int in[], int out[], int left, int mid, int right) {
  int i = left;
  int left_end = mid;
  int j = left_end + 1;
  int right_end = right;
  int k = left;
  while (i <= left_end && j <= right_end) {
    if (array[i] <= array[j]) {
      out[k] = array[i];
      k++;
      i++;
    } else {
      out[k] = array[j];
      k++;
      j++;
    }
  }

  while (i <= left_end) {
    out[k] = in[i];
    k++;
    i++;
  }
  while (j <= right_end) {
    out[k] = in[j];
    k++;
    j++;
  }

  for (i = left; i <= right; i++) {
    array[i] = out[i];
  }
}

void GoodMerge(int array[], int tmp_array[], int lpos, int rpos, int right_end) {
  int left_end = rpos - 1;
  int tmp_pos = lpos;
  while (lpos <= left_end && rpos <= right_end) {
    if (array[lpos] <= array[rpos]) {
      tmp_array[tmp_pos++] = array[lpos++];
    } else {
      tmp_array[tmp_pos++] = array[rpos++];
    }
  }
  
  while (lpos <= left_end) {
    tmp_array[tmp_pos++] = array[lpos++];
  }
  
  while (rpos <= right_end) {
    tmp_array[tmp_pos++] = array[rpos++];
  }

  for (int i = 0; i < right_end - lpos + 1; i++, right_end--) {
    array[right_end] = tmp_array[right_end];
  }
}


bool CheckSort(int array[], size_t n) {
  if (n == 0) {
    return true;
  }
  
  for (size_t i =0; i < n - 2; i++) {
    if (array[i] > array[i+1]) {
      return false;
    }
  }
  return true;
}

#define arraysize(a) (sizeof(a)/sizeof(a[0]))
int main(int argc, char *argv[]) {
  int array0[] = {};
  int array1[] = {8, 9, 10, 11, 12};
  int array2[] = {12, 10, 9, 8, 7, 6};
  int array3[] = {3, 4, 8, 0, 1, 2, 5};

  QuickSort1(array0, 0, arraysize(array0));
  QuickSort1(array1, 0, arraysize(array1));
  QuickSort1(array2, 0, arraysize(array2));
  QuickSort1(array3, 0, arraysize(array3));

  assert(CheckSort(array0, arraysize(array0)));
  assert(CheckSort(array1, arraysize(array1)));
  assert(CheckSort(array2, arraysize(array2)));
  assert(CheckSort(array3, arraysize(array3)));
  return 0;
}

