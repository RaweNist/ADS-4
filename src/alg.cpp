// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int* arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len/2; ++i) {
    for (int j = len; j > i; --j) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
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
        int n1 = n;
        n++;
        while (arr[n] + x == value) {
          count++;
          n--;
        }
        while (arr[n1] + x == value) {
          count++;
          n1++;
        }
        break;
      }
      if (arr[n] + x < value) {
        l = n + 1;
      } else if (arr[n] + x > value) {
        r = n - 1;
      }
    } while (l <= r);
  }
  return count;
}
