#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, M, n, ret;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> n, pq.push(n);

  while (M--) {
    ll num1 = pq.top(); pq.pop();
    ll num2 = pq.top(); pq.pop();

    ll sum = num1 + num2;
    
    pq.push(sum);
    pq.push(sum);
  }

  while (pq.size()) {
    ret += pq.top();
    pq.pop();
  }

  cout << ret << '\n';

  return 0;
}