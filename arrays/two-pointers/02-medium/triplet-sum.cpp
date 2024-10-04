#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool tripletExists(vector<int> &arr, int x){
  sort(arr.begin(), arr.end());
  int n = arr.size();
  for (int i = 0; i <= n - 3; i++){
    int j = i + 1;
    int k = n - 1;
    while(j < k){
      int sum = arr[i] + arr[j] + arr[k];
      if(sum == x){
        return true;
      }
      else if(sum > x){
        k--;
      }
      else{
        j++;
      }
    }
  }
  return false;
}

int main(){
  vector<int> arr = {40, 20, 10, 3, 6, 7};
  int x = 24;
  cout << tripletExists(arr, x) << endl;
  vector<int> arr2 = {1, 4, 45, 6, 10, 8};
  int x2 = 13;
  cout << tripletExists(arr2, x2) << endl;
  vector<int> arr3 = {1, 2, 4, 3, 6};
  int x3 = 10;
  cout << tripletExists(arr3, x3) << endl;
  return 0;
}