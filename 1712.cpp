#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<numeric>

// using namespace std;

// int main(){
//   long double fixed;
//   long double variable;
//   long double price;
//   cin >> fixed >> variable >> price;

//   long double count = 0;
//   if((price - variable)<=0){
//     count = -1;
//     cout << static_cast<int>(count) << '\n';
//     return 0;
//   }
  
//   count = static_cast<int>(fixed/(price-variable)) + 1;

//   // while(true){

//   //   if(count > fixed/(price - variable)) break;
//   //   ++count;
//   // }
//   cout << static_cast<int>(count) << '\n';
// }