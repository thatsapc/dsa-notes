#include<iostream>
using namespace std;

/*Given an array A of size N. The task is to find the length of smallest subarray which contains both maximum and minimum values.

Examples: 

Input : A[] = {1, 5, 9, 7, 1, 9, 4}
Output : 2
subarray {1, 9} has both maximum and minimum value.

Input : A[] = {2, 2, 2, 2}
Output : 1
2 is both maximum and minimum here.*/

int minSubaarayOptimized(int arr[], int n){
  int minlen = INT_MAX;
  int maxi = INT_MIN;
  int mini = INT_MAX;
  for (int i = 0; i < n; i++){
    maxi = max(arr[i], maxi);
    mini = min(arr[i], mini);
  }
  int pmaxi = -1, pmini = -1;
  for (int i = 0; i < n; i++){
    if(arr[i] == maxi){
      pmaxi = i;
    }
    if(arr[i] == mini){
      pmini = i;
    }
    if(pmini != -1 && pmaxi != -1){
      int len = abs(pmaxi - pmini) + 1;
      minlen = min(len, minlen);
    }
  }
  return minlen;
}

int main() 
{
   int n1 = 7;
   int arr1[7] = {1, 5, 9, 7, 1, 9, 4};
   cout << minSubaarayOptimized(arr1, n1) << endl;
   return 0;
}
