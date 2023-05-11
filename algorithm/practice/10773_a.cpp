#include <bits/stdc++.h>
using namespace std;

int N, n, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> v;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> n;
  
    if (n == 0) {
      v.pop_back();
    } else {
      v.push_back(n);
    }
  }

  for (int i : v) ret += i;

  cout << ret << '\n';

  return 0;
}