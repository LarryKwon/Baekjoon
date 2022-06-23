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

void add_relation(int y, int x, vector<vector<int>> &matrix, vector<vector<int>> &graph)
{
    // left, right, up, down

    int height = matrix.size();
    int width = matrix[0].size();

    bool left = true;
    bool right = true;
    bool up = true;
    bool down = true;

    int index = width * y + x;
    graph[index][index] = 1;
    if (y == 0)
    {
        up = false;
    }
    if (y == height - 1)
    {
        down = false;
    }
    if (x == 0)
    {
        left = false;
    }
    if (x == width - 1)
    {
        right = false;
    }

    if (left && matrix[y][x - 1])
    {
        graph[index][width * y + (x - 1)] = 1;
    }
    if (right && matrix[y][x + 1])
    {
        graph[index][width * y + (x + 1)] = 1;
    }
    if (up && matrix[y - 1][x])
    {
        graph[index][width * (y - 1) + x] = 1;
    }
    if (down && matrix[y + 1][x])
    {
        graph[index][width * (y + 1) + x] = 1;
    }
}

void fill_graph(vector<vector<int>> &matrix, vector<vector<int>> &graph)
{
    int height = matrix.size();
    int width = matrix[0].size();
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (matrix[i][j] == 1)
            {
                add_relation(i, j, matrix, graph);
            }
        }
    }
}

void dfs(int start, int &cnt, vector<vector<int>> &graph, vector<int> &visited)
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
            dfs(i, cnt, graph, visited);
        }
    }
}

void solve(vector<vector<int>> &graph, vector<int> &visited, vector<int> &groups)
{
    for (int i = 0; i < graph.size(); i++)
    {
        if (graph[i][i] != 0 && visited[i] == 0)
        {
            int cnt = 0;
            dfs(i, cnt, graph, visited);
            // cout << "i: " << i << " cnt:" << cnt << '\n';
            groups.push_back(cnt);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int test_cnt;
    cin >> test_cnt;

    for (int i = 0; i < test_cnt; i++)
    {
        int N, M, K;
        cin >> M >> N >> K;
        vector<vector<int>> positions(N, vector<int>(M));
        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            positions[y][x] = 1;
        }
        // for (int i = 0; i < N; i++)
        // {
        //     for (int j = 0; j < M; j++)
        //     {
        //         cout << positions[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        vector<vector<int>> graph(N * M, vector<int>(N * M));
        fill_graph(positions, graph);
        // for (int i = 0; i < graph.size(); i++)
        // {
        //     cout << i << ": ";
        //     for (int j = 0; j < graph[i].size(); j++)
        //     {
        //         cout << graph[i][j] << " ";
        //     }
        //     cout << '\n';
        // }
        vector<int> visited(N * M);
        vector<int> groups;
        solve(graph, visited, groups);
        cout << groups.size() << '\n';
    }
}