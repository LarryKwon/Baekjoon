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

// bool is_prime(int m){
//   if(m == 1) return false;
//   for(int i = 2; i<m;i++){
//     if(m%i == 0){
//       return false;
//     }
//   }
//   return true;
// }

// int main(){
//   int n;
//   int m;
//   cin >> m >> n;

//   int count = m;
//   vector<int> numbers;
//   while(m <= count && count <= n){
//     if(is_prime(count)){
//       numbers.push_back(count);
//     }
//     ++count;
//   }
//   // for(int i = 0; i<numbers.size();i++){
//   //   cout << numbers[i] << '\n';
//   // }
//   if(numbers.size() == 0){
//     cout << -1 << '\n';
//     return 0;
//   }
//   int min = *min_element(numbers.begin(),numbers.end());
//   int sum = accumulate(numbers.begin(), numbers.end(),0);

//   cout << sum << '\n' << min << '\n';
// }
