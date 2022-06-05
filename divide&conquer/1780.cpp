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

#define black 1
#define white 0
#define blue -1

using namespace std;

int total_num_of_blue = 0;
int total_num_of_black = 0;
int total_num_of_white = 0;

void sameColor(vector<vector<int>> &colors, int size, int pos_y, int pos_x)
{
    if (size == 1)
    {
        switch (colors[pos_y][pos_x])
        {
        case black:
            total_num_of_black += 1;
            break;

        case white:
            total_num_of_white += 1;
            break;

        case blue:
            total_num_of_blue += 1;
            break;
        }
    }
    else
    {
        bool isWhite = true;
        bool isBlack = true;
        bool isBlue = true;

        for (int i = pos_y; i < size + pos_y; i++)
        {
            for (int j = pos_x; j < size + pos_x; j++)
            {
                if (colors[i][j] == black)
                {
                    isWhite = false;
                    isBlue = false;
                }
                else if (colors[i][j] == white)
                {
                    isBlack = false;
                    isBlue = false;
                }
                else if (colors[i][j] == blue)
                {
                    isBlack = false;
                    isWhite = false;
                }

                if (isWhite == false && isBlack == false && isBlue == false)
                {
                    break;
                }
            }
        }

        if (isWhite == false && isBlack == false && isBlue == false)
        {
            vector<int> partial(9);
            sameColor(colors, size / 3, pos_y, pos_x);
            sameColor(colors, size / 3, pos_y, size / 3 + pos_x);
            sameColor(colors, size / 3, pos_y, size * 2 / 3 + pos_x);

            sameColor(colors, size / 3, size / 3 + pos_y, pos_x);
            sameColor(colors, size / 3, size / 3 + pos_y, size / 3 + pos_x);
            sameColor(colors, size / 3, size / 3 + pos_y, size * 2 / 3 + pos_x);

            sameColor(colors, size / 3, size * 2 / 3 + pos_y, pos_x);
            sameColor(colors, size / 3, size * 2 / 3 + pos_y, size / 3 + pos_x);
            sameColor(colors, size / 3, size * 2 / 3 + pos_y, size * 2 / 3 + pos_x);
        }
        else
        {
            if (isWhite)
            {
                total_num_of_white += 1;
            }
            else if (isBlack)
            {
                total_num_of_black += 1;
            }
            else if (isBlue)
            {
                total_num_of_blue += 1;
            }
        }
        // cout << "size:" << size << " pos_x:" << pos_x << " pos_y" << pos_y << " " << isBlack << isWhite << isBlue << '\n';
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
        int color;
        int j = 0;
        while (iss >> color)
        {
            colors[i][j] = color;
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
    sameColor(colors, n, 0, 0);

    cout << total_num_of_blue << '\n'
         << total_num_of_white << '\n'
         << total_num_of_black << '\n';

    return 0;
}