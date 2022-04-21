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

void print(vector<vector<int>>& table){
  for(auto p: table){
    for(auto q: p){
      cout << q << ' ';
    }
    cout << '\n';
  }
}



int main(){
  string first;
  string second;
  getline(cin,first);
  getline(cin,second);

  vector<vector<int>> table(first.size()+1,vector<int>(second.size()+1));

  int first_len = first.size();
  int second_len = second.size();
  
  for(int i=0; i<first_len; i++){
    for(int j=0; j<second_len; j++){
      if(first[i] == second[j]){
        table[i+1][j+1] = table[i][j] + 1;
      }
      else{
        table[i+1][j+1] = max(table[i][j+1],table[i+1][j]);
      }
    }  
  }

  int max = 0;
  for(auto p: table){
    for(auto q: p){
      if(max < q) max = q;
    }
  }

  cout << max << '\n';
}