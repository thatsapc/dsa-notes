#include<bits/stdc++.h>
using namespace std;

class StackWithMin{
    stack<int> st;
    stack<int> minst;
  public:
    void push(int data){
      st.push(data);
      if(minst.empty()){
        minst.push(data);
      }
      else{
        int curmin = min(data, minst.top());
        minst.push(curmin);
      }
    }
  public:
    void pop(){
      st.pop();
      minst.pop();
    }
  public:
    int getMin(){
      return minst.top();
    }
};

class StackOpt{
  public:
    stack<int> st;
    stack<int> minst;
    void push(int data){
      st.push(data);
      if(minst.empty() || data <= minst.top()){
        minst.push(data);
      }
    }
    void pop(){
      if(minst.empty() && st.empty()){
        return;
      }
      if(!minst.empty() && minst.top() == st.top()){
        minst.pop();
      }
      st.pop();
    }
    int getMin(){
      if(minst.empty()){
        return -1;
      }
      return minst.top();
    }
};

int main(){
  // StackWithMin st;
  StackOpt st;
  st.push(5);
  st.push(3);
  st.push(10);
  cout << st.getMin() << endl;
  st.push(1);
  cout << st.getMin() << endl;
  st.pop();
  cout << st.getMin() << endl;
  return 0;
}