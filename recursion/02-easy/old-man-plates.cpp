#include<bits/stdc++.h>
using namespace std;

void toh(int plates, int from, int to, int use, vector<pair<int, int>> &moves){
  if(plates == 1){
    pair<int, int> p = {from, to};
    moves.push_back(p);
    return;
  }
  toh(plates - 1, from, use, to, moves);
  pair<int, int> p = {from, to};
  moves.push_back(p);
  toh(plates - 1, use, to, from, moves);
}

vector<int> shift(int N, int n){
  vector<pair<int, int>> moves;
  toh(N, 1, 3, 2, moves);
  vector<int> res = {moves[n-1].first, moves[n-1].second};
  return res;
}

int main(){
  int plates = 2;
  int n = 2;
  vector<int> res = shift(plates, n);
  for(auto r : res){
    cout << r << " ";
  }
  cout << endl;
  return 0;
}