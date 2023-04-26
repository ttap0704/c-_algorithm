#include <bits/stdc++.h>
using namespace std;

string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  set<string> set;

  string str = "";
  for (int i = 0; i < s.size(); i++) {
      for (int j = i; j < s.size(); j++) {
          str += s[j];
          set.insert(str);
      }
      str = "";
  }

  cout << set.size();
  
  return 0;
}