// 만약 숫자로 되어있는 문자에 ++증감연산자를 통해 1을 더하면 
// 아스키코드에서 + 1 한 값이 됨

// 문자열 'A'를 string 변에수 저장하면
// 'A'문자 자체가 아닌, 'A'의 ASCII코드 값 65가 저장됨

#include <bits/stdc++.h>
using namespace std; 
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s = "123";
  s[0]++;
  cout << s << "\n"; // 223

  string s2 = "A";
  s2[0]++;
  cout << s2 << "\n"; // B
return 0; }