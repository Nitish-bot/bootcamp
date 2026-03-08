#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  int arr1[m];
  for (int i = 0; i < m; i++) {
    cin >> arr1[i];
  }

  int arr2[n];
  for (int i = 0; i < n; i++) {
    cin >> arr2[i];
  }

  int total_len = m + n;
  int fin[total_len];
  int pointer1 = 0;
  int pointer2 = 0;
  while (pointer1 < m || pointer2 < n) {
    int idx = pointer1 + pointer2;
    if (pointer2 == n) {
      fin[idx] = arr1[pointer1];
      pointer1++;
    } else if (pointer1 == m) {
      fin[idx] = arr2[pointer2];
      pointer2++;
    } else {
      int f1 = arr1[pointer1];
      int f2 = arr2[pointer2];
      if (f1 <= f2) {
        fin[idx] = f1;
        pointer1++;
      } else {
        fin[idx] = f2;
        pointer2++;
      }
    }
  }

  for (int i = 0; i < total_len; i++) {
    cout << fin[i] << " ";
  }
  cout << endl;
}