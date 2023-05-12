#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll N, sum, max_cnt, mx = -1e18, mn = 4001, a[500004];
vector<ll> cnt[500004];
map<ll, ll> cnt_arr;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    sum += a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);

    cnt_arr[a[i]]++;
    cnt[cnt_arr[a[i]]].push_back(a[i]);
    max_cnt = max(max_cnt, cnt_arr[a[i]]);
  }

  sort(a, a + N);
  
  ll avg = round((double) sum / (double) N), mid = N / 2;
  cout << avg << '\n';
  cout << a[mid] << '\n';
  // cout << "test: " << mid << '\n';
  if (cnt[max_cnt].size() == 1) {
    cout << cnt[max_cnt][0] << '\n';
  } else {
    sort(cnt[max_cnt].begin(), cnt[max_cnt].end());
    cout << cnt[max_cnt][1] << '\n';
  }
  cout << mx - mn << '\n';

  return 0;
}