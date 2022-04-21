// #include<iostream>
// #include<sstream>
// #include<fstream>
// #include<string>
// #include<algorithm>
// #include<stdexcept>
// #include<memory>
// #include<vector>
// #include<cmath>
// #include<list>
// #include<map>
// #include<set>
// #include<numeric>

// using namespace std;


// int main(){

//   int n;
//   cin >> n;
//   int num = 0;
//   int cnt = 0;
//   while(n>0){
//     cin >> num;
//     if(num == 1){
//       --n;
//       continue;
//     }
//     int i;
//     for(i=2; i<num; i++){
//       if(num % i == 0) {
//         break;
//       }
//     }
//     if(i!= (num)){
//       --n;
//       continue;
//     }
//     ++cnt;
//     --n;
//   }
//   cout << cnt << '\n';
// }