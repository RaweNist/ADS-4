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
        int a = n - 1;
        int b = n + 1;
        while (arr[a] == arr[n] && a >= l) {
          count++;
          a--;
        }
        while (arr[b] == arr[n] && b <= r) {
          count++;
          b++;
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
