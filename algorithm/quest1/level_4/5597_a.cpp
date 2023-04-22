#include <bits/stdc++.h>
using namespace std;

int a[30], idx;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 28; i++) {
    cin >> idx;
    a[idx] = 1;
  }

  for (int i = 1; i <= 30; i++) {
    if (!a[i]) cout << i << '\n';
  }
  
  return 0;
}