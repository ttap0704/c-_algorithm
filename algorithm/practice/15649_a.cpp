#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> v;
map<string, bool> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 1; i <= N; i++) v.push_back(i);

  do {
    string s = "";
    for (int i = 0; i < M; i++) {
      s += to_string(v[i]) + ' ';
    }

    if (!mp[s]) {
      mp[s] = 1;
      cout << s << '\n';
    }
    
  } while (next_permutation(v.begin(), v.end()));

  return 0;
}