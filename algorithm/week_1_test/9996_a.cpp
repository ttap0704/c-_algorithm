#include <bits/stdc++.h>
using namespace std;

int N;
string pattern;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> pattern;

  long long pos = pattern.find('*');
  string start = pattern.substr(0, pos);
  string end = pattern.substr(pos + 1);

  vector<string> s_arr;

  for (int i = 0; i < N; i++) {
    cin >> s;

    s_arr.push_back(s);
  }

  for (string i : s_arr) {
    if (i.length() >= pattern.length() - 1) {
      if (i.substr(0, start.length()) == start && i.substr(i.length() - end.length()) == end) {
        cout << "DA " << "\n";
      } else {
        cout << "NE " << "\n";
      }
    } else {
      cout << "NE " << "\n";
    }
  }

  return 0;
}