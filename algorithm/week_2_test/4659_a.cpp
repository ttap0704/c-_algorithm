// 4659 복습 필요!!

#include <bits/stdc++.h>
using namespace std;

const vector<char> parent_c = {'a', 'e', 'i', 'o', 'u'};
string s;
pair<int, int> check_char;
bool check;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> s;
    if (s == "end") break;

    bool check = true;

    int check_cnt = 0;
    for (char c : parent_c) {
      if (s.find(c) != string::npos) {
        check_cnt++;
      }
    }
    if(check_cnt == 0) {
      cout << "<" << s << ">" << " is not acceptable.";
      check = false;
    }

    for (int i = 0; i < s.size(); i++) {
      if (check == false) break;
      char c = s[i];
      if (find(parent_c.begin(), parent_c.end(), c) != parent_c.end()) {
        check_char.first++;
        check_char.second = 0;
      } else {
        check_char.first = 0;
        check_char.second++;
      }

      if (check_char.first >= 3 || check_char.second >= 3) {
        cout << "<" << s << ">" << " is not acceptable.";
        check = false;
        break;
      }

      if (i != 0 && s[i - 1] == c) {
        if (c != 'e' && c != 'o') {
          cout << "<" << s << ">" << " is not acceptable.";
          check = false;
          break;
        }
      }
    }

    if (check) {
      cout << "<" << s << ">" << " is acceptable.";
    }
  }
  
  return 0;
}