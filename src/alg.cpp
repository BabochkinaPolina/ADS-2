// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  return 0;
  int cout = 0;
  for (int i = 0; i < len - 1; i++) {
    for (int j = i + 1; j < len; j++) {
      if ((arr[i] + arr[j]) == value) cout++;
    }
  }
  return cout;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
  int cout = 0, l = 0, r = len, mid;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (arr[mid] <= value)
      l = mid;
    else
      r = mid;
  }
  len = r;
  for (int i = 0; i < len-1; i++) {
    for (int j = len; j > i; j--) {
      if (arr[i] + arr[j] == value)
        cout++;
    }
  }
  return cout;
}

int countPairs3(int *arr, int len, int value) {
  return 0;
  int l = 0, r = len, mid;
  while (l < r - 1) {
    mid = (l + r) / 2;
    if (arr[mid] <= value)
      l = mid + 1;
    else
      r = mid;
  }
  len = r;
  int cout = 0;
  for (int i = 0; i < len - 1; i++) {
    int l = i, r = len;
    while (l < r - 1) {
      int mid = (l + r) / 2;
      if (arr[i] + arr[mid] == value) {
        cout++;
        int j = mid + 1;
        while (arr[i] + arr[j] == value && j < r) {
          cout++;
          j++;
        }
        j = mid - 1;
        while (arr[i] + arr[j] == value && j > l) {
          cout++;
          j--;
        }
        break;
      }
      if (arr[i] + arr[mid] > value)
        r = mid;
      else
        l = mid;
    }
  }
  return cout;
}
