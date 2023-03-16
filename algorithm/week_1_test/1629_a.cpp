#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b, c;

ll go (ll a, ll b) {
  if (b == 1) return a % c;

  // 2^4 = 2^2 * 2^2
  ll ret = go(a, b / 2);
  ret = (ret * ret) % c;

  // 2^5 등 홀수일 때, 한 번더 곱해줘야함
  if(b % 2) ret = (ret * a) % c;
  return ret;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> c;

  cout << go(a, b) << "\n";

  return 0;
}