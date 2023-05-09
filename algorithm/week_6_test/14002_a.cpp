#include <bits/stdc++.h>
using namespace std;

int N, a[1001], cnt[1001], prev_arr[1001], idx, ret = 1;
vector<int> v;

void go (int idx) {
  if (idx == -1) return;

  v.push_back(a[idx]);
  go(prev_arr[idx]);
  return;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  scanf("%d", &N);
  for(int i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }

  fill(prev_arr, prev_arr + 1001, -1);
  fill(cnt, cnt + 1001, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < i; j++) {
      if (a[j] < a[i] && cnt[i] < cnt[j] + 1) {
        cnt[i] = cnt[j] + 1;
        prev_arr[i] = j;

        if (ret < cnt[i]) {
          ret = cnt[i];
          idx = i;
        }
      }
    }
  }

  printf("%d\n", ret);
  go(idx);
  for (int i = v.size() - 1; i >= 0; i--) {
    printf("%d ", v[i]);
  }

  return 0;
}