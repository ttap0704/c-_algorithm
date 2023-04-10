#include <bits/stdc++.h>
using namespace std;

int N, del_num, visited[51], root = 0, num;
vector<int> a[51];

int dfs (int start) {
  int ret = 0;
  visited[start] = 1;

  for (int i : a[start]) {
    if (i == del_num) continue;
    ret += dfs(i);
  }
  if (ret == 0) return 1;
  else return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> num;
    if (num == -1) root = i;
    else a[num].push_back(i);
  }

  cin >> del_num; 
  if (root == del_num) {
    cout << 0 << "\n";
  } else {
    cout << dfs(root) << "\n";
  }

  return 0;
}