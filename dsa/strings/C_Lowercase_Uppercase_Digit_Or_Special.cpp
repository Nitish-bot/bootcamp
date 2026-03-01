#include <iostream>
using namespace std;

int main() {
  char c;
  cin >> c;

  int ascii = (int)c;

  if (ascii > 47 && ascii <=57) {
    cout << "Digit";
  } else if (ascii > 64 && ascii <= 90) {
    cout << "Uppercase";
  } else if (ascii > 96 && ascii <= 122) {
    cout << "Lowercase";
  } else {
    cout << "Special";
  }
  cout << endl;
}