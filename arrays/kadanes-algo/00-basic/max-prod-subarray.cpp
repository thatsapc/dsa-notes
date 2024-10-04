#include <iostream>
#include <vector>
using namespace std;

int main(){
  vector<int> arr = {0, 2, 3, -1, -2};
  int n = arr.size();
  int maxprod = INT_MIN;
  int minprod = INT_MAX;
  int ans = INT_MIN;

  for (int i = 0; i < n; i++){
    // swap min and max if arr[i] is -ve
    if(arr[i] < 0){
      swap(maxprod, minprod);
    }
    minprod = min(arr[i], arr[i] * minprod);
    maxprod = max(arr[i], arr[i] * maxprod);
    ans = max(maxprod, ans);
  }
  cout << "Maxprod: " << ans << endl;
  return 0;
}