#include <bits/stdc++.h>
using namespace std;

string N;

bool customSort (char a, char b) {
  return (a - '0') > (b - '0');
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  sort(N.begin(), N.end(), customSort);

  cout << N << '\n';
  
  return 0;
}