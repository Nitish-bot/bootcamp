#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int sortil = 1;
  for (int i = 0; i < n; i++) {
    if (sortil == n) {
      break;
    }
    
    int shifts = 0;
    int to_insert = arr[sortil];
    int lookback = sortil - 1;
    while (lookback >= 0 && to_insert < arr[lookback]) {
      arr[lookback + 1] = arr[lookback];
      lookback--;
      shifts++;
    }
    arr[lookback + 1] = to_insert;
    sortil++;


    // Print output
    cout << "Pass " << i + 1 << ": ";

    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
    }
    cout << ", ";

    for (int j = 0; j < n; j++) {
      cout << arr[j] << " ";
      if (j == sortil - 1) {
        cout << "| ";
      }
    }
    cout << ", ";

    cout << "shifts = " << shifts << endl;
  }
}