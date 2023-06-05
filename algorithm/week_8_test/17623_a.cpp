#include <bits/stdc++.h>
using namespace std;

vector<char> v = {'(', ')', '{', '}', '[', ']'};
int T, N;
map<int, int> cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  while (T--) {
    cin >> N;

    string ret = "";
    string plus_ret = "";

    while (N != 0) {
      int i = 0;
      if (N > 5) {
        while (true) {
          N -= i;
          if (N % 5 == 0 || N % 3 == 0 || N % 2 == 0) break;
          i++;
        }

        if (i == 0) {
          if (N % 5 == 0) N /= 5, i = 14;
          else if (N % 3 == 0) N /= 3, i = 12;
          else if (N % 2 == 0) N /= 2, i = 10;
        } else {
          if (i == 1) i = 0;
          else if (i == 2) i = 2;
          else if (i == 3) i = 4;
        }
      } else {
        if (N == 4) {
          N -= 4, i = 6;
        } else if (N >= 3) N -= 3, i = 4;
        else if (N >= 2) N -= 2, i = 2;
        else N -= 1, i = 0;
      }

      if (i <= 6) {
        string tmp = "";
        if (i == 6) {
          tmp = "({})";
        } else {
          tmp += v[i];
          tmp += v[i + 1];
        }
        plus_ret = tmp + plus_ret;
      } else {
        i %= 10;
        ret += plus_ret;
        ret += v[i];

        plus_ret = "";
      }


      cout << "i : " << i <<'\n';
      cout << "ret : " << ret <<'\n';
    }

    ret += plus_ret;
    cout << "ret : " << ret <<'\n';
  }

  return 0;
}