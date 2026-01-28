#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  if (n == 0) {
    cout << 1 << endl;
  } else {
    int zeros = 0;
    while (n > 0) {
      if (n % 10 == 0) {
        zeros += 1;
      }
      n /= 10;
    }
    cout << zeros << endl;
  }
}