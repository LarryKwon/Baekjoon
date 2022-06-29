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

vector<vector<bool>> miro;
vector<vector<int>> graph;
vector<pair<bool, int>> visited_bfs;

void add_relation(int y, int x, vector<vector<bool>> &matrix, vector<vector<int>> &graph)
{
    // left, right, up, down

    int height = matrix.size() - 1;
    int width = matrix[0].size() - 1;

    bool left = true;
    bool right = true;
    bool up = true;
    bool down = true;

    int index = width * (y - 1) + x;
    if (y == 1)
    {
        up = false;
    }
    if (y == height)
    {
        down = false;
    }
    if (x == 1)
    {
        left = false;
    }
    if (x == width)
    {
        right = false;
    }

    if (left && matrix[y][x - 1])
    {
        graph[index].push_back(width * (y - 1) + (x - 1));
    }
    if (right && matrix[y][x + 1])
    {
        graph[index].push_back(width * (y - 1) + (x + 1));
    }
    if (up && matrix[y - 1][x])
    {
        graph[index].push_back(width * (y - 2) + x);
    }
    if (down && matrix[y + 1][x])
    {
        graph[index].push_back(width * y + x);
    }
}

void fill_graph(vector<vector<bool>> &matrix, vector<vector<int>> &graph)
{
    int height = matrix.size() - 1;
    int width = matrix[0].size() - 1;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width; j++)
        {
            if (matrix[i][j] == true)
            {
                add_relation(i, j, matrix, graph);
            }
        }
    }
}

void bfs(int start, int count)
{
    queue<int> queue;
    visited_bfs[start].first = 1;
    visited_bfs[start].second = count;
    queue.push(start);
    while (!queue.empty())
    {
        int current = queue.front();
        if (count - visited_bfs[current].second < 1)
        {
            count++;
        }
        queue.pop();
        for (auto p : graph[current])
        {
            if (visited_bfs[p].first == false)
            {
                visited_bfs[p].first = true;
                visited_bfs[p].second = count;
                queue.push(p);
            }
        }
    }
}

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    miro.resize(N + 1, vector<bool>(M + 1));
    graph.resize(N * M + 1);
    visited_bfs.resize(N * M + 1);
    cin.ignore();
    for (int i = 1; i <= N; i++)
    {
        string line;
        getline(cin, line);
        istringstream iss{line};
        for (int j = 1; j <= M; j++)
        {
            char c;
            iss >> c;
            bool possible = false;
            if (c == '1')
                possible = true;
            miro[i][j] = possible;
        }
    }
    fill_graph(miro, graph);
    // for (int i = 0; i < graph.size(); i++)
    // {
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << "i:" << i << " j:" << j << " " << graph[i][j] << '\n';
    //     }
    // }
    bfs(1, 1);

    cout << visited_bfs[N * M].second << '\n';
}