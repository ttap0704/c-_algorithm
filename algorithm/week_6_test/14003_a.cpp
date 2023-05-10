#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 4;
int N, n, lis[1000004], ret = 0;
pair<int, int> ans[1000004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fill(lis, lis + 1000004, INF);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n;
    auto pos = lower_bound(lis, lis + ret, n);
    int pos2 = (int)(lower_bound(lis, lis + ret, n) - lis);
    if (*pos == INF) ret++;
    *pos = n;
    ans[i].first = pos2;
    ans[i].second = n;
  };

  // for (int i = 0; i < N; i++) {
  //   cout << ans[i].first << " : " << ans[i].second << '\n';
  // }

  printf("%d\n", ret);
  stack<int> st;
  for (int i = N - 1; i >= 0; i--) {
    if (ans[i].first == ret - 1) {
      st.push(ans[i].second);
      ret--;
    }
  }

  while (st.size()) {
    printf("%d ", st.top());
    st.pop();
  }

  return 0;
}