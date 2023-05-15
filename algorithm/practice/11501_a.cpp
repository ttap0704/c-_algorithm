#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll T, N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;

    ll n, ret = 0;
    vector<ll> v;
    for (int i = 0; i < N; i++) cin >> n, v.push_back(n);

    ll cell = 0;
    for (int i = N - 1; i >= 0; i--) {
      if (cell <= v[i]) {
        cell = v[i];
      } else {
        ret += cell;
        ret -= v[i];
      }
    }

    cout << ret << '\n';
  }

  return 0;
}