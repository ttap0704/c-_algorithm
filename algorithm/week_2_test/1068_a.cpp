#include <bits/stdc++.h>
using namespace std;

int N, parent, visited[51], del_num, cnt = 0;
vector<int> v[51];
vector<int> parent_arr;

void dfs(int start) {
  visited[start] = 1;
  int del_cnt = 0;
  int pos = find(v[start].begin(), v[start].end(), del_num) - v[start].begin();
  if (pos < v[start].size()) {
    del_cnt = 1;
  }
  if (start == del_num) return;
  if (v[start].size() - del_cnt == 0) {
    cnt++;
  } else {
    for (int i : v[start]) {
      if (visited[i] == 0){
        dfs(i);
      }
    }
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> parent;
    if (parent != -1) {
      v[parent].push_back(i);
    } else {
      parent_arr.push_back(i);
    }
  }

  cin >> del_num;
  for (int i : parent_arr) {
    dfs(i);
  }
  cout << cnt << "\n";
  return 0;
}