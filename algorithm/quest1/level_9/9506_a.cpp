#include <bits/stdc++.h>
using namespace std;

int a, i, sum;
vector<int> v;

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  while (true) {
    cin >> a;
    if (a == -1) break;
    
    sum = 0;
    i = 1;
    v.clear();

    while (i < a) {
      if (a % i == 0) {
        sum += i;
        v.push_back(i);
      }
      i++;
    }

    if (a == sum) {
      cout << a << " = ";
      for (int j = 0; j < v.size(); j++) {
        cout << v[j];
        if (j != v.size() - 1) {
          cout << " + ";
        }
      }
      cout << '\n';
    } else {
      cout << a << " is NOT perfect.\n";
    }
  }

  return 0;
}