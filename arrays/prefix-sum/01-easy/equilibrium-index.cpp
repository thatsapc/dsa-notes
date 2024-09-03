#include <iostream>
using namespace std;
/*Given an array arr[] of size n, return the first equilibrium index (if any) or -1 if no equilibrium index exists. The equilibrium index of an array is an index such that the sum of elements at lower indexes equals the sum of elements at higher indexes.

Note: Return equilibrium point in 1-based indexing. Return -1 if no such point exists. 

Examples:

Input: arr[] = {-7, 1, 5, 2, -4, 3, 0}
Output: 4
Explanation: In 1-based indexing, 4 is an equilibrium index, because: arr[1] + arr[2] + arr[3] = arr[5] + arr[6] + arr[7]

Input: arr[] = {1, 2, 3}
Output: -1
Explanation: There is no equilibrium index in the array.*/

int equilibriumBruteForce(int arr[], int n){
  // Brute Force: TC = O(N^2); SC = O(1)
  // Iterate from i-1 to 0 and i+1 to n-1 for each index
  for (int i = 0; i < n; i++)
  {
    int left = 0, right = 0;
    for (int j = i - 1; j >= 0; j--)
    {
      left += arr[j];
    }
    for (int j = i + 1; j <= n - 1; j++)
    {
      right += arr[j];
    }
    // cout <<"arr["<<i<<"]="<<arr[i]<<" left="<<left<<" right="<<right<<endl;
    if (left == right)
    {
      return i + 1;
    }
  }
  return -1;
}

int equilibriumTimeSpaceOptimized(int arr[], int n){
  // Optimized: TC = O(N); SC = O(1)
  // in place calculation for left and right sum
  int right = 0;
  for (int i = 1; i < n; i++){
    right += arr[i];
  }
  int left = 0;
  for (int i = 1; i < n-1 ; i++){
    left += arr[i-1];
    right -= arr[i];
    // cout <<"arr["<<i<<"]="<<arr[i]<<" left="<<left<<" right="<<right<<endl;
    if(left == right){
      return i + 1;
    }
  }
  return -1;
}


int main() 
{
   int n1 = 7;
  int arr1[7] = {-7, 1, 5, 2, -4, 3, 0};
  cout << equilibriumBruteForce(arr1, n1) << endl;
  cout << equilibriumTimeSpaceOptimized(arr1, n1) << endl;
  return 0;
}