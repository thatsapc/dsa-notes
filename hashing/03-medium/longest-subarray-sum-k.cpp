#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> A, int N, int K){
  unordered_map<int, int> sumidx;
  int maxlen = 0;
  int sum = 0;
  for (int i = 0; i < N; i++){
    sum += A[i];
    if(sum == K){
      maxlen = max(i + 1, maxlen);
    }
    else if(sumidx.find(sum - K) != sumidx.end()){
        maxlen = max(i - sumidx[sum - K], maxlen);
    }
    if(sumidx.find(sum) == sumidx.end()){
      sumidx[sum] = i;
    }
  }
  return maxlen;
}

int main(){
  // vector<int> arr = {10, 5, 2, 7, 1, 9};
  // int n = arr.size();
  // int k = 15;
  // cout << longestSubarray(arr, n, k) << endl;
  vector<int> arr2 = {1, 12, 18, 13, 8, -2, 12, -1, -10, 6, 3, -14, 0, 4, 10, 0, -7, 3, -12, 18};
  int n2 = arr2.size();
  int k2 = 30;
  cout << longestSubarray(arr2, n2, k2) << endl;
  return 0;
}