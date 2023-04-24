#include <bits/stdc++.h>
using namespace std;

string a, b;
int cnt = 0;
double num, sum = 0, sum2 = 0;
map<string, double> mp {
  {"A+", 4.5},
  {"A0", 4.0},
  {"B+", 3.5},
  {"B0", 3.0},
  {"C+", 2.5},
  {"C0", 2.0},
  {"D+", 1.5},
  {"D0", 1.0},
  {"F", 0.0},
};

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  for (int i = 0; i < 20; i++) {
    cin >> a >> num >> b;

    if (b != "P") {
      sum += num * mp[b];
      sum2 += num;
      cnt++;
    }
  }

  cout.precision(6);
  cout << fixed;
  cout << sum / sum2 << '\n';

  return 0;
}