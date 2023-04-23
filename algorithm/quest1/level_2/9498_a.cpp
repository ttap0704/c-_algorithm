#include <bits/stdc++.h>
using namespace std;

int A;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A;

  if (100 >= A && A >= 90) {
    cout << 'A' << '\n';
  } else if (89 >= A && A >= 80) {
    cout << 'B' << '\n';
  } else if (79 >= A && A >= 70) {
    cout << 'C' << '\n';
  } else if (69 >= A && A >= 60) {
    cout << 'D' << '\n';
  } else {
    cout << 'F' << '\n';
  }
  return 0;
}