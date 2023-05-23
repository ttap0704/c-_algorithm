#include <bits/stdc++.h>
using namespace std;

int N, fib[42];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  fib[1] = 1;
  fib[2] = 1;
  
  for (int i = 3; i <= N; i++) {
    fib[i] = fib[i - 1] + fib[i - 2];
  }

  cout << fib[N] << ' ' << N - 2 << '\n';

  return 0;
}