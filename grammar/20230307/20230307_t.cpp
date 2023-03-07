// lower_bound, upper_bound를 통해 구한 이터레이터에
// 해당 주소 값인 a.begin()을 빼주면

// 해당 컨테이너의 요소
// 주소값에 주소값을 빼면 해당 주소값이 컨테이너의 몇 번째임을 알 수 있음

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main () {
  vector<int> a {1, 2, 3, 3, 3, 4};
  cout << &*lower_bound(a.begin(), a.end(), 3) << "\n";
  cout << &*a.begin() << "\n";
  cout << &*(a.begin() + 1) << "\n";

  cout << lower_bound(a.begin(), a.end(), 3) - a.begin() <<
"\n";

  vector<int> b {0, 0, 0, 0};
  cout << &*(b.begin() + 3) - &*b.begin() << "\n";
  cout << &*(b.begin() + 3)  << "\n";

  vector<int> c {1, 2, 3, 3, 3, 3, 5, 100};
  cout << upper_bound(c.begin(), c.end(), 3) - lower_bound(c.begin(), c.end(), 3);
  return 0;
}