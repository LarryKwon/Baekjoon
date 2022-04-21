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

// int calculate(vector<int>& counts, int number){
//   if(number == 1){
//     return counts[1];
//   }else if(number == 2){
//     return counts[2];
//   }
  
//   int remainder_2 = number%2;
//   int remainder_3 = number%3;
//   int result = 0;

//   int result_2;
//   int result_3;

//   if(counts[number/3]!=0){
//     result_3 = counts[number/3];
//   }else{
//     result_3 = calculate(counts,number/3);
//   }

//   if(counts[number/2]!=0){
//     result_2 = counts[number/2];
//   }else{
//     result_2 = calculate(counts,number/2);
//   }

//   if(remainder_2 == 0){
//     //(0,0)
//     if(remainder_3 == 0){
//       result = min(1 + result_3,1+result_2);
//       counts[number] = result;
//     }
//     //(0,1)
//     else if(remainder_3 == 1){
//       result = min(result_2+1, result_3+2);
//       counts[number] = result;
//     }
//     //(0,2)
//     else{
//       result = min(result_2+1, result_3+3);
//       counts[number] = result;      
//     }
//   }else{
//     //(1,0)
//     if(remainder_3 == 0){
//       result = min(1+result_3,2+result_2);
//       counts[number] = result;      
//     }
//     //(1,1)
//     else if(remainder_3 == 1){
//       result = min(2+result_3, 2+result_2);
//       counts[number] = result;       
//     }
//     //(1,2)
//     else{
//       result = min(result_2+2, result_3+3);
//       counts[number] = result;            
//     }
//   }
//   // cout << "number: " << number << " result: " << result << '\n';
//   return result;
// }

// int main(){
//   vector<int> counts(1000001);
//   counts[1] = 0;
//   counts[2] = 1;
//   counts[3] = 1;
//   counts[4] = 2;
//   counts[5] = 3;
//   int number;
//   cin >> number;

//   int result = calculate(counts,number);
//   cout << result << '\n';
// }