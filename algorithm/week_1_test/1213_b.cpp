// 1213 복습
#include <bits/stdc++.h>
using namespace std;

string s, mid, ret;
int chars[26], odd_cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  for (char c : s) {
    chars[c - 'A']++;
  }

  for (int i = 25; i >= 0; i--) {
    char cur_char = i + 'A';
    if (chars[i] % 2 != 0) {
      mid = cur_char;
      odd_cnt++;
      if (odd_cnt > 1) {
        break;
      }
    }

    if (chars[i] > 0) {
      for (int j = 0; j < chars[i] / 2; j++) {
        ret = cur_char + ret;
        ret += cur_char;
      }
    }
  }

  ret.insert(ret.size() / 2, mid);

  if (odd_cnt <= 1) {
    cout << ret << "\n";
  } else {
    cout << "I'm Sorry Hansoo" << "\n";
  }

  return 0;
}