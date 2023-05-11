#include <bits/stdc++.h>
using namespace std;

int a[15000];

int main () {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);

  int num = 1;
  while (num <= 10000) {
    int tmp = num;
    string s = to_string(num);
    for (char c : s) tmp += (c - '0');

    a[tmp] = 1;
    num++;
  }

  for (int i = 1; i <= 10000; i++) {
    if (!a[i]) cout << i << '\n';
  }

  return 0;
}