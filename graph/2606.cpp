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

vector<vector<int>> graph;
vector<int> visited;
int cnt = 0;

void dfs(int start)
{
    if (visited[start] == 1)
        return;
    visited[start] = 1;
    cnt++;
    for (auto p : graph[start])
    {
        dfs(p);
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int com_num;
    int line_num;
    cin >> com_num >> line_num;

    graph.resize(com_num + 1);
    visited.resize(com_num + 1);

    for (int i = 0; i < line_num; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);
    cout << cnt - 1 << '\n';
}