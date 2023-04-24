#include <bits/stdc++.h>
using namespace std;

int N, B;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> B;

  while (N) {
    int a = N % B;

    if (a >= 10) s += (a - 10) + 'A';
    else s += a + '0';

    N /= B;
  }

  reverse(s.begin(), s.end());

  cout << s << '\n';

  return 0;
}