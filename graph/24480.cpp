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

vector<int> point_sequence;
vector<int> visited;
vector<vector<int>> graph;

int cnt = 1;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.first >= b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

void dfs(vector<int> &visited, vector<vector<int>> &graph, int start)
{

    if (visited[start] == 1)
        return;
    visited[start] = 1;
    point_sequence[start] = cnt;
    cnt++;
    for (auto p : graph[start])
    {
        dfs(visited, graph, p);
    }
}

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    int start;
    cin >> N >> M >> start;
    point_sequence.resize(N + 1);
    visited.resize(N + 1);
    graph.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a;
        int b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 0; i < graph.size(); i++)
    {
        sort(graph[i].begin(), graph[i].end(), greater<int>());
    }

    // for (int i = 1; i < graph.size(); i++)
    // {
    //     cout << i << " ";
    //     for (int j = 0; j < graph[i].size(); j++)
    //     {
    //         cout << graph[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    dfs(visited, graph, start);

    for (int i = 1; i < point_sequence.size(); i++)
    {
        cout << point_sequence[i] << '\n';
    }
}