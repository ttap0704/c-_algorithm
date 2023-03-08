// 구조체(struct)
// c++에서 제공하는 자료구조가 아닌, 개발자의 커스텀 자료구조


#include <bits/stdc++.h>
using namespace std;

struct Ralo {
  int a, b;
  double c, d, e;
};

void print(Ralo ralo){
  cout << ralo.a << " " << ralo.b << " " << ralo.c << " " << ralo.d << " " <<
  ralo.e << '\n'; 
}

int main () {
  Ralo ralo = {1, 1, 1, 1, 1}; 
  print(ralo);

  vector<Ralo> ret; 
  ret.push_back({1, 2, 3, 4, 5}); 
  ret.push_back({1, 2, 3, 4, 6}); 
  ret.push_back({}); 
  ret.push_back({1, 3}); 
  for(Ralo ralo : ret){
    print(ralo);
  }

  return 0;
}