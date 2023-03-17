// 9996 복습
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
string pattern;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cin >> pattern;

  ll pos = pattern.find('*');
  string start = pattern.substr(0, pos);
  string end = pattern.substr(pos + 1);

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    if (s.size() < start.size() + end.size()) {
      cout << "NE\n";
      continue;
    }
    string compare_start = s.substr(0, start.size());
    string compare_end = s.substr(s.size() - end.size());

    if (compare_start == start && compare_end == end) cout << "DA\n";
    else cout << "NE\n";
  }

  return 0;
}