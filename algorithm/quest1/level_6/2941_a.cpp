#include <bits/stdc++.h>
using namespace std;

int cnt = 0;
string s, a, arr[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  for (char c : s) {
    a += c;
    if (a.size() >= 2) {
      string s2 = a.substr(a.size() - 2);
      string s3 = "";
      if (a.size() >= 3) {
        s3 =  a.substr(a.size() - 3);
      }

      for (string tmp : arr) {
        if (tmp == s2 || tmp == s3) {
          cnt++;
          cnt += a.size() - tmp.size();
          a = "";
          break;
        }
      }
    }
  }

  cout << (cnt + a.size()) << '\n';

  return 0;
}