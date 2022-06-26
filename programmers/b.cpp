#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

void dfs(map<string, string> &graph, map<string, int> &money, string start, int income)
{
    if (income == 0)
        return;
    auto row = graph.find(start);
    if (row == graph.end())
        return;

    int dividend = income * 0.1;
    int own = income - dividend;

    money[start] += own;
    if ((*row).second == "-")
    {
        money["center"] += dividend;
    }
    if (dividend != 0)
    {
        dfs(graph, money, (*row).second, dividend);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount)
{
    map<string, string> graph;
    map<string, int> money;
    map<string, bool> visited;
    visited.insert(pair<string, bool>("center", false));
    money.insert(pair<string, int>("center", 0));

    for (int i = 0; i < enroll.size(); i++)
    {
        money.insert(pair<string, int>(enroll[i], 0));
        graph.insert(pair<string, string>(enroll[i], referral[i]));
    }

    for (int i = 0; i < seller.size(); i++)
    {
        dfs(graph, money, seller[i], amount[i]);
        for (auto p : money)
        {
            cout << p.first << ": " << p.second << '\n';
        }
    }

    vector<int> answer;

    for (auto p : enroll)
    {
        answer.push_back((*money.find(p)).second);
    }
    return answer;
}