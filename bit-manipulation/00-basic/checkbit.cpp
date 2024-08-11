#include <iostream>
using namespace std;
// link: https://www.google.com
/*
Given an integer n and another i, check if the ith bit is set or unset.
Input: n=5, i=3
Output: true
Explanation: 5 in binary = 101. Therefore the 3rd bit from right is set, so return true.
*/

bool checkbit(int n, int i){
  return (n & (1 << i));
}

int main() {
  int n = 5;
  int i = 2;
  cout << checkbit(n, i-1) << endl;
  return 0;
}

