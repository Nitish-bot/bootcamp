#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int good = 0;
  int checker;
  for (int i = 0; i < n; i++) {
    cin >> checker;
    if (checker % 45 == 0 || 18 % checker == 0) {
      good += 1;
    }
  }

  cout << good << endl;
}