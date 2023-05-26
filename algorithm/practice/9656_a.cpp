#include <bits/stdc++.h>
using namespace std;

int N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  cout << (N % 2 == 0 ? "SK" : "CY") << '\n';

  return 0;
}