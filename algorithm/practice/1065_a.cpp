#include <bits/stdc++.h>
using namespace std;

int N, ret;

int checkNumber (int num) {
  string num_s = to_string(num);

  int gap = (num_s[0] - num_s[1]);
  for (int i = 1; i < num_s.size() - 1; i++) {
    int cur_gap = num_s[i] - num_s[i + 1];
    if (cur_gap != gap) return 0;
  }

  return 1;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    if (i <= 99) ret++;
    else ret += checkNumber(i);
  }

  cout << ret << '\n';

  return 0;
}