#include <bits/stdc++.h>
using namespace std;

int N, M, mx, ret;
long long a[1000004];

bool check (int mid) {
  long long sum = 0;
  for (int i = N - 1; i >= 0; i--) {
    sum += (a[i] - mid);
    if (sum >= M) return true;
  }

  return false;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    if (mx < a[i]) mx = a[i];
  }

  sort(a, a + N);

  int left = 1, right = mx, mid;
  while (left <= right) {
    mid = (left + right) / 2;
    
    bool check_tree = check(mid);
    if (check_tree) {
      ret = max(ret, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  
  cout << ret << '\n';

  return 0;
}