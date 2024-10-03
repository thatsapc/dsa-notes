#include <iostream>
using namespace std;

void print(string arr_name, int arr[], int n){
  cout << arr_name << "=[";
  for(int i = 0; i < n; i++){
    cout << arr[i];
    if(i < n-1){
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int splidx(int arr[], int n){
  int count = 0;
  int se[n];
  int so[n];
  
  for(int i = 0; i < n; i++){
    if(i == 0){
      se[i] = arr[i];
      so[i] = 0;
    }
    else{
      se[i] = (i%2 == 0) ? se[i-1] + arr[i] : se[i-1];
      so[i] = (i%2 == 0) ? so[i-1] : so[i-1] + arr[i];
    }
  }
  print("se",se,n);
  print("so",so, n);
  
  for(int i = 0; i < n; i++){
    int even = 0;
    int odd = 0;
    if(i == 0){
      even = so[n-1] - so[i];
      odd = se[n-1] - se[i];
    }
    else if(i == n-1){
      even = se[i-1];
      odd = so[i-1];
    }
    else{
      even = se[i-1] + so[n-1] - so[i];
      odd = so[i-1] + se[n-1] - se[i];
    }
    if(even == odd){
      count++;
    }
  }
  return count;
}

int main() 
{
    int n = 6;
    int arr[n] = {4,3,2,7,6,-2};
    cout << splidx(arr, n) << endl;
    return 0;
}