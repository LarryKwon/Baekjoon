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

// bool compare(pair<int,int> a, pair<int,int> b){
//   if(a.first < b.first) return true;
//   else if(a.first == b.first){
//     if(a.second < b.second) return true;
//     return false;
//   }else{
//     return false;
//   }
// }

// int main(){
//   int n;
//   vector<pair<int,int>> points;
//   cin >> n;
//   while(n>0){
//     int x;
//     int y;
//     cin >> x>> y;
//     pair<int,int> point(x,y);
//     points.push_back(point);
//     --n;
//   }
//   sort(points.begin(),points.end(),compare);
//   for(auto p:points){
//     cout << p.first << ' ' << p.second << '\n';
//   }
// }