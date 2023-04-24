#include <bits/stdc++.h>
using namespace std;

int T, num;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> num >> s;
    
    for (char c : s) {
      for (int i = 0; i < num; i++) {
        cout << c;
      }
    }
    
    cout << '\n';
  }

  return 0;
}