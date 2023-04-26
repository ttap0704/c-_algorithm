#include <bits/stdc++.h>
using namespace std;

string s, s2, b, ret = "";
map<char, int> a;
vector<string> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  cin >> b;

  for (char c : s) {
    ret += c;

    if (ret.size() >= b.size()) {
      if (ret.substr(ret.size() - b.size()) == b) {
        ret.erase(ret.size() - b.size());
      }
      // cout << ret.substr(ret.size() - b.size()) << '\n';
      
    }
  }

  if (ret.size()) {
    cout << ret <<'\n';
  } else {
    cout << "FRULA" <<'\n';
  }
  
  return 0;
}