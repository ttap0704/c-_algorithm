// unique(시작, 끝);
// 앞에서부터 비교하여 중복되는 요소를 제거하고, 나머지 요소는 그대로 둠

// 앞에서부터 비교하기 때문에 sort와 같이 사용하는게 나음

#include <bits/stdc++.h>
using namespace std; 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  vector<int> s {4, 3, 3, 5, 1, 2, 3}; 
  s.erase(unique(s.begin(),s.end()),s.end()); 
  for(int i : s) cout << i << " ";
  cout << '\n';

  vector<int> s2 {4, 3, 3, 5, 1, 2, 3}; 
  sort(s2.begin(), s2.end()); 

  // 최종적으로 모든 중복요소 제가하는 상태
  s2.erase(unique(s2.begin(),s2.end()),s2.end());
  for(int i : s2) cout << i << " ";
  return 0;
}