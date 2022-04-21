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
  for(int y=i; y<n; y++){
    chess[y][j] = 0;
  }

  for(int x=j; x<n; x++){
    chess[i][x] = 0;
  }
  
  for(int y=i;y>=0;y--){
    chess[y][j] = 0;
  }

  for(int x=j; x>=0; x--){
    chess[i][x] = 0;
  }

  int y = i;
  int x = j;
  while(true){
    if(x>=n || y >=n){
      break;
    }
    chess[y][x] = 0;
    ++x;
    ++y;
  }
  
  y = i;
  x = j;
  while(true){
    if(x>=n || y<0){
      break;
    }
    chess[y][x] = 0;
    ++x;
    --y;
  }
  
  y = i;
  x = j;
  while(true){
    if(x<0 || y >=n){
      break;
    }
    chess[y][x] = 0;
    --x;
    ++y;
  }
  
  y = i;
  x = j;
  while(true){
    if(x<0 || y <0){
      break;
    }
    chess[y][x] = 0;
    --x;
    --y;
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
    print_chess(chess);
    cout << '\n';
    return ;
  }
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      vector<vector<int>> prev_chess{chess};
      if(chess[i][j]==1){
        paint_chess(chess,i,j,n);
        queen(chess,nth+1,n);
        chess = prev_chess;
      }
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