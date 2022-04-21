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

// int char_to_int(char c){
//   switch(c){
//     case 'A': 
//     case 'B':
//     case 'C':
//       return 2;
//     case 'D':
//     case 'E':
//     case 'F':
//       return 3;
//     case 'G':
//     case 'H':
//     case 'I':
//       return 4;
//     case 'J':
//     case 'K':
//     case 'L':
//       return 5;
//     case 'M':
//     case 'N':
//     case 'O':
//       return 6;
//     case 'P':
//     case 'Q':
//     case 'R':
//     case 'S':
//       return 7;
//     case 'T':
//     case 'U':
//     case 'V':
//       return 8;
//     case 'W':
//     case 'X':
//     case 'Y':
//     case 'Z':
//       return 9;
//     default:
//       return 1;
//   }
// }

// int int_to_time(int i){
//   return i+1;
// }

// int main(){
//   string line;
//   getline(cin,line);
//   int time = 0;
//   for(char c:line){
//     time += int_to_time(char_to_int(c));
//   }

//   cout << time << '\n';
// }