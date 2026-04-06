// Copyright 2021 NNTU-CS
#include "alg.h"

int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j)
      if (arr[i] + arr[j] == value) {
        count++;
        while (j + 1 < len && arr[j] == arr[j+1]) {
          j++;
        }
      }
    while (i + 1 < len && arr[i] == arr[i + 1]) {
      i++;
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = len; j > i; --j)
      if (arr[i] + arr[j] == value) {
        count++;
        while (arr[j] == arr[j - 1] && j > i) {
          j--;
        }
      }
    while (i + 1 < len && arr[i] == arr[i + 1]) {
      i++;
    }
  }
}
int countPairs3(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    int x = arr[i];
    int l = i + 1;
    int r = len - 1;
    do {
      int n = (l + r) / 2;
      if (arr[n] + x == value) {
        count++;
        int a = n - 1;
        if (a >= l) {
          while (arr[a] == arr[n]) {
            a--;
          }
        }
        int b = n + 1;
        if (b <= r) {
          while (arr[b] == arr[n]) {
            b++;
          }
        }
        break;
      } else if (arr[n] + x < value) {
        l = n + 1;
      } else {
        r = n - 1;
      }
    } while (l <= r);
    while (i + 1 < len && arr[i] == arr[i + 1]) {
      i++;
    }
  }
  return count;
}
