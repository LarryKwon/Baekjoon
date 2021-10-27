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

// bool bigger(pair<int,int>a, pair<int,int>b){
//   if(a.first > b.first && a.second > b.second){
//     return true;
//   }
//   return false;
// }

// int main(){
//   int n;
//   cin >> n;
//   vector<pair<int,int>> peoples;
//   while(n>0){
//     int height;
//     int weight;
//     cin >> weight >> height;
//     peoples.push_back(pair<int,int>(weight,height));
//     --n;
//   }
//   // vector<pair<int,int>> sorted_people;
//   // sorted_people = peoples;
//   // sort(sorted_people.begin(),sorted_people.end(),bigger);
//   // cout << '\n';
//   // for(auto p: sorted_people){
//   //   cout << p.first << ' ' << p.second << '\n';
//   // }

//   auto it = peoples.begin();
//   while(it!=peoples.end()){
//     int rank = 1;
//     int cnt = 0;
//     for(auto p = peoples.begin();p!=peoples.end();++p){
//       if(p==it){
//         continue;
//       }
//       if(it->first > p->first && it->second > p->second){
//         continue;
//       }else if(it->first < p->first && it->second < p->second){
//         ++rank;
//         cnt = 0;
//       }else{
//         // cnt ++;
//       }
//     }
//     ++it;
//     cout << rank << '\n';
//   }
// }