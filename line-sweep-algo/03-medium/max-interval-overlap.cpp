#include<bits/stdc++.h>
using namespace std;

vector<int> findMaxGuests(vector<int> Entry, vector<int> Exit, int N)
	{
	   // Your code goes here
	   sort(Entry.begin(), Entry.end());
	   sort(Exit.begin(), Exit.end());
	   int g = 1;
	   int maxg = 1;
	   int mint = Entry[0];
	   int n = 1, x = 0;
	   while(n < N && x < N){
	       if(Entry[n] <= Exit[x]){
	           g++;
	           if(maxg < g){
	               maxg = g;
	               mint = Entry[n];
	           }
	           n++;
	       }
	       else{
	           g--;
	           x++;
	       }
	   }
	   return {maxg, mint};
	}

int main(){
  vector<int> entry = {1, 2,10, 5, 5};
  vector<int> exit = {4, 5, 12, 9, 12};
  int N = entry.size();
  auto ans = findMaxGuests(entry, exit, N);
  for(auto a : ans){
    cout << a << " ";
  }
  cout << endl;
  return 0;
}