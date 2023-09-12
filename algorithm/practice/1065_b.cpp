#include <bits/stdc++.h>
using namespace std;

int N, a;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    string s = to_string(i);
    bool flag = 0;

    if (s.size() > 1) {
      int gap = (s[0] - '0') - (s[1] - '0');

      for (int j = 1; j < s.size(); j++) {
        if (gap != (s[j - 1] - '0') - (s[j] - '0')){
          flag = 1;
          break;
        }
      }
    }
    
    if (!flag) a++;
  }

  cout << a << '\n';

  return 0;
}