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
//   int m;
//   int n;
//   cin >> m >> n;

//   vector<int> numbers;
//   for(int i = 0; i<=n;i++){
//     numbers.push_back(1);
//   }

//   numbers[0] = 0;
//   numbers[1] = 0;

//   for(int i = 2; i<=n;i++){
//     if(numbers[i]==0) continue;
//     for(int j = 2*i; j<=n; j+=i){
//       if(numbers[j] == 0) continue;
//       else{
//         numbers[j] = 0;
//       }
//     }
//   }

//   for(int i = m; i<=n;i++){
//     if(numbers[i] == 1){
//       cout << i << '\n';
//     }
//   }
// }