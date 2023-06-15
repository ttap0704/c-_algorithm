#include <bits/stdc++.h>
#define MODULE 1000000007
using namespace std;

typedef long long ll;
int N, M, K, n, num[1000004], a, b, c;
vector<ll> tree;

ll init (int node, int start, int end) {
  if (start == end) return tree[node] = num[start];

  ll left = init(node * 2, start, (start + end) / 2), right = init((node * 2) + 1, (start + end) / 2 + 1, end);
  return tree[node] = (left * right) % MODULE;
}

ll query (int node, int start, int end, int left, int right) {
  if (right < start || left > end) return 1;
  if (start >= left && end <= right) return tree[node];

  ll l = query(node * 2, start, (start + end) / 2, left, right), r = query((node * 2) + 1, (start + end) / 2 + 1, end, left, right);
  return (l * r) % MODULE;
}

ll update (int node, int start, int end, int idx, ll val) {
  if (idx > end || idx < start) return tree[node];
  if (start == end) return tree[node] = val;
  
  ll left = update(node * 2, start, (start + end) / 2, idx, val), right = update((node * 2) + 1, (start + end) / 2 + 1, end, idx, val);
  return tree[node] = (left * right) % MODULE;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M >> K;
  int h = (int)ceil(log2(N));
  tree = vector<ll>(1 << (h + 1));

  for (int i = 1; i <= N; i++) {
    cin >> num[i];
  }
  init(1, 1, N);

  M += K;
  while (M--) {
    cin >> a >> b >> c;

    if (a == 1) {
      update(1, 1, N, b, c);
    } else {
      if (b > c) swap(b, c);
      ll ret = query(1, 1, N, b, c);
      cout << ret << '\n';
    }
  }
  
  return 0;
}