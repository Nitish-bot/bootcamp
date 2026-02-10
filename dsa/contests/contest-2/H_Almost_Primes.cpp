#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> almp;
  almp.push_back(1);
  for (int i = 2; i <= n; i++) {
    int facs = 1;
    for (int j = 2; j <= i; j++) {
      if (i % j == 0) {
        facs += 1;
      }
    }
    if (facs <= 4) {
      almp.push_back(i);
    }
  }

  for (int i = 0; i < almp.size(); i++) {
    cout << almp[i] << " ";
  }
  cout << endl;
}