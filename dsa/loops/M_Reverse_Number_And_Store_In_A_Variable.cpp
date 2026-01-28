#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long var = 0;
  while (n != 0) {
    var *= 10;
    var += n % 10;
    n /= 10;
  }

  cout << var << endl;
}