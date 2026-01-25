#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;

  for (int i = 1; i < 11; i++) {
    int res = a * i;
    cout << a << " * " << i << " = ";
    cout << to_string(res) << endl;
  }
}