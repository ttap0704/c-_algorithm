// 재귀함수로 풀어보기
#include <bits/stdc++.h>
using namespace std;

int a[9];
int n = 9;
int r = 7;
vector<int> v;

void solve() {
  int sum = 0;
  for (int i = 0; i < r; i++) {
    sum += a[i];
  }

  if (sum == 100) {
    sort(a, a + r);
    for (int i = 0; i < r; i++) {
      cout << a[i] << "\n";
    }
    exit(0);
  }
}

void print() {
  for (int i : a) cout << i << " ";
  cout << "\n";
}

void makePermutation(int n, int r, int depth) {
  if (r == depth) {
    solve();
  }

  for (int i = depth; i < n; i++) {
    swap(a[i], a[depth]);
    makePermutation(n, r, depth + 1);
    swap(a[i], a[depth]);
  }
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  makePermutation(n, r, 0);
  return 0;
}