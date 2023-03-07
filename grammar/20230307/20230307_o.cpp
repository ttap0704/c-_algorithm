#include <bits/stdc++.h>
using namespace std;

vector<int> a;
int b[5];

int main() {
  for(int i = 5; i >= 1; i--) b[i - 1] = i; 
  for(int i = 5; i >= 1; i--) a.push_back(i);

  // 배열쓸떄
  sort(b, b + 5);
  // vector 쓸때
  sort(a.begin(),a.end()); 
  for(int i : b) cout << i << ' '; 
  cout << '\n';
  for(int i : a) cout << i << ' '; 
  cout << '\n';

  // 배열 오름차순
  sort(b, b + 5, less<int>()); 
  // vector 오름차순
  sort(a.begin(),a.end(), less<int>()); 
  for(int i : b) cout << i << ' '; 
  cout << '\n';
  for(int i : a) cout << i << ' '; 
  cout << '\n';

  // 배열 내림차순
  sort(b, b + 5, greater<int>()); 
  // vector 내림차순
  sort(a.begin(),a.end(), greater<int>()); 
  for(int i : b) cout << i << ' ';
  cout << '\n';
  for(int i : a) cout << i << ' ';
  cout << '\n';

  return 0;
}