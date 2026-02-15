#include <iostream>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  int m[n];
  int freq = 0;
  for (int i = 0; i < n; i++) {
    cin >> m[i];
    if (m[i] == x) {
      freq++;
    }
  }
  cout << freq << endl;
}