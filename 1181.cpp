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

// struct compare{
//   bool operator()(string a, string b) const{
//     if(a.size() < b.size()) return true;
//     else if(a.size() == b.size()){
//       if(a < b) return true;
//       return false;
//     }else{
//       return false;
//     }
//   }
// };

// int main(){
//   int n;
//   set<string,compare> lines;
//   cin >> n;
//   cin.ignore();
//   while(n>0){
//     string line;
//     getline(cin,line);
//     lines.insert(line);
//     --n;
//   }

//   // sort(lines.begin(),lines.end());

//   for(auto p: lines){
//     cout << p << '\n';
//   }
// }