#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;

  if (a > 90) {
    cout << "Excellent";
  } else if (a > 80) {
    cout << "Good";
  } else if (a > 70) {
    cout << "Fair";
  } else if (a > 60) {
    cout << "Meets Expectations";
  } else {
    cout << "Below Par";
  }
  cout << endl;
}