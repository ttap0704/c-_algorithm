#include <bits/stdc++.h>
using namespace std;

int N, L, n, ret = 0;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> L;
  for (int i = 0 ; i < N; i++) cin >> n, v.push_back(n);

  if (N == 0) {
    cout << 0 << '\n';
    return 0;
  }
  
  sort(v.begin(), v.end());
  
  int to = -1;
  for (int i : v) {
    if (i <= to) continue;
    to = i + L - 1;
    ret++;
  }

  cout << ret << '\n';

  return 0;
}