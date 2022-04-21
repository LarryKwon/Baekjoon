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
// static bool col[9][10] = {0,};
// static bool row[9][10] = {0,}; 
// static bool square[9][10] = {0,};

// void print_sudoku(const vector<vector<int>>& sudoku){
//   for(int i=0; i<9; i++){
//     for(int j=0; j<9; j++){
//       cout << sudoku[i][j]<<' ';
//     }
//     cout << '\n';
//   }
// }

// int change_xy_to_square(int x, int y){
//   int x_group = x/3;
//   int y_group = y/3;
//   return y_group*3 + x_group;
// }

// void fill_sudoku(vector<vector<int>>& sudoku,int nth){
//   if(nth == 81){
//     print_sudoku(sudoku);
//     exit(0);
//     return ;
//   }else{
//     int y = nth/9;
//     int x = nth%9;
//     if(sudoku[y][x]){
//       fill_sudoku(sudoku,nth+1);
//     }else{
//       for(int i=1; i<=9; i++){
//         if((!col[x][i])&&(!row[y][i])&&(!square[change_xy_to_square(x,y)][i])){
//           int square_index = change_xy_to_square(x,y);
//           sudoku[y][x] = i;
//           col[x][i] = true;
//           row[y][i] = true;
//           square[square_index][i] = true;
//           fill_sudoku(sudoku,nth+1);
//           sudoku[y][x] = 0;
//           col[x][i] = false;
//           row[y][i] = false;
//           square[square_index][i] = false;
//         }
//       }
//     }
//   }
// }

// int main(){
//   vector<vector<int>> sudoku(9);

//   for(int i=0; i<9; i++){
//     string line;
//     getline(cin,line);
//     istringstream iss{line};
//     int n;
//     int j=0;
//     while(iss>>n){
//       sudoku[i].push_back(n);
//       col[j][n] = true;
//       row[i][n] = true;
//       int square_index = change_xy_to_square(j,i);
//       square[square_index][n] = true;
//       ++j;
//     }
//   }

//   int nth = 0;
//   fill_sudoku(sudoku,nth);
// }