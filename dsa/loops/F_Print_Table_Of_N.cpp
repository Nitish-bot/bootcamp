#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;

  for (int i = 1; i < 11; i++) {
    cout << a << " * " << i << " = ";
    cout << a * i << endl;
  }
}