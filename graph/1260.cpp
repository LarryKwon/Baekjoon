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

vector<int> visited_dfs;
vector<int> visited_bfs;
vector<int> sequence_dfs;
vector<int> sequence_bfs;

vector<vector<int>> graph;

void dfs(int start)
{
    if (visited_dfs[start] == 1)
        return;
    visited_dfs[start] = 1;
    sequence_dfs.push_back(start);
    for (auto p : graph[start])
    {
        dfs(p);
    }
}

void bfs(int start)
{
    queue<int> queue;
    visited_bfs[start] = 1;
    sequence_bfs.push_back(start);
    queue.push(start);
    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();
        for (auto p : graph[current])
        {
            if (visited_bfs[p] == 0)
            {
                visited_bfs[p] = 1;
                sequence_bfs.push_back(p);
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
    int N, M, start;
    cin >> N >> M >> start;

    visited_dfs.resize(N + 1);
    visited_bfs.resize(N + 1);
    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < graph.size(); i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(start);
    bfs(start);

    for (int i = 0; i < sequence_dfs.size(); i++)
    {
        cout << sequence_dfs[i] << " ";
    }
    cout << '\n';
    for (int i = 0; i < sequence_bfs.size(); i++)
    {
        cout << sequence_bfs[i] << " ";
    }
    cout << '\n';
}