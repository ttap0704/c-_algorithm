#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s, s2;
vector<ll> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      char c = s[j];
      if (c + 0 >= 48 && c + 0 <= 57) {
        s2 += c;
        if (j == s.size() - 1) {
          v.push_back(stoll(s2));
          s2 = "";
        }
      } else {
        if (s2.size() != 0) {
          v.push_back(stoll(s2));
        }
        s2 = "";
      }
    }
  }

  sort(v.begin(), v.end());

  for (int i : v) {
    cout << i << "\n";
  }
  
  return 0; 
}