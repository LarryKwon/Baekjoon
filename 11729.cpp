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

// int cnt_hanoi(int n){
//   if(n==1) return 1;
//   else{
//     return 2*cnt_hanoi(n-1) + 1;
//   }
// }

// void hanoi(int n, int start, int end){
//   if(n==1){
//     cout << start << ' ' << end << '\n';
//     return ;
//   }
//   hanoi(n-1,start,6-start-end);
//   cout << start << ' ' << end << '\n';
//   hanoi(n-1,6-start-end,end);
// }

// int main(){
//   int n;
//   cin >> n;
//   int cnt = 0;
//   cnt = cnt_hanoi(n);
//   cout << cnt << '\n';
//   hanoi(n,1,3);
// }