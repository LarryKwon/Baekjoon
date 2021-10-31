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
//   int cycle = n;
//   vector<int> numbers;
//   numbers.push_back(0);
//   while(cycle >0){
//     int number;
//     cin >> number;
//     numbers.push_back(number);
//     --cycle;
//   }
//   vector<int> forward(n+1);
//   vector<int> reverse(n+1);
//   vector<int> counts(n+1);
  
//   forward[0] = 0;
//   reverse[0] = 0;

//   forward[1] = 0;
//   reverse[n] = 0;
  
//   counts[0] = 0;

//   for(int i=1; i<=n; i++){
//     int forward_max = 0;
//     for(int j=1; j<i;j++){
//       if(numbers[j] < numbers[i]){
//         if(forward_max < forward[j]){
//           forward_max = forward[j];
//         }
//       }
//     }
//     forward[i] = forward_max+1;
//   }
//   for(int i = n; i>=1; i--){
//     int reverse_max = 0;
//     for(int k=n; k>i; k--){
//       if(numbers[k] < numbers[i]){
//         if(reverse_max < reverse[k]){
//           reverse_max = reverse[k];
//         }
//       }
//     }
//     reverse[i] = reverse_max+1;
//     counts[i] = forward[i] + reverse[i] - 1;
//   }
//   // for(auto p:forward){
//   //   cout << p << " ";
//   // }
//   // cout << '\n';

//   // for(auto p: reverse){
//   //   cout << p << " ";
//   // }
//   // cout << '\n';
//   cout << *max_element(counts.begin(),counts.end()) << '\n';
// }