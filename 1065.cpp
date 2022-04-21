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

using namespace std;


// bool hansoo(int n){
//   vector<int> numbers;
//   while(n>0){
//     numbers.push_back(n%10);
//     n = n/10;
//   }
//   if (numbers.size()<=2){
//     return true;
//   }

//   int difference = numbers[0] - numbers[1];
//   for(int i = 0; i<numbers.size()-1;i++){
//     if((numbers[i] - numbers[i+1])!= difference) return false;
//   }
//   return true;
// }

// int main(){
//   int n; 
//   cin >> n;
//   int cnt = 0;
//   for(int i = 0; i<n;i++){
//     if(hansoo(i+1)) cnt+=1;
//   }
//   cout << cnt;

// }