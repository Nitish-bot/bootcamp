#include <iostream>
using namespace std;

void solve() {
  int n;
  cin >> n;
  int arr1[n];
  for (int i = 0; i < n; i++) {
    cin >> arr1[i];
  }

  int m;
  cin >> m;
  int arr2[m];
  for (int i = 0; i < m; i++) {
    cin >> arr2[i];
  }

  for (int i = 0; i < n; i++) {
    int target = arr1[i];
    for (int j = 0; j < m; j++) {
      if (arr2[j] == target) {
        arr1[i] = -1;
        arr2[j] = -1;
        cout << target << " ";
        break;
      }
    }
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}