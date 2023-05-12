#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
string s;
ll sum;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  
  int _size = s.size();
  for (int i = 1; i < _size; i++) {
    int m_num = pow(10, i - 1) * 9;

    sum += m_num * i;
    s = to_string(stoi(s) - m_num);
  }

  ll tmp = stoi(s);
  sum += tmp * _size;

  cout << sum <<'\n';
  return 0;
}