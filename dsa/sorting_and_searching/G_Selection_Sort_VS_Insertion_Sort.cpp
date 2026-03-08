#include <bits/stdc++.h>
using namespace std;

int insertion_sort(int n, int arr[]) {
  int shifts = 0;
  int sortil = 1;
  for (int i = 0; i < n; i++) {
    if (sortil == n) {
      break;
    }
    
    int to_insert = arr[sortil];
    int lookback = sortil - 1;
    while (lookback >= 0 && to_insert < arr[lookback]) {
      arr[lookback + 1] = arr[lookback];
      lookback--;
      shifts++;
    }
    arr[lookback + 1] = to_insert;
    sortil++;
  }

  return shifts;
}

int selection_sort(int n, int arr[]) {
  int swaps = 0;
  for (int i = 0; i < n - 1; i++) {
    // Find index of min value excluding the
    // indices already placed by starting at i
    int min = i;
    for (int j = i; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }

    if (min == i) {
      continue;
    }
    swaps++;

    // Swap min with current pass
    int buffer = arr[i];
    arr[i] = arr[min];
    arr[min] = buffer;
  }

  return swaps;
}

void solve() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  // Create copies since both sorts modify the array
  int arr1[n], arr2[n];
  for (int i = 0; i < n; i++) {
    arr1[i] = arr[i];
    arr2[i] = arr[i];
  }

  int shifts = insertion_sort(n, arr1);
  int swaps = selection_sort(n, arr2);

  if (shifts < swaps) {
    cout << "Insertion Sort";
  } else if (swaps < shifts) {
    cout << "Selection Sort";
  } else {
    cout << "Tie";
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