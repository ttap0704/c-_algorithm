#include <bits/stdc++.h>
using namespace std;

int N;
string dp[10004];

string addString (string a, string b) {
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());

  string tmp = "";
  int r = 0;
  for (int i = 0; i < max(a.size(), b.size()); i++) {
    int sum = r;
    if (i < a.size()) sum += a[i] - '0';
    if (i < b.size()) sum += b[i] - '0';

    int add_i = (sum % 10);
    tmp += to_string(add_i);
    r = sum / 10;
  }

  reverse(tmp.begin(), tmp.end());

  if (r) tmp = '1' + tmp;

  return tmp;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  dp[0] = "0";
  dp[1] = "1";
  for (int i = 2; i <= N; i++) dp[i] = addString(dp[i - 1], dp[i - 2]);

  cout << dp[N] << '\n';

  return 0;
}