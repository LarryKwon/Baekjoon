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

// enum State{
//   start,ready,done
// };

// char bool_to_int(bool n){
//   if(n==true){
//     return 1;
//   }else{return 0;}
// }

// bool is_croatian(string::iterator& p){
//   string::iterator next = p;
//   ++next;
//   switch(*p){
//     case 'c':
//       if(*next == '=' || *next == '-') return true;
//       else return false;
//       break;

//     case 'l':
//       if(*next == 'j') return true;
//       else return false;
//     break;

//     case 'd':
//       if(*next == '-') return true;
//       else return false;
//     break;

//     case 'n':
//       if(*next == 'j') return true;
//       else return false;
//     break;

//     case 's':
//       if(*next == '=') return true;
//       else return false;
//     break;

//     case 'z':
//       if(*next == '=') return true;
//       else return false;
//     break;

//     default:
//       return false;
//     break;
//   }
// }

// bool is_b(string::iterator p){
//   string::iterator next = p;
//   ++next;
//   if(*(p) == 'z' && *(next) == '='){
//     return true;
//   }
//   return false;
// }

// int main(){
//   string line;
//   getline(cin,line);
//   auto p = line.begin();
//   State state = start;
//   string new_line;
//   while(p!=line.end()){
//     switch(state){
//       case start:
//         if(is_croatian(p)){
//           new_line += *p;
//           ++p;
//           ++p;
//         }
//         else{
//           if(*p == 'd'){
//             state = ready;
//             new_line += *p;
//             ++p;
//           }
//           else{
//             new_line += *p;
//             ++p;
//           }
//         }
//       break;

//       case ready:
//         if(is_b(p)){
//           ++p;
//           ++p;
//           state= start;
//         }else{
//           state = start;
//         }
//       break;

//       case done:
//       break;
//     }
//   }

//   cout << new_line.size() << '\n';
  
// }