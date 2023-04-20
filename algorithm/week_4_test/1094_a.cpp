#include <bits/stdc++.h>
using namespace std;

int N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N;

  int cnt = 0;
  for (int i = 0; i <= 6; i++) {
    if (N & (1 << i)) cnt++;
  }

  cout << cnt << '\n';

  return 0;
}