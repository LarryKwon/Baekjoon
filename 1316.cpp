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

int main(){
  int n;
  cin >> n;
  cin.ignore();
  set<char> characters;
  int count = 0;
  while(n>0){
    string line;
    getline(cin,line);
    auto p = line.begin();
    characters.insert(*p);
    while(p!=line.end()){
      if(is_sequence(p)){
        if(find(characters.begin(),characters.end(),*p)==characters.end()){
          characters.insert(*p);
        }  
        ++p;
      }
      else{
        string::iterator next = p;
        ++next;
        if(find(characters.begin(),characters.end(),*next)!=characters.end()){
          --n;
          break;
        }
        else{
          characters.insert(*next);
          ++p;
        }
      }
    }
    if(p==line.end()){
      count += 1;
      --n;
    }
  }
  cout << count << '\n';
}