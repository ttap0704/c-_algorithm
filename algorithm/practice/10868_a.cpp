#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 4;
int N, M, a[100004], y, x;
vector<int> tree;

int init (int node, int start, int end) {
  if (start == end) return tree[node] = a[start];

  int left = init(node * 2, start, (start + end) / 2), right = init((node * 2) + 1, (start + end) / 2 + 1, end);
  return tree[node] = min(left, right);
}

int query (int node, int start, int end, int left, int right) {
  if (end < left || start > right) return INF;
  if (left <= start && right >= end) return tree[node];

  int l = query(node * 2, start, (start + end) / 2, left, right), r = query((node * 2) + 1, (start + end) / 2 + 1, end, left, right);
  return min(l, r);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) cin >> a[i];

  int h = (int)ceil(log2(N));
  tree = vector<int>(1 << (h + 1));
  init(1, 0, N - 1);

  for (int i = 0; i < M; i++) {
    cin >> y >> x;
    int ret = query(1, 0, N - 1, y - 1, x - 1);
    cout << ret << '\n';
  }

  return 0;
}