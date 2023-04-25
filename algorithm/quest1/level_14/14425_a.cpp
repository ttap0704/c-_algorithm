#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
string s;
map<string, int> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    mp[s] = 1;
  }

  for (int i = 0; i < M; i++) {
    cin >> s;

    if (mp[s]) cnt++;
  }

  cout << cnt << '\n';

  return 0;
}