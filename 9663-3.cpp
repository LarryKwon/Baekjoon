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

static int num_of_case = 0;

bool check_chess(vector<int> &chess, int pos, int depth)
{
    for (int i = 1; i <= depth - 1; i++)
    {
        if (abs(pos - chess[i]) == abs(depth - i) | pos == chess[i])
        {
            return false;
        }
    }
    return true;
}

void print_chess(vector<int> &chess, int depth)
{
    cout << "current depth: " << depth << "\n";
    for (int i = 1; i < chess.size(); i++)
    {
        cout << chess[i] << " ";
    }
    cout << '\n';
}

void nqueen(int n, int depth, vector<int> &chess)
{

    if (depth == n + 1)
    {
        num_of_case += 1;
        // print_chess(chess, depth);
    }
    else
    {
        vector<bool> possible(n + 1, false);
        for (int i = 1; i <= n; i++)
        {
            //현재 row에 대해서, 놓을 수 있는 말이 있는지 검사
            // check_chess;
            if (check_chess(chess, i, depth))
            {
                chess[depth] = i;
                nqueen(n, depth + 1, chess);
            }
        }

        //그 다음에 가능한 값들을 돌면서, 만약 true라면
        // next depth
        // for (int i = 1; i <= n; i++)
        // {
        //     if (possible[i] == true)
        //     {
        //         chess[depth] = i;
        //         nqueen(n, depth + 1, chess);
        //     }
        // }
    }
}

int main()
{
    int n;
    cin >> n;
    static vector<int> chess(n + 1);
    nqueen(n, 1, chess);
    cout << num_of_case << '\n';
}