#include <iostream>
#include <vector>
using namespace std;

int xmod11(string x){
  int num = 0;
  int base = 1; // 10 power 0;
  for (int i = x.size() - 1; i >= 0; i--){
    int digit = x[i] - '0';
    num = (num + ((digit % 11) * base) % 11) % 11;
    base = (base * 10) % 11;
  }
  return num;
}

int main(){
  string x = "231456786543567898765";
  cout << xmod11(x) << endl;
  return 0;
}