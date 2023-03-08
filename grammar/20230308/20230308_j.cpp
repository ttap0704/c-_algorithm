#include <bits/stdc++.h>
using namespace std;

int main () {
  // set은 고유한 요소만을 저장하는 컨테이너
  // 중복을 혀용하지 않음

  set<pair<string, int>> st;
  st.insert({"test", 1});
  st.insert({"test", 1});
  st.insert({"test", 1});
  st.insert({"test", 1});
  cout << st.size() << "\n";

  set<int> st2;
  st2.insert(2);
  st2.insert(1);
  st2.insert(2);
  for (auto it : st2) {
    cout << it << "\n";
  }

  // multiset은 중복되는 요소도 넣을 수 있음
  multiset<int> st3;
  for(int i = 5; i >= 1; i--){ 
    st3.insert(i);
    st3.insert(i);
  }
  for(int it : st3) {
    cout << it << " "; 
  }

  return 0;
}