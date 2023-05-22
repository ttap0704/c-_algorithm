#include <bits/stdc++.h>
using namespace std;

int N, S, E, M, a[2004], dp[2004][2004];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> a[i];
  
  for (int i = 1; i <= N; i++) dp[i][i] = 1;
  
  for (int i = 1; i <= N; i++) {
    if (a[i] == a[i + 1]) dp[i][i + 1] = 1;
  }

  for (int _size = 2; _size <= N; _size++) {
		for (int i = 1; i <= N - _size; i++) {
			if(a[i] == a[i + _size] && dp[i + 1][i + _size - 1])dp[i][i + _size] = 1; 
		}
	} 

  cin >> M;
  while (M--) {
    cin >> S >> E;
    cout << dp[S][E] << '\n';
  }

  return 0;
}