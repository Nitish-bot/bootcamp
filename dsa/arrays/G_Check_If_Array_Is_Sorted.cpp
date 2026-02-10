#include <bits/stdc++.h>
using namespace std;

bool isSorted(int n[], int length) {
  if (length < 2) {
    return true;
  }
  for (int i = 0; i < length - 1; i++) {
    if (n[i] > n[i + 1]) {
      return false;
    }
  }
  return true;
}

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  if (isSorted(m, len)) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  cout << endl;
}