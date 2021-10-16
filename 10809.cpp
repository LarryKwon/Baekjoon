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

// using namespace std;


// int main(){
//   string line;
//   getline(cin,line);
//   map<char,int> characters;
//   for(char ch = 'a'; ch < '{';ch++){
//     characters[ch] = -1;
//   }

//   for(int i = 0; i<line.size();i++){
//     auto p = characters.find(line[i]);
//     if(p->second == -1){
//       p->second = i;
//     }
//   }
//   for(auto p:characters){
//     cout << p.second << " ";
//   }
// }