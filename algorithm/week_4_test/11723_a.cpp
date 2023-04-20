#include <bits/stdc++.h>
using namespace std;

int N, a, num;
char s[11];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  scanf(" %d", &N);
  for (int i = 0; i < N; i++) {
    scanf(" %s %d", &s, &num);
    
    if (s[0] == 'a' && s[1] == 'l') {
      a = (1 << 21) - 1;
    } else if (s[0] == 'e') {
      a = 0;
    } else if(s[0] == 'a' && s[1] == 'd') {
      a |= (1 << num);
    } else if (s[0] == 'r') {
      a &= ~(1 << num);
    } else if (s[0] == 't') {
      a ^= (1 << num);
    } else if (s[0] == 'c') {
      cout << ((a & (1 << num)) ? 1 : 0) << '\n';
    }
  }

  return 0;
}