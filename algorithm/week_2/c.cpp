#include <bits/stdc++.h>
using namespace std;

const int V = 10;
vector<int> adj[V];
bool visited[V];

void go (int from) {
  cout << from << "\n";
  visited[from] = 1;
  for (int there : adj[from]) {
    if (visited[there]) continue;
    go(there);
  }
}

int main () {
  adj[1].push_back(2);
  adj[1].push_back(3);

  adj[2].push_back(1);
  
  adj[3].push_back(1);
  adj[3].push_back(4);

  for (int i = 0; i < V; i++) {
    if (adj[i].size() && visited[i] == 0) {
      go(i);
    }
  }
 
  return 0;
}