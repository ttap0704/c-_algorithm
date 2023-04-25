#include <bits/stdc++.h>
using namespace std;

string a, b, s;
int i = 0, plus_num;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b;

  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  while (true) {
    int sum = 0;
    if (a.size()) {
      sum += a.front() - '0';
      a.erase(0, 1);
    }

    if (b.size()) {
      sum += b.front() - '0';
      b.erase(0, 1);
    }

    sum += plus_num;

    s += to_string(sum % 10);
    plus_num = sum / 10;

    if (a.size() == 0 && b.size() == 0) break;
  }

  if (plus_num) s += plus_num + '0';
  reverse(s.begin(), s.end());

  cout << s << '\n';

  return 0;
}