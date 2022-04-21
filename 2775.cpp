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

// int main(){
//   int count = 0;
//   cin >> count;
//   cin.ignore();
//   while(count>0){
//     int k;
//     int n;
//     cin >> k >> n;
//     vector<int> mans(n);
//     for(int i = 0; i<n; i++){
//       mans[i] = i+1;
//     }

//     for(int i = 1; i<k; i++){
//       auto p = mans.end();
//       --p;
//       for(;p!=mans.begin();--p){
//         auto end = p;
//         ++end;
//         *p = accumulate(mans.begin(),end,0);
//       }
//     }
//     int sum = accumulate(mans.begin(),mans.end(),0);
//     cout << sum << '\n';
//     --count;
//   }
// }