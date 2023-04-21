#include <bits/stdc++.h>
using namespace std;

string S;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;
  
  string tmp = "";
  for (char c : S) {
    tmp += c;

    if (tmp == "pi" || tmp == "ka" || tmp == "chu") {
      tmp = "";
    }
  }

  if (tmp.size() == 0) cout << "YES" << '\n';
  else cout << "NO" << '\n';

  return 0;
}