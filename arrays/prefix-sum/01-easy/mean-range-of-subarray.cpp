#include <iostream>
#include <vector>
using namespace std;

/*Given an array of n integers. You are given q queries. Write a program to print floor value of mean in range l to r for each query in a new line.

Examples : 

Input : arr[] = {1, 2, 3, 4, 5}
        q = 3
        0 2
        1 3
        0 4
Output : 2
         3
         3
Here for 0 to 2 (1 + 2 + 3) / 3 = 2

Input : arr[] = {6, 7, 8, 10}
        q = 2
        0 3
        1 2
Output : 7
         7*/

void print(vector<int> a){
  cout << "[";
  for(int i = 0; i < a.size(); i++){
    cout << a[i];
    if(i < a.size()-1){
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

vector<int> meanOfSubarray(int arr[], int n, int Q[], int q){
  vector<int> res;
  for (int i = 1; i < n; i++){
    arr[i] += arr[i - 1];
  }
  for (int i = 0; i < 2*q; i = i+2){
    // sum from arr[Q[i]] to arr[Q[i+1]]
    int sum = 0;
    if(Q[i] == 0){
      sum = arr[Q[i + 1]];
    }
    else{
      sum = arr[Q[i + 1]] - arr[Q[i] - 1];
    }
    res.push_back(sum / (Q[i + 1] - Q[i] + 1));
  }
    return res;
}

int main() 
{
   int n1 = 5;
  int arr1[n1] = {1, 2, 3, 4, 5};
  int q1 = 3;
  int Q[2 * q1] = {0, 2, 1, 3, 0, 4};
  print(meanOfSubarray(arr1, n1, Q, q1));
  return 0;
}