#include <iostream>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  int digit_a = a % 10;
  int digit_b = b % 10;

  cout << digit_a + digit_b << endl;
}