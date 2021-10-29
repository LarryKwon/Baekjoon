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
//   vector<int> counts(n+1);
//   counts[0] = 0;
//   counts[1] = 1;
//   for(int i=2; i<=n; i++){
//     int max = 0;
//     for(int j=1; j<i;j++){
//       if(numbers[j] < numbers[i]){
//         if(max < counts[j]){
//           max = counts[j];
//         }
//       }
//     }
//     counts[i] = max+1;
//   }
//   cout << *max_element(counts.begin(),counts.end()) << '\n';
// }