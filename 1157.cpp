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

// struct great{
//   bool operator()(const pair<int,char>& a, const pair<int,char>& b){
//     return a.first > b.first;
//   }
// };

// int main(){
//   string line;
//   getline(cin,line);

//   for(auto p = line.begin(); p!= line.end();++p){
//     *p = toupper(*p);
//   }

//   map<char,int> characters;
//   for(auto p:line){
//     ++characters[p];
//   }

//   vector<pair<int,char>> sorted_count;
//   for(auto p:characters){
//     pair<int,char> count(p.second,p.first);
//     sorted_count.push_back(count);
//   }
//   sort(sorted_count.begin(),sorted_count.end(),great());
//   if(sorted_count[0].first == sorted_count[1].first){
//     cout << '?' << '\n';
//   }
//   else{
//     cout << sorted_count[0].second << '\n';
//   }
  
// }