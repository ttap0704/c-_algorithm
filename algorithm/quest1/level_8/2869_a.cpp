#include <bits/stdc++.h>
using namespace std;

int a, b, v, sum = 0, ret = 1;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> a >> b >> v;

  if (a >= v) cout << '1' << '\n';
  else {
    ret += (v - a) / (a - b);
    if ((v - a) % (a - b) != 0) ret++;

    cout << ret << '\n';
  }  
  

  return 0;
}