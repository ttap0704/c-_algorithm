#include <bits/stdc++.h>
using namespace std;
int a[26], sum = 0;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  a[0] = a[1] = a[2] = 3;
  a[3] = a[4] = a[5] = 4;
  a[6] = a[7] = a[8] = 5;
  a[9] = a[10] = a[11] = 6;
  a[12] = a[13] = a[14] = 7;
  a[15] = a[16] = a[17] = a[18] = 8;
  a[19] = a[20] = a[21] = 9;
  a[22] = a[23] = a[24] = a[25] = 10;

  for (char c : s) {
    sum += a[c - 'A'];
  }

  cout << sum << '\n';

  return 0;
}