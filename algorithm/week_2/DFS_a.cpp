#include <bits/stdc++.h>
using namespace std;

vector<int> adj[6];
int visited[6];

void dfs (int start) {
  visited[start] = 1;
  cout << "start : " << start << "\n";
  for (int i : adj[start]) {
    if (visited[i] == 0) {
      dfs(i);
    }
  }

  cout << start << "로부터 종료\n";
}

int main () {
  adj[1].push_back(2);
  adj[1].push_back(3);
  adj[2].push_back(4);
  adj[4].push_back(2);
  adj[2].push_back(5);

  dfs(1);
  return 0;
}