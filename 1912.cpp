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
//   int n;
//   cin >> n;
//   int cycle = n;
//   vector<int> numbers(n+1);
//   int i = 1;
//   while(cycle>0){
//     int number;
//     cin >> number;
//     numbers[i] = number;
//     ++i;
//     --cycle;
//   }

//   vector<int> maxes(n+1);

//   maxes[1] = numbers[1];
//   int max_i = numbers[1];
//   for(int i=2; i<=n; i++){
//     max_i = max(max_i + numbers[i],numbers[i]);
//     maxes[i] = max(max_i,maxes[i-1]);
//   }

//   cout << maxes[n] << '\n';

// }