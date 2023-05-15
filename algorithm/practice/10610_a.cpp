#include <bits/stdc++.h>
using namespace std;

string N;
int ret = -1;
vector<char> v;

bool check (string num) {
  if (stoi(num) % 30 != 0) return false;

  sort(num.begin(), num.end());
  return num == N;
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;
  sort(N.begin(), N.end(), greater<>());

  if (N.back() != '0') cout << -1 << '\n';
  else {
    int sum = 0;
    
    for (char c : N) sum += (c - '0');

    if (sum % 3 == 0) cout << N << '\n';
    else cout << -1 << '\n';
  }

  return 0;
}