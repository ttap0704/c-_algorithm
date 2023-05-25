#include <bits/stdc++.h>
using namespace std;

int N, a[1004], cnt[1004], ret = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(cnt, cnt + 1004, 1);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> a[i];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      if (a[i] < a[j] && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
      }
    }

    // cout << "cnt : " << cnt[i] << '\n';
    ret = max(ret, cnt[i]);
  }

  cout << ret << '\n';

  return 0;
}