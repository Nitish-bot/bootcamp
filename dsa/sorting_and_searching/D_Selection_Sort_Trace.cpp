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
    // Find index of min value excluding the
    // indices already placed by starting at i
    int min = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    // Swap min with current pass
    int buffer = arr[i];
    arr[i] = arr[min];
    arr[min] = buffer;
  
    // Print formatted
    cout << "Pass " << i + 1 << ": ";
    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << ", min_selected = ";
    cout << arr[i] << endl;
  }
}