#include <bits/stdc++.h>
using namespace std;

int N, sum = 0;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) {
    sum += i;
  }

  cout << sum << '\n';

  return 0;
}