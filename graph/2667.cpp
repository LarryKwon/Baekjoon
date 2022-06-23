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
#include <queue>

using namespace std;

vector<vector<int>> matrix;
vector<vector<int>> graph;
vector<int> towns;
vector<bool> visited;

void add_relation(int y, int x)
{
    // left, right, up, down
    bool left = true;
    bool right = true;
    bool up = true;
    bool down = true;

    int index = matrix.size() * y + x;
    graph[index][index] = 1;
    if (y == 0)
    {
        up = false;
    }
    if (y == matrix.size() - 1)
    {
        down = false;
    }
    if (x == 0)
    {
        left = false;
    }
    if (x == matrix.size() - 1)
    {
        right = false;
    }

    if (left && matrix[y][x - 1])
    {
        graph[index][matrix.size() * y + (x - 1)] = 1;
    }
    if (right && matrix[y][x + 1])
    {
        graph[index][matrix.size() * y + (x + 1)] = 1;
    }
    if (up && matrix[y - 1][x])
    {
        graph[index][matrix.size() * (y - 1) + x] = 1;
    }
    if (down && matrix[y + 1][x])
    {
        graph[index][matrix.size() * (y + 1) + x] = 1;
    }
}

void fill_graph(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            if (matrix[i][j] == 1)
            {
                add_relation(i, j);
            }
        }
    }
}

void dfs(int start, int &cnt)
{
    // cout << "start: " << start << " cnt:" << cnt << '\n';
    if (visited[start] == 1)
    {
        return;
    }
    visited[start] = 1;
    cnt++;
    for (int i = 0; i < graph[start].size(); i++)
    {
        if (graph[start][i] == 1)
        {
            dfs(i, cnt);
        }
    }
}

void solve()
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i][i] != 0 && visited[i] == 0)
        {
            int cnt = 0;
            dfs(i, cnt);
            // cout << "i: " << i << " cnt:" << cnt << '\n';
            towns.push_back(cnt);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    matrix.resize(N, vector<int>(N));
    graph.resize(N * N, vector<int>(N * N));
    visited.resize(N * N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char isHouse;
            cin >> isHouse;
            matrix[i][j] = isHouse - '0';
        }
    }

    fill_graph(matrix);

    // for (int i = 0; i < graph.size(); i++)
    // {
    //     cout << i << ": ";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << '\n';
    // }
    solve();
    cout << towns.size() << '\n';
    sort(towns.begin(), towns.end());
    for (auto p : towns)
    {
        cout << p << '\n';
    }
}