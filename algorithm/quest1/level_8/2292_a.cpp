#include <bits/stdc++.h>
using namespace std;

int N, sum = 1, num = 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  while (sum < N) {
    sum += (num * 6);
    num++;
  }

  cout << num << '\n';

  return 0;
}