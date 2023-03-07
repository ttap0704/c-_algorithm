// pair로 된 vector 정렬 시
// first, second, third 순으로 정렬됨

#include<bits/stdc++.h>
using namespace std; 

vector<pair<int, int>> v; 

bool cmp(pair<int, int> a, pair<int, int> b){
  return a.first > b.first;
}

int main(){
  for(int i = 10; i >= 1; i--){
    v.push_back({i, 10 - i});
  }

  for(int i = 10; i >= 1; i--){
    v.push_back({i, 20 - i});
  }
  sort(v.begin(), v.end(), cmp);
  for(auto it : v) cout << it.first << " : " << it.second << "\n";
return 0;
}
