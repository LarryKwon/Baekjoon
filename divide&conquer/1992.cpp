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
#include <deque>
#include <numeric>

using namespace std;

int total_num_of_blue = 0;
int total_num_of_white = 0;

void print_partial(vector<vector<int>> &colors, int size, int pos_y, int pos_x)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << colors[pos_y + i][pos_x + j];
        }
    }
}

void quadTree(vector<vector<int>> &colors, int size, int pos_y, int pos_x)
{

    if (size == 1)
    {
        cout << colors[pos_y][pos_x];
    }
    else
    {
        bool isWhite, isBlack;
        isWhite = true;
        isBlack = true;
        for (int i = pos_y; i < size + pos_y; i++)
        {
            for (int j = pos_x; j < size + pos_x; j++)
            {
                if (colors[i][j] == 0)
                    isBlack = false;
                if (colors[i][j] == 1)
                    isWhite = false;
            }
        }
        if (isWhite)
        {
            cout << 0;
            return;
        }
        if (isBlack)
        {
            cout << 1;
            return;
        }
        cout << "(";
        quadTree(colors, size / 2, pos_y, pos_x);
        quadTree(colors, size / 2, pos_y, size / 2 + pos_x);
        quadTree(colors, size / 2, size / 2 + pos_y, pos_x);
        quadTree(colors, size / 2, size / 2 + pos_y, size / 2 + pos_x);
        cout << ")";
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> colors(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss{line};
        char color;
        int j = 0;
        while (iss >> color)
        {
            if (color == '1')
                colors[i][j] = 1;
            if (color == '0')
                colors[i][j] = 0;
            j++;
        }
        cin.clear(ios_base::goodbit);
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << colors[i][j];
    //     }
    //     cout << '\n';
    // }

    quadTree(colors, n, 0, 0);

    return 0;
}