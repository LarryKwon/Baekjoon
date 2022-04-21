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

// void calculate(vector<long long>& counts, int number,int nth){
//   if(nth == number){
//     return;
//   }else{
//     vector<long long> prev = counts;
//     counts[0] = prev[1]%1000000000;
//     for(int i=1; i<9;i++){
//       counts[i] = (prev[i-1] + prev[i+1])% 1000000000;
//     }
//     counts[9] = prev[8]%1000000000;
//     calculate(counts,number,nth+1);
//   }
// }

// int main(){
//   vector<long long> counts = {0,1,1,1,1,1,1,1,1,1};
//   int n;
//   cin >> n;
//   calculate(counts,n,1);
//   long long result = 0;
//   for(auto p: counts){
//     result = (result+p)%1000000000;
//   }
//   // long long result = (accumulate(counts.begin(), counts.end(),0))%1000000000;
//   cout << result << '\n';
// }