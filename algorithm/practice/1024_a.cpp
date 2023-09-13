#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, L;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L;

  ll start, end;
  while (L <= 100) {
    ll mid = N / L;

    if (mid - L + 1 < 0) {
      start = 0;
      end = mid + abs(mid - L + 1);
    } else {
      start = mid - L + 1 < 0 ? 0 : mid - L + 1;
      end = mid;
    }

    ll tmp = (start + end) * L / 2;

    while (tmp < N) {
      tmp -= start;
      start++;

      end++;
      tmp += end;
    }

    if (tmp != N) L++;
    else if (tmp == N) break;
  }

  if (L <= 100) {
    for (int i = start; i <= end; i++) {
      cout << i << ' ';
    }
    cout << '\n';
  } else {
    cout << -1 << '\n';
  }

  return 0;
}