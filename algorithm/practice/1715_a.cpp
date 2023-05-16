#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, n, ret;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> n, pq.push(n);

  while (pq.size() >= 2) {
    ll i1 = pq.top(); pq.pop();
    ll i2 = pq.top(); pq.pop();

    ret += i1 + i2;

    pq.push(i1 + i2);
  }

  cout << ret << '\n';

  return 0;
}