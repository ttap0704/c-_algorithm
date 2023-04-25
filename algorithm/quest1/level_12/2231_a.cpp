#include <bits/stdc++.h>
using namespace std;

string origin, N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> origin;
  N = "1";

  while (true) {
    if (N == origin) break;

    int sum = stoi(N);
    for (char c : N) {
      sum += c - '0';
    }

    if (sum == stoi(origin)) break;

    N = to_string(stoi(N) + 1);
  }

  if (N == origin) cout << 0 << '\n';
  else cout << N << '\n';

  return 0;
}