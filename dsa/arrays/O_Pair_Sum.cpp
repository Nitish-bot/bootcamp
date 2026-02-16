#include <iostream>
using namespace std;

void solve() {
  // Inputs
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int x;
  cin >> x;

  // Processing
  int pairs = 0;
  for (int i = 0; i < n; i++) {
    int target = x - arr[i];
    for (int j = i; j < n; j++) {
      if (arr[j] == target && i != j) {
        pairs++;
      }
    }
  }

  cout << pairs << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}