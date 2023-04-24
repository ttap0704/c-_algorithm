#include <bits/stdc++.h>
using namespace std;

int N, sum = 0;
char c;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> c;
    sum += c - '0';
  }

  cout << sum << '\n';

  return 0;
}