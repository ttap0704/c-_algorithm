#include <bits/stdc++.h>
using namespace std;

const int INF = -987654321;
vector<int> num_arr;
vector<char> emo_arr;
int N, mx = INF, n, ret;
char c;
vector<int> num_index;

int oper (char a, int b, int c) {
  if (a == '+') return b + c;
  else if (a == '-') return b - c;
  else if (a == '*') return b * c;
}

void go (int here, int _num) {
  if (here + 1 == num_arr.size()) {
    mx = max(mx, _num);
    return;
  }

  go(here + 1, oper(emo_arr[here], _num, num_arr[here + 1]));
  if (here + 2 <= num_arr.size() - 1) {
    int tmp = oper(emo_arr[here + 1], num_arr[here + 1], num_arr[here + 2]);
    go(here + 2, oper(emo_arr[here], _num, tmp));
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      cin >> n;
      num_arr.push_back(n);
    } else {
      cin >> c;
      emo_arr.push_back(c);
    }
  }

  go(0, num_arr[0]);

  cout << mx << "\n";

  // for (int i : num_arr) {
  //   cout << i << " ";
  // }
  // cout << "\n";

  // for (char i : emo_arr) {
  //   cout << i << " ";
  // }
  // cout << "\n";

  return 0;
}