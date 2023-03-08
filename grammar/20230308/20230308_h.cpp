#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
map<string, string> mp2;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // 참조
  // cout << mp[1] << "\n";
  // cout << mp2["aaa"] << "\n";

  // 참조만 해도
  // int = 0
  // string = ''
  // 으로 자동 생성됨

  // 그렇기 때문에 맵에 요소가 있는지 체크 후
  // 데이터를 할당

  if (mp[1] == 0) {
    mp[1] = 2;
  }
  for(auto i : mp) cout << i.first << " " << i.second;
  cout << '\n';
  for(auto i : mp2) cout << i.first << " " << i.second;

  return 0;
}