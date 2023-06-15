#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;
const int INF = 1e9 + 4;
int N, M, y, x, a[100004];
vector<PI> tree;

PI init (int node, int start, int end) {
  if (start == end) return tree[node] = {a[start], a[start]};
  else {
    PI left = init(node * 2, start, (start + end) / 2), right = init((node * 2) + 1, (start + end) / 2 + 1, end);
    return tree[node] = {min(left.first, right.first), max(left.second, right.second)};
  }
}

PI query (int node, int start, int end, int left, int right) {
  if (end < left || right < start) return {INF, 0};
  if (left <= start && end <= right) return tree[node];

  PI l = query(node * 2, start, (start + end) / 2, left, right), r = query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return {min(l.first, r.first), max(l.second, r.second)};
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  int h = (int)ceil(log2(N));
  tree = vector<PI>(1 << (h + 1));

  for (int i = 0; i < N; i++) cin >> a[i];
  init(1, 0, N - 1);

  for (int i = 0; i < M; i++) {
    cin >> y >> x;
    PI ret = query(1, 0, N - 1, y - 1, x - 1);
    cout << ret.first << ' ' << ret.second << '\n';
  }

  return 0;
}