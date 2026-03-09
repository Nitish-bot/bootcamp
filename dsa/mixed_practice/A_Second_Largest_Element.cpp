#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int largest = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > arr[largest]) {
      largest = i;
    }
  }

  int second_largest = -1;
  for (int i = 0; i < n; i++) {
    if (arr[i] < arr[largest] && arr[i] > second_largest) {
      second_largest = arr[i];
    }
  }

  cout << second_largest << endl;
}