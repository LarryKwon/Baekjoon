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
// void insertion_sort(iter first, iter last){
//   auto p = first;
//   ++p;
//   while(p!=last){
//     typename std::iterator_traits<iter>::value_type key = *p;
//     auto prev = p;
//     auto current = p;
//     for(--prev;current!=first;){
//       if(*prev > *current){
//         *current = *prev;
//         *prev = key;
//       }
//       --prev;
//       --current;
//     }
//     ++p;
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
//   insertion_sort(numbers.begin(),numbers.end());
//   for(auto p:numbers){
//     cout << p << '\n';
//   }
// }