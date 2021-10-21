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

//   pair<int,int> point;
//   vector<pair<int,int>> points;
//   for(int i = 0; i<3; i++){
//     int x,y;
//     cin >> x >> y;
//     point.first = x;
//     point.second = y;
//     points.push_back(point);
//   }

//   int x1_count = 1;
//   int x1 = points[0].first;
//   int x2_count = 0;
//   int x2;

//   for(int i = 1; i<3; i++){
//     if(points[i].first != x1){
//       x2_count += 1;
//       x2 = points[i].first;
//     }else{
//       x1_count += 1;
//     }
//   }

//   int result_x;
//   if(x1_count == 2){
//     result_x = x2;
//   }else{
//     result_x = x1;
//   }

//   int y1_count = 1;
//   int y1 = points[0].second;
//   int y2_count = 0;
//   int y2;

//   for(int i = 1; i<3; i++){
//     if(points[i].second != y1){
//       y2_count += 1;
//       y2 = points[i].second;
//     }else{
//       y1_count += 1;
//     }
//   }

//   int result_y;
//   if(y1_count == 2){
//     result_y = y2;
//   }else{
//     result_y = y1;
//   }

//   cout << result_x << " " << result_y << '\n';

  
// }