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

// bool check_numb(string number){
//   int cnt = 0;
//   for(auto p:number){
//     if(p == '6'){
//       cnt +=1;
//     }else{
//       cnt = 0;
//     }
//     if(cnt >=3) return true;
//   }
//   return false;
// }

// int main(){
//   int number = 666;
//   int n;
//   cin >> n;
//   int cnt = 0;
//   while(true){
//     string number_str = to_string(number);
//     if(check_numb(number_str)){
//       cnt += 1;      
//     }
//     if(cnt == n) break;
//     ++number;
//   }
//   cout << number << '\n';
 
// }