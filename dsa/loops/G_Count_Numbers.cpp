#include <iostream>
using namespace std;

int main() {
  int a;
  cin >> a;

  int input;
  int pos = 0, neg = 0, eve = 0, odd = 0;
  for (int i = 0; i < a; i++) {
    cin >> input;

    if (input % 2 == 0) {
      eve += 1;
    } else {
      odd += 1;
    }

    if (input > 0) {
      pos += 1;
    } else if (input < 0) {
      neg += 1;
    }
  }

  cout << pos << endl;
  cout << neg << endl;
  cout << eve << endl;
  cout << odd << endl;
}