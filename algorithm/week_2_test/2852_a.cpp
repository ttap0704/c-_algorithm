#include<bits/stdc++.h>
using namespace std;
#define prev test2
int n, o, A, B, asum, bsum;
string s, prev; 

string changeTime(int i) {
  string m = "00" + to_string(i / 60);
  string s = "00" + to_string(i % 60);
  return m.substr(m.size() - 2, 2) + ":" + s.substr(s.size() - 2, 2); 
}

int changeInt(string s) {
  return (stoi(s.substr(0, 2)) * 60) + stoi(s.substr(3));
}

void sumTime(int &sum, string s) {
  sum += changeInt(s) - changeInt(prev);
}

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> o >> s;

    if (A > B) sumTime(asum, s);
    else if (B > A) sumTime(bsum, s);
    
    if (o == 1) A++;
    else B++;
    prev = s;
  }

  if (A > B) sumTime(asum, "48:00");
  else if (B > A) sumTime(bsum, "48:00");

  cout << changeTime(asum) << "\n";
  cout << changeTime(bsum) << "\n";

  return 0;
}