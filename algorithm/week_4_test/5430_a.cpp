#include <bits/stdc++.h>
using namespace std;

int N, num;
string f, arr;
bool r = 0, error = 0;

// void print () {
// }

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N;

  while (N--) {
    cin >> f;
    cin >> num;
    cin >> arr;
   
    r = 0;
    error = 0;
    deque<int> dq;

    int x = 0;
    for (char c : arr) {
      if(c == '[' || c == ']') continue;
      if(c >= '0' && c <= '9') x = x*10 + c-'0';
      else{
        if(x > 0) dq.push_back(x);
        x = 0; 
      }
    }
    if (x > 0) dq.push_back(x);

    for (char c : f) {
      if (c == 'R') {
        r = !r;
      } else {
        if (dq.size() == 0) {
          error = true;
          break;
        } else {
          if (r) dq.pop_back();
          else dq.pop_front();
        }
      }
    }

    if (!error) {
      if (r) reverse(dq.begin(), dq.end());

      string answer = "";
      for (int i = 0; i < dq.size(); i++) {
        int num = dq[i];
        answer += to_string(num);
        if (i != dq.size() - 1) {
          answer += ',';
        }
      }

      cout << '[' << answer << "]\n";
    } else {
      cout << "error" << '\n';
    }
    
  }

  return 0;
}