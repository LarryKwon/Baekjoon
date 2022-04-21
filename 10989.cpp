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
//   ios::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);
//   int n;
//   cin >> n;
//   int counted_numbers[10001] = {0,};
//   cin.ignore();
//   while(n>0){
//     int number;
//     cin >> number;
//     counted_numbers[number] += 1;
//     --n;
//   }
//   for(int i=0;i<10001;i++){
//     for(int j=0; j<counted_numbers[i]; j++){
//       cout << i << '\n';
//     }
//   }
// }