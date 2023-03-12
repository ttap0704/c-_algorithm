#include <bits/stdc++.h>
using namespace std;

int n, a[1004], cnt;
int go (int l, int r) {
  cnt++;
  if(l == r) return a[l];
  int mid = (l + r) / 2;
  int sum = go(l, mid) + go(mid + 1, r);
  return sum;
}

int main () {
  cin >> n;
  for (int i = 0; i <= n; i++) {
    a[i - 1] = i;
  }
  int sumval = go(0, n - 1);
  cout << sumval << "\n";
  cout << "cnt: " << cnt << "\n";
  return 0;
}