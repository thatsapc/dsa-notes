#include <iostream>
using namespace std;

/* Given an array, A[N], where every element repeats itself except two. Find both the unique elements.
Input: A[8]: {1,5,10,2,10,3,3,1}
Output: {5,2}
Explanation: 1, 10 and 3 repeat whereas 5 and 2 dont.
*/

int findLsb(int n){
  int pos = 0;
  while((n&1) == 0){
    pos++;
    n = (n >> 1);
  }
  return pos;
}

void findUnique(int a[], int n){
  // xor all elements
  int all = 0;
  for (int i = 0; i < n; i++){
    all = (all ^ a[i]);
  }
  
  // cout << "all: " << all << endl;
  int lsb = findLsb(all);
  // cout << "lsb: " << lsb << endl;

  int num1 = 0, num2 = 0;

  for (int i = 0; i < n; i++){
    if((a[i] & (1 << lsb)) > 0){
      num1 = (num1 ^ a[i]);
    }
    if((a[i] & (1 << lsb)) == 0){
      num2 = (num2 ^ a[i]);
    }
  }
  cout << "num1: " << num1 << " num2: " << num2 << endl;
}

int main(){
  int a[6] = {5,9,8,8,5,0};
  findUnique(a, 6);
  return 0;
}