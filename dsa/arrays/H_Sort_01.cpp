#include <iostream>
using namespace std;

void input_sort_output() {
  int len;
  cin >> len;

  int arr[len];
  int freq_0= 0, freq_1 = 0;
  for (int i = 0; i < len; i++) {
    cin >> arr[i];
    if (arr[i] == 0) {
      freq_0++;
    } else {
      freq_1++;
    }
  }

  for (int i = 0; i < freq_0; i++) {
    cout << 0 << " ";
  }
  for (int i = 0; i < freq_1; i++) {
    cout << 1 << " ";
  }
  cout << endl;
}

int main () {
  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    input_sort_output();
  }
}