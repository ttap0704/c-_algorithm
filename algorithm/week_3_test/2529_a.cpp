#include <bits/stdc++.h>
using namespace std;

int N;
char c[10];
vector<int> mn_v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector<int> mx_v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
vector<int> mn, mx;
string mn_s, mx_s;

bool check(char cur_c, int i, int j) {
  if (cur_c == '<') {
    return i < j;
  } else {
    return i > j;
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  
  stack<char> st;
  for (int i = 0; i < N; i++) {
    cin >> c[i];

    mn.push_back(mn_v[i]);
    mx.push_back(mx_v[i]);

    mn_s += '9';
    mx_s += '0';
  }

  mn.push_back(mn_v[N]);
  mx.push_back(mx_v[N]);
  mn_s += '9';
  mx_s += '0';

  do {
    bool flag = 1;
    string s = "";
    for (int i = 0; i < N; i++) {
      if (check(c[i], mn[i], mn[i + 1]) && mn[i] <= mn_s[i] - '0') {
        s += to_string(mn[i]);
      } else {
        flag = 0;
        break;
      }
    }

    if (!flag) continue;
    s += to_string(mn[N]);

    if (s.size() == N + 1) {
      mn_s = s;
    }
  } while (next_permutation(mn.begin(), mn.end()));

  do {
    bool flag = 1;
    string s = "";
    for (int i = 0; i < N; i++) {
      if (check(c[i], mx[i], mx[i + 1]) && mx[i] >= mx_s[i] - '0') {
        s += to_string(mx[i]);
      } else {
        flag = 0;
        break;
      }
    }
    if (!flag) continue;
    s += to_string(mx[N]);

    if (s.size() == N + 1) {
      mx_s = s;
    }
  } while (prev_permutation(mx.begin(), mx.end()));

  cout << mx_s << "\n";
  cout << mn_s << "\n";

  return 0;
}