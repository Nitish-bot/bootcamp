#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n - 1; i++) {
    int swaps = 0;
    for (int j = 0; j < n - 1; j++) {
      int curr = arr[j];
      int next = arr[j + 1];

      if (curr > next) {
        arr[j] = next;
        arr[j + 1] = curr;
        swaps++;
      }
    }

    cout << "Pass " << i + 1 << ": ";
    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << ", swaps = " << swaps << endl;

    if (swaps == 0) {
      break;
    }
  }
}