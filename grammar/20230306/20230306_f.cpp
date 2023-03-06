#include <bits/stdc++.h>
using namespace std;

int main () {
  string a = "love is";
  a += " pain!";
  a.pop_back(); // 맨 뒤의 문자 빼기 : O(1)의 시간복잡도

  cout << a << " : " << a.size() << "\n";
  cout << char(* a.begin()) << '\n'; // 문자열의 시작
  cout << char(* (a.end() - 1)) << '\n'; // 문자열의 마지막 그 다음 : -1 >> 마지막 문자열

  a.insert(0, "test "); // 특정위치에 문자열 삽입 : O(n)의 시간복잡도
  cout << a << " : " << a.size() << "\n";

  a.erase(0, 5); // 특정위치에 "크기"만큼 문자열을 지움 : O(n)의 시간복잡도
  cout << a << " : " << a.size() << "\n";

  // find() : 특정 문자열을 찾아 위치를 반환
  // 못 찾을 경우 : string::npos를 리턴 O(n)의 시간복잡도
  // string::npos는 size_t 타입의 최대값 :최대값은 OS에 따라 달라짐
  
  auto it = a.find("love"); 
  if (it != string::npos) {
    cout << "포함되어 있다." << "\n";
  }

  cout << it << '\n';
  cout << string::npos << '\n';

  cout << a.substr(5, 2) << '\n';

  return 0;
}