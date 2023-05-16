#include <bits/stdc++.h>
using namespace std;

int a[10], ret, mx = 0;
string s1, s2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s1 >> s2;

  int gap = stoi(s2) - stoi(s1);
  if (s1.size() > s2.size()) {
    mx = s1.size();
  } else {
    mx = s2.size();
  }

  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());
  for (int i = 0; i < s1.size(); i++) if(s1[i] == '8') a[i]++;
  for (int i = 0; i < s2.size(); i++) if(s2[i] == '8') a[i]++;

  int idx = to_string(gap).size();
  if (gap == 0) idx = 0;

  for (int i = idx; i < mx; i++) if(a[i] == 2) ret++;

  cout << ret << '\n';

  return 0;
}