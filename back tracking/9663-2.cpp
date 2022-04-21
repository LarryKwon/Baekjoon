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


// static int cnt = 0;

// void print_chess(vector<vector<int>>& chess){
//   for(int i=0; i<chess.size(); i++){
//     for(int j=0; j<chess.size(); j++){
//       cout << chess[i][j];
//     }
//     cout << '\n';
//   }
// }

// bool check_chess(vector<int>& rows,int nth){
//   for(int i=0; i<nth; i++){
//     if(rows[i]==rows[nth]) return false;
//     if(abs(rows[i]-rows[nth])==nth-i) return false;
//   }
//   return true;
// }

// void queen(vector<int>& rows,int nth, int n){
//   if(nth==n){
//     cnt += 1;
//   }else{
//     for(int i=0; i<n; i++){
//       rows[nth] = i;
//       if(check_chess(rows,nth)){
//         queen(rows,nth+1,n);
//       }
//     }
//   }
//   return ;
// }

// int main(){
//   int n;
//   cin >> n;
//   static vector<int> rows(n);
//   queen(rows,0,n);
//   cout << cnt << '\n';
// }