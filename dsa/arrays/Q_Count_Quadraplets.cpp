#include <iostream>
using namespace std;

void solve() {
  // Inputs
  int n, x;
  cin >> n >> x;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Processing
  int quadraplets = 0;
  for (int i = 0; i < n - 3; i++) {
    for (int j = i + 1; j < n - 2; j++) {
      for (int k = j + 1; k < n - 1; k++) {
        for (int l = k + 1; l < n; l++){
          int a = arr[i];
          int b = arr[j];
          int c = arr[k];
          int d = arr[l];
          int condition = a - 2 * b + 3 * c - 4 * d;
          if (condition == x) {
            quadraplets++;
          }
        }
      }
    }
  }

  cout << quadraplets << endl;
}

int main() {
  // int t;
  // cin >> t;

  int t = 1;
  for (int i = 0; i < t; i++) {
    solve();
  }
}