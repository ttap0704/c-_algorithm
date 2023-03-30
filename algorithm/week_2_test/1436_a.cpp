#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int N;
string s;
ll pos, cnt = 0, num = 665;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  while (N != cnt) {
    num++;
    s = to_string(num);
    pos = s.find("666");
    if (pos != string::npos) {
      cnt++;
    }
  }

  cout << num << "\n";

  return 0;
}