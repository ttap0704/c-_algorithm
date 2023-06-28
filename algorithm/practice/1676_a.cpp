#include <bits/stdc++.h>
using namespace std;

int N, ret;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 5; i <= N; i *= 5) {
		ret += N / i;
	}

  cout << ret << '\n';

  return 0;
}