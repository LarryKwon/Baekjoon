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

vector<int> point_sequence;
vector<int> visited;
vector<vector<int>> graph;

void bfs(vector<int> &visited, vector<vector<int>> &graph, int start)
{
    int cnt = 1;
    queue<int> queue;
    visited[start] = 1;
    point_sequence[start] = cnt;
    cnt++;
    queue.push(start);
    while (!queue.empty())
    {
        int current = queue.front();
        queue.pop();
        for (auto p : graph[current])
        {
            if (visited[p] == 0)
            {
                visited[p] = 1;
                point_sequence[p] = cnt;
                cnt++;
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

    bfs(visited, graph, start);

    for (int i = 1; i < point_sequence.size(); i++)
    {
        cout << point_sequence[i] << '\n';
    }
}