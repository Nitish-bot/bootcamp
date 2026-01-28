#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int to_print;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      to_print = 0;
    } else {
      to_print = 1;
    }

    for (int j = 0; j < i + 1; j++) {
      cout << to_print;
      to_print = 1 - to_print;
    }
    cout << endl;
  }
}