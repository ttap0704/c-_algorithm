#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, K, m, v, c, ret;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  vector<pair<ll, ll>> arr(N);
  vector<ll> arr2(K);
  for (int i = 0; i < N; i++) {
    cin >> arr[i].first >> arr[i].second;
  }
  sort(arr.begin(), arr.end());

  for (int i = 0; i < K; i++) {
    cin >> arr2[i];
  }
  sort(arr2.begin(), arr2.end());

  priority_queue<ll> pq;

  ll j = 0;
  for (ll i = 0; i < K; i++) {
    while (j < arr.size() && arr[j].first <= arr2[i]) {
      pq.push(arr[j].second);
      j++;
    }

    if (pq.size()) {
      ret += pq.top();
      pq.pop();
    }
  }

  cout << ret << '\n';

  return 0;
}