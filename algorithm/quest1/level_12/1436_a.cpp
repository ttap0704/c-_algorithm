#include <bits/stdc++.h>
using namespace std;

long long N, cnt = 1, num = 667;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  while (true) {
    if (N == cnt) break;

    string tmp = to_string(num);
    int pos =tmp.find("666");
    if (pos != string::npos) cnt++;

    num++;
  }

  cout << num - 1 << '\n';

  return 0;
}