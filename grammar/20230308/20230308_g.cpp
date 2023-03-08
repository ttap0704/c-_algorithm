#include <bits/stdc++.h>
using namespace std;

map<string, int> mp;
string a[] = {"김씨", "이씨", "박씨"};

int main () {
  for (int i = 0; i < 3; i++) {
    mp.insert({a[i], i + 1});
    mp[a[i]] = i + 1;
  }

  cout << mp["최씨"] << "\n";

  mp["최씨"] = 4;
  cout << mp.size() << "\n";

  mp.erase("최씨");
  auto it = mp.find("최씨"); 
  if(it == mp.end()){
    cout << "못찾겠네 꾀꼬리\n"; 
  }

  mp["최씨"] = 100;
  it = mp.find("최씨"); 
  if(it != mp.end()){
    cout << (*it).first << " : " << (*it).second << '\n';
  }

  for(auto it : mp){
    cout << (it).first << " : " << (it).second << '\n';
  }

  for(auto it = mp.begin(); it != mp.end(); it++){
    cout << (*it).first << " : " << (*it).second << '\n';
  }

  mp.clear();

  return 0;
}