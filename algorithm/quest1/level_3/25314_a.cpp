#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  for (int i = 0; i < N / 4; i++) {
    s += "long ";
  }
  s+= "int";
  
  cout << s << '\n';

  return 0;
}