#include <bits/stdc++.h>
using namespace std;

bool check[10001];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  for (int i = 1; i <= 10000; i++) {
    string n = to_string(i);
    int m = i;

    for (char c : n) {
      m += c - '0';
    }
    if (m > 10000) continue;
    check[m] = true;
  }

  for (int i = 1; i <= 10000; i++) {
    if (!check[i]) cout << i << '\n';
  }

  return 0;
}