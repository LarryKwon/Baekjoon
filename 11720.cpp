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


// int main(){
//   int n;
//   cin >> n;
//   cin.ignore();
//   string line;
//   getline(cin,line);
//   istringstream ss{line};
//   char number;
//   vector<int> numbers;
//   while(ss.get(number)){
//     numbers.push_back(number - '0');
//   }
//   cout << accumulate(numbers.begin(),numbers.end(),0);
// }