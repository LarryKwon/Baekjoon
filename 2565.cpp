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
//   if(a.first < b.first){
//     return true;
//   }
//   return false;
// }

// int main(){
//   int n;
//   cin >> n;
//   int cycle = n;
//   vector<pair<int,int>> line_pairs;
//   line_pairs.push_back(pair<int,int>(0,0));
  
//   while(cycle >0){
//     int a;
//     int b;
//     cin >> a >> b;
//     line_pairs.push_back(pair<int,int>(a,b));
//     --cycle;
//   }


//   vector<int> forward(n+1);
//   vector<int> reverse(n+1);

//   forward[0] = 0;
//   reverse[0] = 0;

//   forward[1] = 0;
//   reverse[n] = 0;

//   sort(++line_pairs.begin(),line_pairs.end(),compare);

//   // for(auto p:line_pairs){
//   //   cout << "a: " << p.first << " b: " << p.second << '\n';
//   // }

//   for(int i=1; i<=n; i++){
//     int forward_max = 0;
//     for(int j=1; j<i;j++){
//       if(line_pairs[j].second <= line_pairs[i].second){
//         if(forward_max < forward[j]){
//           forward_max = forward[j];
//         }
//       }
//     }
//     forward[i] = forward_max+1;
//   }
  
//   int forward_max = *max_element(forward.begin(),forward.end());

//   cout << n - forward_max << '\n';
// }