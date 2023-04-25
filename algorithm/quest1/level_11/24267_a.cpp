#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, cnt;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  n = n - 1;
  int i = 1;
  while (n--) {
    cnt += n * i;
    i++;
  }  

  cout << cnt << '\n';
  cout << 3 << '\n';

  return 0;
}