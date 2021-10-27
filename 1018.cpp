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

void copy_board (vector<vector<char>>& board, vector<vector<char>>& chess,int x, int y){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      chess[i][j] = board[x+i][y+j]; 
    }
  }
}

int case_white(const vector<vector<char>>& chess){
  
  char correct = 'B';
  int count = 0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if((i+j)%2==0){
        correct = 'W';
      }else{
        correct = 'B';
      }
      if(chess[i][j]!=correct){
        count += 1;
      }
    }
  }
  // cout << "case_white:" << count << '\n';
  return count;
}

int case_black(const vector<vector<char>>& chess){
  char correct = 'B';
  int count = 0;
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      if((i+j)%2==0){
        correct = 'B';
      }else{
        correct = 'W';
      }
      if(chess[i][j]!=correct){
        count += 1;
      }
    }
  }
  // cout << "case_black:" << count << '\n';
  return count;
}

int main(){
  int n;
  int m;
  cin >> n >> m;
  cin.ignore();
  vector<vector<char>> board(n,vector<char>(m));
  for(int i=0;i<n;i++){
    string line;
    getline(cin,line);
    for(int j=0;j<m;j++){
      board[i][j] = line[j];
    }
  }

  vector<vector<char>> chess(8,vector<char>(8));
  int y_move = n-7;
  int x_move = m-7;

  // cout << '\n';

  int count = 32;
  for(int i=0; i<y_move;i++){
    for(int j=0; j<x_move;j++){
      copy_board(board,chess,i,j);
      int cnt_white = case_white(chess);
      int cnt_black = case_black(chess);
      if(count > min(cnt_white,cnt_black)){
        count = min(cnt_white,cnt_black);
      }
    }
  }
  cout << count << '\n';

 
}