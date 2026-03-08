#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int x;
  cin >> x;

  int l = 0;
  int r = n - 1;
  bool found = false;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (arr[mid] > x) {
      r = mid - 1;
    } else if (arr[mid] < x) {
      l = mid + 1;
    } else {
      found = true;
      break;
    }
  }

  if (found) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}