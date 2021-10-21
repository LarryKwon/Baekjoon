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
//   int count;
//   cin >> count;
//   while(count>0){
//     int n;
//     cin >> n;

//     vector<int> numbers;
//     for(int i = 0; i<=n;i++){
//       numbers.push_back(1);
//     }

//     numbers[0] = 0;
//     numbers[1] = 0;

//     for(int i = 2; i<=n;i++){
//       if(numbers[i]==0) continue;
//       for(int j = 2*i; j<=n; j+=i){
//         if(numbers[j] == 0) continue;
//         else{
//           numbers[j] = 0;
//         }
//       }
//     }

//     vector<pair<int,int>> partitions;
//     for(int i = n/2; i>=2;i--){
//       if(numbers[i] == 1){
//         int rest = n - i;
//         if(numbers[rest] == 1){
//           cout << i << " " << rest << '\n';
//           break;
//         }
//       }else{
//         continue;
//       }
//     }  

//     // int diff = n;
//     // pair<int,int>* result ;
//     // for(auto p:partitions){
//     //   if((p.second - p.first)<diff) result = &p;
//     // }
//     // cout << result->first << " " << result->second << '\n';
//     --count;
//   }
// }