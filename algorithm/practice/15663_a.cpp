#include <bits/stdc++.h>
using namespace std;

int N, M, n;
vector<int> v;
map<string, int> mp;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> n;
    v.push_back(n);
  }

  sort(v.begin(), v.end());
  do {
    string s = "";
    for (int i = 0; i < M; i++) {
      s += to_string(v[i]) + ' ';
    }

    if (!mp[s]) {
      cout << s << '\n';
      mp[s] = 1;
    }
    

  } while (next_permutation(v.begin(), v.end()));

  return 0;
}