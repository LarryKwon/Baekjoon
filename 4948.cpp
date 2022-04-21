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
//   while(true){
//     int n;
//     cin >>  n;
//     if(n == 0) break;
//     vector<int> numbers;
//     for(int i = 0; i<=2*n;i++){
//       numbers.push_back(1);
//     }

//     numbers[0] = 0;
//     numbers[1] = 0;

//     for(int i = 2; i<=2*n;i++){
//       if(numbers[i]==0) continue;
//       for(int j = 2*i; j<=2*n; j+=i){
//         if(numbers[j] == 0) continue;
//         else{
//           numbers[j] = 0;
//         }
//       }
//     }
//     int cnt = 0;
//     for(int i = n+1; i<=2*n;i++){
//       if(numbers[i] == 1){
//         cnt += 1;
//       }
//     }
//     cout << cnt << '\n';
//   }
// }