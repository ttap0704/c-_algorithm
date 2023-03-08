// 순열 : 1,2,3이 있을 때 -> 1,3,2 등으로 다른 순서로 섞는 연산
// n개의 집합 중 n개를 고르시오 = n!

// 1,2,3으로 만들 수 있는 3자리 자연수 = 3! / (3 - 3)!
// 1,2,3으로 만들 수 있는 1자리 자연수 = 3! / (3 - 1)!

// 첫 번째 방법
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printV(vector<int> &v) {
  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << " ";
  }
}

bool cmp(int a, int b) { 
  return a > b;
} 


int main () {
  int a[3] = {3, 1, 2};
  vector<int> v;
  for (int i = 0; i < 3; i++) v.push_back(a[i]);

  sort(v.begin(), v.end());
  do {
    printV(v);
  } while (next_permutation(v.begin(), v.end()));
  cout << "--------------" << "\n";
  v.clear();

  for (int i = 2; i >= 0; i--) v.push_back(a[i]);

  sort(v.begin(), v.end(), cmp);
  do {
    printV(v);
  } while(prev_permutation(v.begin(), v.end()));

  // next_permutation()을 사용할 때,
  // 오름차순으로 정렬 후 쓰는것이 중요!

  // prev_permutation()을 사용할 때,
  // 내림차순으로 정렬 후 쓰는것이 중요!

  return 0;
}