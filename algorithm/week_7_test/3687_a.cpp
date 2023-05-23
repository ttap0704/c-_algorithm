#include <bits/stdc++.h>
using namespace std;

const string MAX_STRING = "1111111111111111111111111111111111111111111111111199";
const int price[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int T, N;
string dp[104];

string mxString (int num) {
  string tmp = "";
  while (num != 0) {
    if (num % 2 == 0) {
      tmp += '1';
      num -= 2;
    } else {
      tmp += '7';
      num -= 3;
    }
  }

  return tmp;
}

string getMinString (string a, string b) {
  if (a.size() == b.size()) return (a > b ? b : a);
  else if (a.size() > b.size()) return b;
  else return a;
}

string mnString (int here) {
  if (here == 0) return "";
  string &ret = dp[here];
  if (ret != MAX_STRING) return ret;

  for (int i = 0; i <= 9; i++) {
    if (here - price[i] < 0) continue;
    if (here == N && i == 0) continue;
    ret = getMinString(ret, to_string(i) + mnString(here - price[i]));
  }

  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;

    fill(dp, dp + 104, MAX_STRING);
    string mx = mxString(N);
    string mn = mnString(N);

    cout << mn << ' ';
    cout << mx << '\n';
  }

  return 0;
}