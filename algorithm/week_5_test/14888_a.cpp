#include <bits/stdc++.h>
using namespace std;

int N, a[12], calc_arr[4], mn = 1e9, mx = -1e9;

int calcValue (int idx, int a, int b) {
  if (idx == 0) return a + b;
  else if (idx == 1) return a - b;
  else if (idx == 2) return a * b;
  else return a / b;
}

void go (int idx, int val) {
  if (idx >= N - 1) {
    mn = min(mn, val);
    mx = max(mx, val);
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (calc_arr[i] == 0) continue;

    calc_arr[i]--;
    go(idx + 1, calcValue(i, val, a[idx + 1]));
    calc_arr[i]++;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];
  for (int i = 0; i < 4; i++) cin >> calc_arr[i];

  go(0, a[0]);

  cout << mx << '\n';
  cout << mn << '\n';
  
  return 0;
}