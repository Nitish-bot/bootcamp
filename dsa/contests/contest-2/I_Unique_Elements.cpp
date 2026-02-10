#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int len;
  cin >> len;

  vector<int> m(len);
  for (int i = 0; i < len; i++) {
    cin >> m[i];
  }

  vector<int> unique;
  for (int i = 0; i < len; i++) {
    int number = m[i];
    int c = count(m.begin(), m.end(), number);
    if (c == 1) {
      unique.push_back(number);
    }
  }

  for (int i = 0; i < unique.size(); i++) {
    cout << unique[i] << " ";
  }
  cout << endl;
}