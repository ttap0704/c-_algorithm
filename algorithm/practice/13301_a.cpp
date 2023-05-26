#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
ll fibo[81];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  fibo[0] = 1;
  fibo[1] = 1;
  for (int i = 2; i <= N; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];

  cout << ((fibo[N] + fibo[N - 1]) * 2) << '\n';

  return 0;
}