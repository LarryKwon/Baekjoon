#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>

using namespace std;

// int main(){
//   int n1;
//   int n2;
//   int n3;
//   cin >> n1 >> n2 >> n3;

//   int multiple = n1 * n2 * n3;
//   map<int,int> counters;

//   while(multiple > 0){
//     int left = multiple % 10;
//     multiple = multiple / 10;
//     ++counters[left];
//   }
//   for(auto p:counters){
//     cout << p.second << '\n';
//   }
// }