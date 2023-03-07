// lower_bount, upper_bound()

// 정렬된 배열에서 어떤 값이 나오는 첫번째 지점, 초과하는 지점 위치 찾기

#include <bits/stdc++.h>
using namespace std;

int main () {
  vector<int> a {1, 2, 3, 3, 3, 4};
  cout << lower_bound(a.begin(), a.end(), 3) - a.begin() <<
"\n"; // 2
cout << upper_bound(a.begin(), a.end(), 3) - a.begin() <<
"\n"; // 5

  return 0;
}