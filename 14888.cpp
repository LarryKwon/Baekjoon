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

// static vector<int> numbers;
// static vector<pair<int,bool>> operators;
// static set<int> results;

// static int n;
// static int num_size;


// //pseudo code
// /*
// 연산이 저장되어있는 어떤 배열을 돌면서
// bool operators[] -> 연산이 전체 저장되있다.

// 어떤 타입인지에 따라 구별해야하니까
// operators -> vector<pair<int,bool>> 이여야하고
// pair.first -> 0,1,2,3 => +,-,*,/
// switch(pair.first){
//   case 0:
//     result += number;
//   case 1:
//   case 2:
//   case 3:
// }
// operators[i].second = true;
// calculate(numbers,operators,nth+1);
// */

// void calculate(vector<int>& numbers, vector<pair<int,bool>>&operators,int nth,int result){
//   if(nth == num_size){
//     results.insert(result);
//     // cout <<"nth = numsize, result: " << result << '\n';
//     return ;
//   }else{
//     int number = numbers[nth];
//     int prev_result = result;
//     // cout <<"number: " << number << '\n';
//     for(int i=0; i<(num_size-1);i++){
//       if(operators[i].second == false){
//         operators[i].second = true;
//         switch(operators[i].first){
//           case 0:
//             result += number;
//           break;
          
//           case 1:
//             result -= number;
//           break;

//           case 2:
//             result *= number;
//           break;
          
//           case 3:
//             result /= number;
//           break;
//         }
//         // cout <<"result: " << result << '\n';
//         calculate(numbers,operators,nth+1,result);
//         operators[i].second = false;
//         result = prev_result;
//       }
//     }
//   }
// }

// int main(){
//   cin >> n;
//   num_size = n;
//   while(n>0){
//     int number;
//     cin >> number;
//     numbers.push_back(number);
//     --n;
//   }
//   for(int i=0; i<4; i++){
//     int cnt;
//     cin >> cnt;
//     while(cnt>0){
//       operators.push_back(pair<int,bool>(i,false));
//       --cnt;
//     }
//   }
//   // for(auto p: numbers){
//   //   cout << p << " ";
//   // }

//   // for(auto p: operators){
//   //   cout << "operation: " << p.first << "bool: " << p.second << '\n';
//   // }
  
//   int nth = 1;
//   int result = numbers[0];
//   calculate(numbers,operators,nth,result);
//   auto min = results.begin();
//   auto max = min;
//   while(true){
//     auto max_next = max;
//     ++max_next;
//     if(max_next == results.end()) break;
//     max = max_next;
//   }
//   cout << *max << '\n' << *min << '\n';
// }