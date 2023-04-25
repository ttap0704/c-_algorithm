#include <bits/stdc++.h>
using namespace std;

int a, b, c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;

  if (a == 60 && b == 60 && c == 60) {
    cout << "Equilateral" << '\n';
  } else if ((a + b + c) == 180) {
    if (a == b || a == c || b == c) {
      cout << "Isosceles" << '\n';
    } else {
      cout << "Scalene" << '\n';
    } 
  } else {
    cout << "Error" << '\n';
  }

  return 0;
}