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

int sameColor(vector<vector<int>> &colors, int size, int pos_x, int pos_y)
{
    if (size == 1)
    {
        return colors[pos_x][pos_y];
    }
    else
    {
        vector<int> partial(4);
        for (int i = 0; i < 4; i++)
        {
            if (i == 0)
            {
                partial[0] = sameColor(colors, size / 2, pos_x, pos_y);
            }
            else if (i == 1)
            {
                partial[1] = sameColor(colors, size / 2, size / 2 + pos_x, pos_y);
            }
            else if (i == 2)
            {

                partial[2] = sameColor(colors, size / 2, pos_x, size / 2 + pos_y);
            }
            else
            {
                partial[3] = sameColor(colors, size / 2, size / 2 + pos_x, size / 2 + pos_y);
            }
        }
        int num_of_blue = 0;
        int num_of_white = 0;
        int num_of_mix = 0;
        for (auto p : partial)
        {
            if (p == 1)
            {
                num_of_blue += 1;
            }
            else if (p == 0)
            {
                num_of_white += 1;
            }
            else
            {
                num_of_mix += 1;
            }
        }
        // cout << "n: " << size << " white: " << num_of_white << " blue: " << num_of_blue << " mix: " << num_of_mix << '\n';
        if (num_of_mix)
        {
            total_num_of_white += num_of_white;
            total_num_of_blue += num_of_blue;
            return -1;
        }
        else
        {
            if (num_of_blue == 0 || num_of_white == 0)
            {
                if (num_of_white == 0)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                total_num_of_white += num_of_white;
                total_num_of_blue += num_of_blue;
                return -1;
            }
        }
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << colors[i][j];
        }
        cout << '\n';
    }
    int color = sameColor(colors, n, 0, 0);
    if (color == 1)
    {
        cout << 0 << '\n'
             << 1 << '\n';
    }
    else if (color == 0)
    {
        cout << 1 << '\n'
             << 0 << '\n';
    }
    else
    {
        cout << total_num_of_white << '\n'
             << total_num_of_blue << '\n';
    }

    return 0;
}