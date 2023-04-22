#include <bits/stdc++.h>
using namespace std;

int N, X, num;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> X;

  for (int i = 0; i < N; i++) {
    cin >> num;
    if (num < X) s += to_string(num) + ' ';
  }

  cout << s << '\n';
  
  return 0;
}