#include <iostream>
using namespace std;

int main() {
  char c;
  cin >> c;

  int ascii = (int)c;

  if (ascii > 64 && ascii <= 90) {
    cout << (char)(ascii + 32);
  } else {
    cout << c;
  }
  cout << endl;
}