#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (int i = 1; i < n + 1; i++) {
    if (i % 3 == 0) {
      if (i % 5 == 0) {
        cout << "FizzBuzz";
      } else {
        cout << "Fizz";
      }
    } else if (i % 5 == 0) {
      cout << "Buzz";
    } else {
      cout << i;
    }

    cout << endl;
  }
}