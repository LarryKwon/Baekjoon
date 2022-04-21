#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <numeric>

using namespace std;

static vector<vector<bool> > col(9, vector<bool>(10));
static vector<vector<bool> > row(9, vector<bool>(10));
static vector<vector<bool> > square(9, vector<bool>(10));

int change_xy_to_square_index(int x, int y)
{
    int x_index = x / 3;
    int y_index = y / 3;

    return y_index * 3 + x_index;
}

void print_sudoku(vector<vector<int> >& sudoku)
{
    // cout << '\n';
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j] << " ";
        }
        cout << '\n';
    }
}

void fill_sudoku(vector<vector<int> >& sudoku, int nth)
{
    if (nth == 81)
    {
        print_sudoku(sudoku);
        exit(0);
        return;
    }
    else
    {
        // index가 올 때, x,y로 바꾼 다음에
        // 각 자리마다 하나씩 가능한 수를 체크한다.
        int y = nth / 9;
        int x = nth % 9;
        if(sudoku[y][x]!=0){
            fill_sudoku(sudoku, nth + 1);
        }else{
            // cout << sudoku[y][x] << '\n';
            // 각 x, y 값에 sudoku가 채워져있지 않으면
            int square_index = change_xy_to_square_index(x,y);
            // x 값에 해당하는 row[x]에 false인 것들 대상으로 확인하기
            // y 값에 해당하는 col[y]에 false인 것들 대상으로 확인하기
            // x,y를 이용해서 square_index인 곳에가서 false인 걸 대상으로 확인하기
            for(int i=1; i<=9; i++){
                if (col[x][i] == false && row[y][i] == false && square[square_index][i] == false){
                    col[x][i] = true;
                    row[y][i] = true;
                    square[square_index][i] = true;
                    // cout << nth << ' ' << sudoku[x][y] << ' ' << i <<'\n';
                    sudoku[y][x] = i;
                    fill_sudoku(sudoku,nth+1);
                    //원상 복구
                    sudoku[y][x] = 0;
                    col[x][i] = false;
                    row[y][i] = false;
                    square[square_index][i] = false;
                }
            }
        }
        //print_sudoku(sudoku);
    }
}

int main()
{
    vector<vector<int> > sudoku(9);

    for (int i = 0; i < 9; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss(line);
        int n;
        int j = 0;
        while (iss >> n)
        {
            sudoku[i].push_back(n);
            col[j][n] = true;
            row[i][n] = true;
            int square_index = change_xy_to_square_index(j, i);
            square[square_index][n] = true;
            j++;
        }
    }

    // print_sudoku(sudoku);

    int nth = 0;
    fill_sudoku(sudoku, nth);
}