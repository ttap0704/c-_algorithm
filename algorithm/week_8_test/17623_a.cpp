#include <bits/stdc++.h>
using namespace std;

char a[6] = {'(', ')', '{', '}', '[', ']'};
int T, N;
string dp[1004];
map<char, char> mp;

bool check(string before, string after){ 
	if(before == "" && after == "") return false; 
	if(before == "") return true;   
	if(before.size() == after.size()) return after < before;
	return after.size() < before.size(); 
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 6; i++) {
    mp[i + '1'] = a[i];
  }

  dp[1] = "12";
  dp[2] = "34";
  dp[3] = "56";

  for(int idx = 1; idx <= 1000; idx++){   
		if(idx % 2 == 0 && check(dp[idx], '1' + dp[idx / 2] + '2'))dp[idx] = '1' + dp[idx / 2] + '2'; 
		if(idx % 3 == 0 && check(dp[idx], '3' + dp[idx / 3] + '4'))dp[idx] = '3' + dp[idx / 3] + '4'; 
		if(idx % 5 == 0 && check(dp[idx], '5' + dp[idx / 5] + '6'))dp[idx] = '5' + dp[idx / 5] + '6';   

		for(int i = 1; i <= idx; i++){
			if(check(dp[idx], dp[i] + dp[idx - i]))dp[idx] = dp[i] + dp[idx - i]; 
		}
	}  

  cin >> T;
  while (T--) {
    cin >> N;
    
    string ret = "";
    for (char c : dp[N]) ret += mp[c];

    cout << ret << '\n';
  }

  return 0;
}