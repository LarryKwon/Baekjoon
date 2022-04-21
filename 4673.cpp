// #include<iostream>
// #include<sstream>
// #include<fstream>
// #include<string>
// #include<algorithm>
// #include<stdexcept>
// #include<memory>
// #include<vector>
// #include<list>
// #include<map>
// #include<set>
// #include<numeric>

// using namespace std;

// int generated_numbers(int n){
//   int dividend = 10;
//   int generated_number = n;
//   while(n > 0){
//     int remainder = n % 10;
//     n = n / 10;
//     generated_number += remainder;
//   }
//   return generated_number;
// }

// void self_numbers(map<int,int>& numbers){
//   for(auto p: numbers){
//     int n = p.first;
//     int generated_number = generated_numbers(n);
//     if(numbers.find(generated_number)!= numbers.end()){
//       numbers[generated_number] += 1;
//     }
//   }
// }

// int main(){

//   int n = 10000;
//   map<int,int> numbers;
//   for(int i = 0; i<n;i++){
//     numbers.insert(pair<int,int>(i+1,0));
//   }

//   self_numbers(numbers);
//   for(auto p: numbers){
//     if(p.second == 0){
//       cout << p.first << '\n';
//     }
//   }

// }