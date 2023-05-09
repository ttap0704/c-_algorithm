#include <bits/stdc++.h>
using namespace std;

int N, M, ret, num;
map<int, int> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> num, mp[num]++;
  for (int i = 0; i < M; i++) cin >> num, mp[num]++;

  for (auto i : mp) if (i.second == 1) ret++;

  cout << ret << '\n';

  return 0;
}