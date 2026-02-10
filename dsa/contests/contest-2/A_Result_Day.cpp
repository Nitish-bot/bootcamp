#include <iostream>
using namespace std;

int main() {
  int len;
  cin >> len;

  int m[len];
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  int passing = 0;
  cin >> passing;

  int pass = 0;
  int fail = 0;
  for (int i = 0; i < len; i ++) {
    if (m[i] < passing) {
      fail += 1;
    } else {
      pass += 1;
    }
  }

  cout << "Pass: " << pass;
  cout << endl;
  cout << "Fail: " << fail;
  cout << endl;
}