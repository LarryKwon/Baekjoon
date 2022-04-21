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

// long long counts[1000001];

// long long count(long long n){
//   if(counts[n] != 0) return counts[n];
//   else{
//     int cnt = count(n-1) + count(n-2);
//     counts[n] = cnt%15746;
//     return counts[n];
//   }
// }

// int main(){
//   int n;
//   cin >> n;
//   counts[1] = 1;
//   counts[2] = 2;
//   long long result = count(n);
//   cout << result << '\n';
// }