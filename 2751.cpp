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

// template<typename iter>
// void bubble_sort(iter first, iter last){
//   auto end = first;
//   ++end;
//   auto p = last;
//   while(p!=end){
//     auto current = first;
//     auto next = first;
//     ++next;
//     for(;next!=p;){
//       typename std::iterator_traits<iter>::value_type key = *current;
//       if(*current > *next){
//         *current = *next;
//         *next = key;
//       }
//       ++current;
//       ++next;
//     }
//     --p;
//   }
// }

// int main(){
//   int n;
//   cin >> n;
//   vector<int> numbers;
//   while(n>0){
//     int number;
//     cin >> number;
//     numbers.push_back(number);
//     --n;
//   }
//   sort(numbers.begin(),numbers.end());
//   for(auto p:numbers){
//     cout << p << '\n';
//   }
// }