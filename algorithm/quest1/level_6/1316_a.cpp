#include <bits/stdc++.h>
using namespace std;

int N, a[26], cnt;
string s;
char cur_c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s;

    memset(a, 0, sizeof(a));
    cur_c = s[0];
    for (char c : s) {
      if (cur_c == c) {
        a[c -  'a']++;
      } else {
        if (a[c - 'a'] == 0) {
          cur_c = c;
          a[c - 'a']++;
        } else {
          cnt++;
          break;
        }
      }
    }
  }

  cout << (N - cnt) << '\n';
  
  return 0;
}