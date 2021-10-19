#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<numeric>

// using namespace std;

// int main(){
//   int x;
//   cin >> x;
//   int n = 1;
//   while(true){
//     if(n*(n-1)/2 < x && x <= n*(n+1)/2){
//       break;
//     }
//     n++;
//   }
//   int sum = n+1;
//   int sun = 0;
//   int parent = 0;
//   if(sum%2 == 1 ){
//     int no = x - (n*(n-1)/2);
//     sun = no;
//     parent = sum - sun;
//   }else{
//     int no = x - (n*(n-1)/2);
//     sun = sum - no;
//     parent = sum - sun; 
//   }

//   cout << sun <<'/'<<parent<<'\n';
// }