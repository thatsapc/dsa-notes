#include <iostream>
#include <vector>
using namespace std;

bool isValid(string str){
  // count dots
  int n = str.size();
  int countdots = 0;
  for (int i = 0; i < n; i++){
    if(str[i] == '.') countdots++;
  }
  if(countdots != 3){
    //cout << "dots:" << countdots << endl;
    return false;
  }
  string numstr = "";
  for (int i = 0; i <= n; i++){
    if(str[i] == '.' || i == n){
      if(numstr.size() == 0){
        return false;
      }
      //cout << numstr << endl;
      if(numstr[0] == '0' && numstr.size() != 1){
        //cout << "Leading zeros:" << numstr << endl;
        return false;
      }
      int num = stoi(numstr);
      if(num > 255){
        //cout << "> 255:" << num << endl;
        return false;
      }
      numstr = "";
    }
    else if(str[i] - '0' > 9 || str[i] - '0' < 0){
      //cout << "not a digit:" << str[i] << endl;
      return false;
    }
    else{
      numstr += str[i];
    }
  }
  return true;
}

int main(){
  string str = "125.172.0.6";
  cout << isValid(str) << endl;
  string str1 = ".172.0.6";
  string str2 = "125.0172.0.6";
  string str3 = "125.172.6";
  string str4 = "125.a.172.6";
  cout << isValid(str1) << endl;
  cout << isValid(str2) << endl;
  cout << isValid(str3) << endl;
  cout << isValid(str4) << endl;
  return 0;
}