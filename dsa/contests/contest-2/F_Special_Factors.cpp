#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> facs;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) {
      if (i % 10 == 2 || i % 10 == 7) {
        facs.push_back(i);
      }
    }
  }

  int len = facs.size();
  if (len == 0) {
    cout << -1;
  } else {
    for (int i = 0; i < len; i++) {
      cout << facs[i] << " ";
    }
  }
  cout << endl;
}