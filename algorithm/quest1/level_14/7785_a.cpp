#include <bits/stdc++.h>
using namespace std;

int N;
string s1, s2;
map<string, int> mp;
vector<string> v;

bool customSort (string val1, string val2) {
  return val1 > val2;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s1 >> s2;

    if (s2 == "enter") {
      if (mp[s1] == 0) v.push_back(s1);
      mp[s1] = 2;
    } else {
      mp[s1] = 1;
    }
  }

  sort(v.begin(), v.end(), customSort);

  for (string s : v) {
    if (mp[s] == 2) cout << s << '\n';
  }

  return 0;
}