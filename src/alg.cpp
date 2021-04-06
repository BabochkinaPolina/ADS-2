// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  return 0;
int pairs = 0;
  for (int a = 0; a < len - 1; a++)
    for (int b = a + 1; b < len; b++)
      if (arr[a] + arr[b] == value)
        pairs++;
  return pairs;
}

int countPairs2(int *arr, int len, int value) {
  return 0;
int pairs = 0, l = 0, r = len-1;
while(l < r - 1) {
int middle = (r + l)/2;
if (arr[middle] <= value)
l = middle;
else
r = middle;
}
len = r - 1;
for (int a = len; a >= 0; a--) {
for (int b = 0; b < a; b++) {
if (arr[a] + arr[b] == value)
pairs++;
if (arr[a] + arr[b] > value)
break;
}
}
return pairs;  
}

int countPairs3(int *arr, int len, int value) {
  return 0;
int pairs = 0;
  for (int a = 0; a < len - 1; a++) {
  int l = a, r = len;
    while (l < r-1) {
    int middle = (l + r) / 2;
      if (arr[a] + arr[middle] == value) {
      pairs++;
      int b = middle+1;
        while (arr[a] + arr[b] == value && b <r) {
        pairs++;
        b++;
        }
      b = middle - 1;
          while (arr[a] + arr[b] == value && b > l) {
          pairs++;
          b--;
          }
       break;
       }
          if (arr[a] + arr[middle] > value)
          r = middle;
          else
          l = middle;
     }
  }
return pairs;  
}
