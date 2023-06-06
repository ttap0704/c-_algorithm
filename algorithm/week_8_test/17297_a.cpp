#include <bits/stdc++.h>
using namespace std;

int dp[40];
int M;
string s = "Messi Gimossi";
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> M;
  M--;

  dp[1] = 5;
  dp[2] = 13;

  for (int i = 3; i <= 39; i++) {
    dp[i] = dp[i - 1] + dp[i - 2] + 1;
  }
 
  for (int i = 39; i >= 2; i--) {
    if (M >= dp[i]) M -= (dp[i] + 1);
  }

  if (M == 5 || M == -1) cout << "Messi Messi Gimossi" << '\n';
  else cout << s[M] << '\n';
  
  return 0;
}