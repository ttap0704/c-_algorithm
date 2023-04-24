#include <bits/stdc++.h>
using namespace std;

string S;
int N;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> S;
  cin >> N;

  cout << S[N - 1] << '\n';
  return 0;
}