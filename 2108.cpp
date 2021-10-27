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

// bool compare(const pair<int,int>& a, const pair<int,int>& b){
//   if(a.first > b.first) return true;
//   else if(a.first == b.first){
//     if(a.second < b.second) return true;
//     return false;
//   }
//   return false;
// }

// int main(){
//   int n;
//   cin >> n;
//   int size = n;
//   vector<int> numbers;
//   while(n>0){
//     int number;
//     cin >> number;
//     numbers.push_back(number);
//     --n;
//   }
//   int sum = accumulate(numbers.begin(),numbers.end(),0);
//   int avg = round((static_cast<double>(sum) / (static_cast<double>(size))));

//   sort(numbers.begin(),numbers.end());
//   int mid = numbers[numbers.size()/2];
//   int range = numbers[numbers.size()-1] - numbers[0];

//   vector<pair<int,int>> counted_numbers;

//   int cnt = 0;
//   for(int i=0; i<numbers.size();i++){
//     cnt += 1;
//     if(numbers[i]!=numbers[i+1]){
//       counted_numbers.push_back(pair<int,int>(cnt,numbers[i]));
//       cnt = 0;
//     }
//     // if(i == numbers.size()-1){
//     //   counted_numbers.push_back(pair<int,int>(cnt,numbers[i]));
//     // }
//   }

//   sort(counted_numbers.begin(),counted_numbers.end(),compare);
//   // for(auto p: counted_numbers){
//   //   cout << "counts: " << p.first << " number: " << p.second << '\n';
//   // }
//   cout << avg << '\n';
//   cout << mid << '\n'; 
//   if(counted_numbers[0].first==counted_numbers[1].first){
//     cout << counted_numbers[1].second << '\n';
//   }else{
//     cout << counted_numbers[0].second << '\n';
//   }
//   cout << range << '\n';

// }