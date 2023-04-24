#include <bits/stdc++.h>
using namespace std;

string N;
int B, sum;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> B;
  reverse(N.begin(), N.end());
  for (int i = 0; i < N.size(); i++) {
    char c = N[i];
    int tmp = 0;
    if ('9' >= c && c >= '0') tmp = (int)(c - '0');
    else {
      tmp = (c - 'A') + 10;
    }

    sum += tmp * pow(B, i);
  }

  cout << sum << '\n';

  return 0;
}