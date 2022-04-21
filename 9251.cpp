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
//   string first;
//   string second;
//   cin >> first;
//   cin >> second;

//   first = '0' + first;
//   second = '0' + second;

//   int len_1 = first.size();
//   int len_2 = second.size();

//   vector<vector<int>> table(len_2,vector<int>(len_1));
//   for(int i=1; i<len_2;i++){
//     for(int j=1; j<len_1; j++){
//       if(second[i]==first[j]){
//         table[i][j] = table[i-1][j-1] + 1;
//       }
//       else{
//         table[i][j] = max(table[i-1][j],table[i][j-1]);
//       }
//     }
//   }

//   int max = 0;
//   for(auto p:table){
//     int line_max = *max_element(p.begin(),p.end());
//     if(max < line_max) max = line_max; 
//   }

//   cout << max << '\n';

// }