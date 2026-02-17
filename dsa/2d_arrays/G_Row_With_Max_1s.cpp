#include <iostream>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  int arr[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
    }
  }

  int index = -1;
  int max_occurences = 0;
  for (int i = 0; i < n; i++) {
    int occurences = 0;
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 1) {
        occurences++;
      }
    }
    if (occurences > max_occurences) {
      index = i;
      max_occurences = occurences;
    }
  }
  cout << index << endl;
}