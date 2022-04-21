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
//   int n;
//   cin >> n;
//   while(n>0){
//     int x1;
//     int y1;
//     int r1;

//     int x2;
//     int y2;
//     int r2;
//     cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

//     //pseudo code 
//     long long int dist = pow((x2-x1),2) + pow((y2-y1),2);
//     long int sub_radius = pow(r2-r1,2);
//     long int sum_radius = pow(r2+r1,2);
//     if(dist == 0){
//       if((sub_radius)==0){
//         cout << -1 << '\n';
//       }
//       else{
//         cout << 0 << '\n';
//       }
//     }else{
//       if(dist == sub_radius){
//         cout << 1 << '\n';
//       }else if(dist < sub_radius){
//         cout << 0 << '\n';
//       }else if(dist < sum_radius){
//         cout << 2 << '\n';
//       }else if(dist == sum_radius){
//         cout << 1 << '\n';
//       }else if(dist > sum_radius){
//         cout << 0 << '\n';
//       }else{
//         cout << "???" << '\n';
//       }
//     }
//     --n;
//   }
// }