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
#include <stdio.h>
#include <cstring>

using namespace std;

vector<long long> trees;
int max_height = 0;

bool check(const vector<long long> &trees, long long mid, long long amount)
{
    long long cutted = 0;
    for (auto p : trees)
    {
        if (p > mid)
        {
            cutted += (p - mid);
        }
    }
    if (cutted >= amount)
    {
        // cout << "mid: " << mid << " cutted:" << cutted << " amount: " << amount << '\n';
        return true;
    }
    else
        return false;
}

bool parameticSearch(vector<long long> &trees, long long start, long long end, long long amount)
{
    long long mid = (start + end) / 2;
    if (start >= mid)
    {
        if (mid > max_height)
            max_height = mid;
        return true;
    }
    else
    {
        if (check(trees, mid, amount))
        {
            if (mid > max_height)
            {
                max_height = mid;
            }
            return parameticSearch(trees, mid, end, amount);
        }
        else
        {
            return parameticSearch(trees, start, mid, amount);
        }
    }
}

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long N, M;
    cin >> N >> M;
    trees.resize(N);
    for (int i = 0; i < N; i++)
    {
        long long height;
        cin >> height;
        trees[i] = height;
    }
    sort(trees.begin(), trees.end());
    long long start = 0;
    long long end = trees[trees.size() - 1] + 1;
    parameticSearch(trees, start, end, M);
    cout << max_height << '\n';
}