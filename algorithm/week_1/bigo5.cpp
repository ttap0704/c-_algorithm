#include <bits/stdc++.h>
using namespace std;

int N, cnt, forcnt;

void solve (int N) {
  cnt++;
  // cout << cnt << "\n";
  if (N == 0) return;
  for (int i = 0; i < 3; i++) {
    forcnt++;
    solve(N - 1);
  }
  return;
}

int main () {
  cin >> N;
  solve(N);
  cout << cnt << "\n";
  return 0;
}