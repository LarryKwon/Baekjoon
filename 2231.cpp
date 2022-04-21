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

// int decomposition(int n){
//   int sum = n;
//   while(n>0){
//     sum = sum + n%10;
//     n = n/10;
//   }
//   return sum;
// }

// int main(){
//   int n;
//   cin >> n;
//   int number = n;
//   int digit = 0;
//   while(number > 0){
//     number = number/10;
//     ++digit;
//   }
//   // cout << digit << '\n';
//   int min_number = n - 9*digit;
//   for(int i = min_number; i<n;i++){
//     int sum = decomposition(i);
//     if(sum == n){
//       cout << i << '\n';
//       return 0;
//     }
//   }
//   cout << 0 << '\n';
//   return 0;
// }