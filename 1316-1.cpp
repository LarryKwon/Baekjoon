#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<numeric>

using namespace std;

bool is_sequence(string::iterator p){
  string::iterator next = p;
  ++next;
  if(*p == *next){ return true;}
  return false;
}

bool is_group(string& line, map<char,int>&characters){
  for(int i = 0; i<line.size();i++){
    char c = line[i];
    int pos = characters[c];
    if(pos == -1){
      characters[c] = i;
    }else{
      if((i - pos) == 1){
        characters[c] = i;
      }
      else{
        return false;
      }
    }
  }
  return true;
}

int main(){
  int n;
  cin >> n;
  cin.ignore();
  map<char,int> characters;
  int count = 0;
  while(n>0){
    string line;
    getline(cin,line);
    for(auto p:line){
      characters[p] = -1;
    }
    if(is_group(line,characters)){
      count += 1;
      // cout << line <<'\n';
    }
    --n;
  }
  cout << count << '\n';
}