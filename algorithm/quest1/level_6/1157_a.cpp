#include <bits/stdc++.h>
using namespace std;

string s;
int mx = 0, a[30];
vector<char> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  for (char c : s) {
    int idx = tolower(c) - (int)'a';
    a[idx]++;

    mx = max(a[idx], mx);
  }

  for (int i = 0; i < 26; i++) {
    if (a[i] == mx) v.push_back(i);
  }

  if (v.size() == 1) {
    cout << (char)toupper(v[0] + 'a') << '\n';
  } else {
    cout << '?' << '\n';
  }

  return 0;
}