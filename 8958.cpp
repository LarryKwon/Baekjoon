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

// using namespace std;

// int point_calculator(const vector<char>& ox){
//   int sum = 0;
//   int point = 0;
//   for(auto p:ox){
//     if(p == 'O'){
//       point += 1;
//       sum += point;
//     }
//     else if(p == 'X'){
//       point = 0;
//     }
//   }
//   return sum;
// }

// int main(){
//   int n;
//   cin >> n;
//   vector<int> points;
//   cin.ignore();
//   while(n){
//     string line;
//     getline(cin,line);
//     istringstream iss{line};
//     char c;
//     vector<char> ox; 
//     while(iss.get(c)){
//       ox.push_back(c);
//     }
//     cout << point_calculator(ox) << '\n';
//     --n;
//   }
// }