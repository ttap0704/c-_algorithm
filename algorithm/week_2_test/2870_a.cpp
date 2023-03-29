#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s, s2;
vector<string> v;

bool cmp (string a, string b) {
  if (a.size() == b.size()) {
    for (int i = 0; i < a.size(); i++) {
      char a_char = a[i];
      char b_char = b[i];

      if (a_char != b_char) {
        return a_char < b_char;
      }
    }
  }
  return a.size() < b.size();
}

string eraseZero(string s) {
  string cur_str = s;
  for (int i = 0; i < s.size(); i++) {
    char cur_char = s[i];
    if (cur_char != '0') {
      break;
    } else {
      if (i != s.size() - 1) {
        cur_str.erase(0, 1);
      }
    }
  }

  return cur_str;
}

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
          v.push_back(eraseZero(s2));
          s2 = "";
        }
      } else {
        if (s2.size() != 0) {
          v.push_back(eraseZero(s2));
        }
        s2 = "";
      }
    }
  }

  sort(v.begin(), v.end(), cmp);

  for (string i : v) {
    cout << i << "\n";
  }
  
  return 0; 
}