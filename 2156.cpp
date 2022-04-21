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

// // int calculate(vector<int>& amounts,vector<int>& maxes,int n){
// //   if(n == 0){
// //     return maxes[0];
// //   }else if(n == 1){
// //     return maxes[1];
// //   }else if(n == 2){
// //     return maxes[2];
// //   }else{
// //     int max_n1;
// //     int max_n2;
// //     int max_n3;
// //     if(maxes[n-1]!=0){
// //       max_n1 = maxes[n-1];
// //     }else{
// //       max_n1 = calculate(amounts,maxes,n-1);
// //     }
    
// //     if(maxes[n-2]!=0){
// //       max_n2 = maxes[n-2];
// //     }else{
// //       max_n2 = calculate(amounts,maxes,n-2);
// //     }

// //     if(maxes[n-3]!=0){
// //       max_n3 = maxes[n-3];
// //     }else{
// //       max_n3 = calculate(amounts,maxes,n-3);
// //     }

// //     int max_n = max(max_n1,max(amounts[n]+amounts[n-1]+max_n3,amounts[n]+max_n2));
// //     maxes[n] = max_n;
// //     return maxes[n];
// //   }
// // }

// int main(){
//   int n;
//   cin >> n;
//   int cycle = n;
//   vector<int> amounts;
//   amounts.push_back(0);
//   while(cycle>0){
//     int amount;
//     cin >> amount;
//     amounts.push_back(amount);
//     --cycle;
//   }
//   vector<int> maxes(n+1);
//   maxes[1] = amounts[1];
//   maxes[2] = amounts[1] + amounts[2];

//   for(int i=3; i<=n; i++){
//     int max_n1;
//     int max_n2;
//     int max_n3;
//     max_n1 = maxes[i-1];
//     max_n2 = maxes[i-2];
//     max_n3 = maxes[i-3];
//     maxes[i] = max(max_n1,max(amounts[i]+amounts[i-1]+max_n3,amounts[i]+max_n2));
//   }

//   cout << maxes[n] << '\n';
// }