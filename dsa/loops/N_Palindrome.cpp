#include <iostream>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long original = n;
  long long reverse = 0;
  while (n != 0) {
    reverse *= 10;
    reverse += n % 10;
    n /= 10;
  }

  if (original == reverse) {
    cout << "YES";
  } else {
    cout << "NO";
  }

  cout << endl;
}