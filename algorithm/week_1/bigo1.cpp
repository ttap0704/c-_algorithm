#include <bits/stdc++.h>
using namespace std;

int n;
int main() {
  cin >> n;
  int a = 0;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      a += i + j;
      cnt++;
    }
  }

  cout << a << "\n";
  cout << cnt << "\n";
  return 0;
}