#include <bits/stdc++.h>
using namespace std;

vector<string> a = {"사과", "딸기", "포도", "배"};

void go (int num) {
  string ret = "";
  for (int i = 0; i < a.size(); i++) {
    if (num & (1 << i)) {
      ret += a[i] + " ";
    }
  }

  cout << ret << '\n';
}

int main () {
  for (int i = 0; i < a.size(); i++) {
    go(1 | (1 << i));
  }
  return 0;
}