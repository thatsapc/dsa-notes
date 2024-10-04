//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User-function template for C++

// Complete the function
// n: Input n
// Return True if the given number is a lucky number else return False

class Solution{
public:
    bool check(int n, int rem){
        if(n < rem){
            return true;
        }
        if(n % rem == 0)
        {
            return false;
        }
        else{
            int next = (n - (n /rem));
            return check(next, ++rem);
        }
    }
    bool isLucky(int n) {
        // code here
        int rem = 2;
        return check(n, rem);
    }
};

//{ Driver Code Starts.
signed main(){
  int n = 13;
  Solution obj;
  // calling isLucky() function
  if (obj.isLucky(n))
    cout << "1\n"; // printing "1" if isLucky() returns true
  else
    cout << "0\n"; // printing "0" if isLucky() returns false
}
// } Driver Code Ends