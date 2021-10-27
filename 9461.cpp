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

// long long counts[101];

// long count(long n){
//   if(counts[n] != 0) return counts[n];
//   else{
//     long long cnt = count(n-1) + count(n-5);
//     counts[n] = cnt;
//     return counts[n];
//   }
// }

// int main(){
//   int cycle;
//   cin >> cycle;
//   counts[1] = 1;
//   counts[2] = 1;
//   counts[3] = 1;
//   counts[4] = 2;
//   counts[5] = 2;

//   while(cycle>0){
//     int n;
//     cin >> n;
//     cout << count(n) << '\n';
//     --cycle;
//   }
// }