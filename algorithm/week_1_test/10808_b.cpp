// 10808 복습
#include <bits/stdc++.h>
using namespace std;

string s;
int alpha[26];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  for (char i : s) alpha[i - 'a']++;

  for (int i = 0; i < 26; i++) {
    cout << alpha[i] << " ";
  }

  return 0;
}