#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<numeric>

using namespace std;


// int main(){
//   int n;
//   cin >> n;
//   cin.ignore();
//   while(n){
//     string line;
//     getline(cin,line);
//     istringstream iss{line};
//     int num = 0;
//     iss >> num;
    
//     vector<int>points;
//     int point = 0;
//     while(iss >> point){
//       points.push_back(point);
//     }
//     double average = accumulate(points.begin(),points.end(),0)/points.size();
//     double count = 0;
//     for(auto point: points){
//       if(point > average){
//         count += 1;
//       }
//     }
//     double ratio = count / points.size() * 100;
//     cout << fixed;
//     cout.precision(3);
//     cout << ratio << '%'<<'\n';
//     --n;
//   }
// }