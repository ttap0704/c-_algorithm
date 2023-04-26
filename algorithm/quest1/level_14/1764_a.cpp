#include <bits/stdc++.h>
using namespace std;

int N, M, cnt;
string s;
vector<string> v;
map<string, int> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> s;
    mp[s]++;
  }

  for (int i = 0; i < M; i++) {
    cin >> s;
    mp[s]++;

    if (mp[s] == 2) {
      cnt++;
      v.push_back(s);
    }
  }

  sort(v.begin(), v.end());

  cout << cnt << '\n';
  for (string tmp : v) {
    cout << tmp << '\n';
  }

  return 0;
}