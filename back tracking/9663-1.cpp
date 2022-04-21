#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<numeric>

using namespace std;


static int cnt = 0;

void paint_chess(vector<vector<int>>& chess,int i, int j,int n){
  
  for(int x=0; x<n; x++){
    chess[i][x] = 0;
  }
  for(int y=0; y<n; y++){
    chess[y][j] = 0;
  }

  int x = j;
  int y = i;
  while(true){
    if(y>=n || x >=n) break;
    chess[y][x] = 0;
    ++x;
    ++y;
  }
  x = j;
  y = i;
  while(true){
    if(y>=n || x <0) break;
    chess[y][x] = 0;
    --x;
    ++y;
  }
  chess[i][j] = 2;
}

void print_chess(vector<vector<int>>& chess){
  for(int i=0; i<chess.size(); i++){
    for(int j=0; j<chess.size(); j++){
      cout << chess[i][j];
    }
    cout << '\n';
  }
}

void queen(vector<vector<int>>& chess,int nth, int n){
  if(nth==n){
    cnt += 1;
    // print_chess(chess);
    // cout << '\n';
    return ;
  }
  vector<vector<int>> prev_chess{chess};
  for(int j=0; j<n; j++){
    if(chess[nth][j]==1){
      paint_chess(chess,nth,j,n);
      queen(chess,nth+1,n);
      chess = prev_chess;
    }
  }
  return ;
}

int main(){
  int n;
  cin >> n;
  static vector<vector<int>> chess(n,vector<int>(n,1));
  queen(chess,0,n);
  cout << cnt << '\n';
}