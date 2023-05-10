// 무조건 복습 필요
#include <bits/stdc++.h>
#define max_n 60000000004
using namespace std;

typedef long long ll;
ll N, M, a[10004], ret, lo, hi = max_n, mid, tmp;

bool check (ll mid) {
  tmp = M;
  for (ll i = 0; i < M; i++) tmp += mid / a[i];
  return tmp >= N;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < M; i++) cin >> a[i];
  if (N <= M) {
    cout << N << '\n';
    return 0;
  }

  while (lo <= hi) {
    mid = (lo + hi) / 2;
    if (check(mid)) {
      ret = mid;
      hi = mid - 1;
    } else lo = mid + 1;
  }

  tmp = M;
  for (ll i = 0; i < M; i++) tmp += ((ret - 1) / a[i]);

  for (ll i = 0; i < M; i++) {
    if (ret % a[i] == 0) tmp++;
    if (tmp == N) {
      cout << i + 1 << '\n';
      return 0;
    }
  }

  return 0;
}