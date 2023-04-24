#include <bits/stdc++.h>
using namespace std;

int N, num;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  num = pow(2, N) + 1;

  cout << num * num << '\n';

  return 0;
}