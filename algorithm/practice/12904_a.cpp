#include <bits/stdc++.h>
using namespace std;

string S, T;
bool ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S >> T;

  while (true) {
    if (S.size() == T.size()) {
      if (S == T) ret = 1;
      break;
    }

    char c = T.back();
    T.pop_back();
    if (c == 'B') {
      reverse(T.begin(), T.end());
    }
  }

  cout << ret << '\n';

  return 0;
}