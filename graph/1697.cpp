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

vector<vector<int>> graph(100001);
vector<bool> visited(100001);
vector<int> dist(100001);

void add_relation(vector<vector<int>> &graph, int coor)
{
    if (coor < 100000 && coor >= 0)
    {
        graph[coor].push_back(coor + 1);
    }
    if (coor > 0)
    {
        graph[coor].push_back(coor - 1);
    }
    if (coor <= 50000 && coor > 0)
    {
        graph[coor].push_back(2 * coor);
    }
}

void bfs(vector<vector<int>> &graph, int start, int end)
{
    queue<int> queue;
    visited[start] = true;
    int time = 0;
    bool found = false;
    add_relation(graph, start);
    queue.push(start);
    while (!queue.empty() && found == false)
    {
        int current = queue.front();
        if (time - dist[current] < 1)
        {
            time++;
        }
        queue.pop();
        for (auto p : graph[current])
        {
            if (visited[p] == false)
            {
                // cout << "current: " << current << " possible:" << p << '\n';
                visited[p] = true;
                add_relation(graph, p);
                if (dist[p] > time || dist[p] == 0)
                {
                    dist[p] = time;
                }
                if (p == end)
                {
                    found = true;
                    break;
                }
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

    int N, K;
    cin >> N >> K;
    bfs(graph, N, K);
    cout << dist[K] << '\n';
}