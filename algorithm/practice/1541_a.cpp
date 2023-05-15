#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> a;
vector<char> b;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;
  string tmp = "";
  for (char c : s) {
    if (c >= '0' && c <= '9') {
      tmp += c;
    } else {
      a.push_back(stoi(tmp));
      b.push_back(c);

      tmp = "";
    }
  }
  a.push_back(stoi(tmp));

  vector<int> num;
  int sum = 0;
  for (int i = 0; i < a.size(); i++) {
    sum += a[i];
    if (i == a.size() - 1) {
      num.push_back(sum);
      break;
    }
    if (b[i] == '-') {
      num.push_back(sum);
      sum = 0;
    }
  }

  int ret = num[0];
  for (int i = 1; i < num.size(); i++) {
    ret -= num[i];
  }

  cout << ret << '\n';
  
  return 0;
}