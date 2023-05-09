#include <bits/stdc++.h>
using namespace std;

int N, a[1004], cnt[1004], ret = -1e9;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < N; i++) {
    int max_val = 0;
    for (int j = 0; j < N; j++) {
      if (a[j] < a[i] && max_val < cnt[j]) max_val = cnt[j];
    }
    cnt[i] = max_val + 1;
    ret = max(ret, cnt[i]);
  }

  cout << ret << '\n';
  
  return 0;
}