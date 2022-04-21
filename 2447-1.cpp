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

// vector<vector<char>> star( vector<vector<char>>& origin, int n){
  
  
//   for(int i = n/3;i<n*2/3;i++){
//     for(int j = n/3;j<n*2/3;j++){
//       origin[i][j] = ' ';
//     }
//   }

//   if(n==3) return origin;
  
//   vector<vector<char>> part(n/3,vector<char>(n/3,'*'));
//   part = star(part,n/3);
  
//   for(int i = 0;i<n;i+= n/3){
//     for(int j = 0; j<n;j+= n/3){
//       for(int x = 0;x<n/3;x++){
//         for(int y = 0;y<n/3;y++){
//           if(n/3<=(i+x)&&(i+x)<n*2/3 && n/3<=(j+y) && (j+y)<n*2/3) continue;
//           origin[i+x][j+y] = part[x][y];
//         }
//       }
//     }
//   }
//   return origin;
// }

// int main(){
//   int n;
//   cin >> n;
//   //pseudo code
//   vector<vector<char>> stars(n,vector<char>(n,'*'));
//   stars = star(stars,n);
//   for(int i = 0;i<n;i++){
//     for(int j = 0; j<n;j++){
//       cout << stars[i][j];
//     }
//     cout << '\n';
//   }
// }