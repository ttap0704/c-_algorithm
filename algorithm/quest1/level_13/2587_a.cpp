#include <bits/stdc++.h>
using namespace std;

int num, avg;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 5; i++) {
    cin >> num;
    v.push_back(num);
    avg += num / 5;
  }

  sort(v.begin(), v.end());

  cout << avg << '\n';
  cout << v[2] << '\n';

  return 0;
}