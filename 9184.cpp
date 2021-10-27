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

// int results[21][21][21] = {0,};

// int w(int a, int b, int c){
//   if (a <= 0 || b <= 0 || c <= 0){
//     return 1;
//   }
//   else if (a > 20 || b > 20 || c > 20){
//     return w(20,20,20);
//   }
//   else if (a < b && b < c){
//     int first,second,third;

//     if(results[a][b][c-1]!= 0){
//       first = results[a][b][c-1];
//     }else{
//       first = w(a,b,c-1);
//       results[a][b][c-1] = first;
//     }

//     if(results[a][b-1][c-1]!=0){
//       second = results[a][b-1][c-1];
//     }else{
//       second = w(a,b-1,c-1);
//       results[a][b-1][c-1] = second;
//     }

//     if(results[a][b-1][c]!=0){
//       third = results[a][b-1][c];
//     }else{
//       third = w(a,b-1,c);
//       results[a][b-1][c] = third;
//     }

//     return first + second - third;
//   } 
//   else{
//     int first;
//     int second;
//     int third;
//     int fourth;

//     if(results[a-1][b][c]!= 0){
//       first = results[a-1][b][c];
//     }else{
//       first = w(a-1,b,c);
//       results[a-1][b][c] = first;
//     }

//     if(results[a-1][b-1][c]!=0){
//       second = results[a-1][b-1][c];
//     }else{
//       second = w(a-1,b-1,c);
//       results[a-1][b-1][c] = second;
//     }

//     if(results[a-1][b][c-1]!=0){
//       third = results[a-1][b][c-1];
//     }else{
//       third = w(a-1,b,c-1);
//       results[a-1][b][c-1] = third;
//     }

//     if(results[a-1][b-1][c-1]!=0){
//       fourth = results[a-1][b-1][c-1];
//     }else{
//       fourth = w(a-1,b-1,c-1);
//       results[a-1][b-1][c-1] = fourth;
//     }


//     return first + second + third - fourth;
//   }
// }

// int main(){
//   int a,b,c;
//   for(int i=0;i<21;i++){
//     for(int j=0; j<21;j++){
//       results[0][i][j] = 1;
//       results[i][0][j] = 1;
//       results[i][j][0] = 1;
//     }
//   }
//   while(true){
//     cin >> a >> b >> c;
//         if(a==-1 && b== -1 && c== -1) break;
//     int result = w(a,b,c);
//     cout << "w("<<a <<", " << b <<", " << c <<") = " << result << '\n'; 


//   }
//   return 0;
// }