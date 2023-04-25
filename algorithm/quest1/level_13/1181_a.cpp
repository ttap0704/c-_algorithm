#include <bits/stdc++.h>
using namespace std;

int N;
string s;
vector<string> v;
map<string, bool> mp;

bool customSort (string s1, string s2) {
  if (s1.size() == s2.size()) {
    return s1 < s2;
  } else {
    return s1.size() < s2.size();
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (mp[s] != 1) v.push_back(s);
    mp[s] = 1;
  }

  sort(v.begin(), v.end(), customSort);

  for (string tmp : v) {
    cout << tmp << '\n';
  }
  return 0;
}