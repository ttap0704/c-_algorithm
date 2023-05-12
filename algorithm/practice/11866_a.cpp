#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v[1004], ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;
  v[0].push_back(1);
  for (int i = 1; i < N; i++) v[i].push_back(i + 1);
  v[N].push_back(1);

  int cur_idx = 0, before_idx = 0, cnt = 0;
  while (true) {
    if (cnt % K == 0 && cur_idx != 0) {
      ret.push_back(cur_idx);
      if (ret.size() == N) break;
      v[before_idx][0] = v[cur_idx][0];
      cnt = 0;
    }

    before_idx = cur_idx;
    cur_idx = v[cur_idx][0];
    cnt++;
  }

  cout << "<";
  for (int i = 0; i < ret.size(); i++) {
    cout << ret[i];
    if (i != ret.size() - 1) cout << ", ";
  }
  cout << ">\n";
  
  return 0;
}