#include <bits/stdc++.h>
using namespace std;

vector<string> a = {"사과", "딸기", "포도", "배"};

int main () {
  int a_size = a.size();

  for (int i = 0; i < (1 << a_size); i++) {
    string ret = "";
    for (int j = 0; j < a_size; j++) {
      if (i & (1 << j)) {
        ret += a[j] + " ";
      }
    }    
    cout << ret << "\n";
  }

  return 0;
}