#include <bits/stdc++.h>
using namespace std;

int K, N, mx, ret;
long long lines[10004];

bool check (int mid) {
  long long sum = 0;
  for (int i = K - 1; i >= 0; i--) {
    sum += (lines[i] / mid);
    if (sum >= N) {
      return true;
    }
  }

  return false;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> K >> N;
  for (int i = 0; i < K; i++) {
    cin >> lines[i];
    if (mx < lines[i]) mx = lines[i];
  }
  sort(lines, lines + K);

  long long l = 1, r = mx, mid;
  while (l <= r) {
    mid = (l + r) / 2;

    bool check_cut = check(mid);
    if (check_cut) {
      if (ret < mid) ret = mid;
      l = mid + 1;
    } else r = mid - 1;
  }

  cout << ret << '\n';

  return 0;
}