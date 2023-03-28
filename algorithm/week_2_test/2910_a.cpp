#include <bits/stdc++.h>
using namespace std;  
int n, c, a[1004];
vector<pair<int, int>> v; 
map<int, int> mp, mp_first;

bool cmp (pair<int, int> i, pair<int, int> j) {
  if(i.second == j.second) {
    return mp_first[i.first] < mp_first[j.first];
  }
  return i.second > j.second;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
  cout.tie(NULL);
	cin >> n >> c; 
  
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]]++;
    if (mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
  }

  for (auto i : mp) {
    v.push_back({i.first, i.second});
  }

  sort(v.begin(), v.end(), cmp);

  for (auto i : v) {
    for (int j = 0; j < mp[i.first]; j++) {
      cout << i.first << " ";
    }
  }
	 
	return 0;
}
