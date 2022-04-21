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

// static vector<pair<int,int>> counts(41);


// pair<int,int> fibonacci_count(int number){
//   if(number == 0){
//     return counts[0];
//   }else if(number == 1){
//     return counts[1];
//   }else if(!(counts[number].first == 0 && counts[number].second == 0)){
//     return counts[number];
//   }else{
//     pair<int,int> count_1 = fibonacci_count(number-1);
//     pair<int,int> count_2 = fibonacci_count(number-2);
//     counts[number].first = count_1.first + count_2.first;
//     counts[number].second = count_1.second + count_2.second;
//     return counts[number];
//   }
// }

// int main(){

//   int n;
//   cin >> n;
//   counts[0] = pair<int,int>(1,0);
//   counts[1] = pair<int,int>(0,1);

//   while(n>0){
//     int number;
//     cin >> number;
//     pair<int,int> count = fibonacci_count(number);
//     cout << count.first << " " << count.second << '\n';
//     --n;
//   }
// }