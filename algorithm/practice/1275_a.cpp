#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N, Q, num[100004], a, b, c, d;
vector<ll> tree;

ll init (int node, int start, int end) {
  if (start == end) return tree[node] = num[start];

  ll left = init(node * 2, start, (start + end) / 2), right = init((node * 2) + 1, (start + end) / 2 + 1, end);
  return tree[node] = (left + right);
}

ll query (int node, int start, int end, int left, int right) {
  if (right < start || left > end) return 0;
  if (start >= left && end <= right) return tree[node];

  ll l = query(node * 2, start, (start + end) / 2, left, right), r = query((node * 2) + 1, (start + end) / 2 + 1, end, left, right);
  return (l + r);
}

ll update (int node, int start, int end, int idx, ll val) {
  if (idx > end || idx < start) return tree[node];
  if (start == end) return tree[node] = val;

  ll l = update(node * 2, start, (start + end) / 2, idx, val), r = update((node * 2) + 1, (start + end) / 2 + 1, end, idx, val);
  return tree[node] = l + r;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  cin >> N >> Q;
  for (int i = 1; i <= N; i++) cin >> num[i];

  int h = (int)ceil(log2(N));
  tree.resize((1 << (h + 1)));
  init(1, 1, N);

  while (Q--) {
    cin >> a >> b >> c >> d;

    if (a > b) swap(a, b);

    cout << query(1, 1, N, a, b) << '\n';
    update(1, 1, N, c, d);
  }

  return 0;
}