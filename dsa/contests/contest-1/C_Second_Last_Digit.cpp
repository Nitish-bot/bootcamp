#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  n /= 10;
  int res = n % 10;
  cout << res << endl;
}