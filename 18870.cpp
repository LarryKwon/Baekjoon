// #include<iostream>
// #include<sstream>
// #include<fstream>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<stdexcept>
// #include<memory>
// #include<vector>
// #include<list>
// #include<map>
// #include<set>
// #include<numeric>

// using namespace std;

// int main(){
//   map<int,int> coordinates;
//   vector<int> numbers;

//   int n;
//   cin >> n;
//   while(n>0){
//     int number;
//     cin >> number;
//     numbers.push_back(number);
//     coordinates[number] = 0;
//     --n;
//   }
  
//   int i = 0;
//   for(auto it = coordinates.begin();it!=coordinates.end();++it){
//     it->second = i;
//     ++i;
//   }

//   for(auto p: numbers){
//     int coordinate = coordinates.find(p)->second;
//     cout << coordinate << " ";
//   } 
// }