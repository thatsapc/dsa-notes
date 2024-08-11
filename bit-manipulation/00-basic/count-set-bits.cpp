#include <iostream>
using namespace std;

/*
Guven an integer n, find the number of set bits in n.
Input: n = 5
Output: 2
Explanation: 5 = 000101, so there are 2 set bits in 5
*/

int countSetBits(int n){
  int count = 0;
  while(n >0){
    if((n&1) == 1){
      count++;
    }
    n = (n >> 1);
  }
  return count;
}

int main(){
  int n = 5;
  
  cout << countSetBits(n) << endl;
  return 0;
}