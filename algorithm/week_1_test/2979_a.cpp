#include <bits/stdc++.h>
using namespace std;
int A, B, C;
int park1_s, park1_e, park2_s, park2_e, park3_s, park3_e;
map<int, int> total;
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> A >> B >> C;
  int price[3] = {A, B, C};
  vector<int> keys;
  cin >> park1_s >> park1_e;
  cin >> park2_s >> park2_e;
  cin >> park3_s >> park3_e;

  for (int i = park1_s; i < park1_e; i++) {
    total[i]++;
    keys.push_back(i);
  }

  for (int i = park2_s; i < park2_e; i++) {
    total[i]++;
    keys.push_back(i);
  }

  for (int i = park3_s; i < park3_e; i++) {
    total[i]++;
    keys.push_back(i);
  }

  sort(keys.begin(), keys.end());
  keys.erase(unique(keys.begin(),keys.end()),keys.end());

  int sum = 0;
  // for (int i : keys) cout << "total " << i << " : " << price[total[i] - 1] << "\n"; 
  for (int i : keys) sum += price[total[i] - 1] * total[i]; 
  cout << sum << "\n";
  return 0;
}