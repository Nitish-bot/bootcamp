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
  int triplets = 0;
  for (int i = 0; i < n - 2; i++) {
    for (int j = i + 1; j < n - 1; j++) {
      for (int k = j + 1; k < n; k++) {
        if (arr[i] + arr[j] + arr[k] == x) {
          triplets++;
        }
      }
    }
  }

  cout << triplets << endl;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    solve();
  }
}