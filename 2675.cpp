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

// string repeat(char c, int n){
//   string s = "";
//   for(int i = 0 ; i<n; i++){
//     s+= c;
//   }
//   return s;
// }

// int main(){
//   int n;
//   cin >>n;
//   while(n>0){
//     int count = 0;
//     cin >> count;
//     string characters;
//     cin >> characters;
//     string new_characters = "";
//     for(char c:characters){
//       new_characters += repeat(c,count);
//     }
//     cout << new_characters << '\n';
//     n--;
//   }
// }