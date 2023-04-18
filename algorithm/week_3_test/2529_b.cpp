#include <bits/stdc++.h>
using namespace std;

int N, visited[10];
char c[10];
string mn, mx;
vector<string> ret;

bool check(char cur_c, int i, int j) {
  bool res = false;
  if (i < j && cur_c == '<') res = true;
  else if (i > j && cur_c == '>') res = true;

  return res;
}

void dfs(int start, string s) {
  if (s.size() == N + 1){
    ret.push_back(s);
    return;
  }

  for (int i = 0; i < 10; i++) {
    if (visited[i]) continue;
    if (start == 0 || check(c[start - 1], s[s.size() - 1] - '0', i)) {
      visited[i] = 1;
      dfs(start + 1, s + to_string(i));
      visited[i] = 0;
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) cin >> c[i];

  dfs(0, "");
  sort(ret.begin(), ret.end());

  cout << ret[ret.size() - 1] << "\n" << ret[0] << "\n";

  return 0;
}