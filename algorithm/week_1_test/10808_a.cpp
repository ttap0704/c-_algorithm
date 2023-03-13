#include <bits/stdc++.h>
using namespace std;
string s;
int a[26];

int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> s;

  // string -> char 타입으로 변환
  char arr[s.length() + 1]; 
	strcpy(arr, s.c_str()); 

  for (int i = 0; i < s.length(); i++) {
    int ascii = int(arr[i]);

    int alpha = ascii - 97;
    a[alpha]++;
  }

  for (int i = 0; i < 26; i++) {
    cout << a[i] << " ";
  }

  return 0;
}