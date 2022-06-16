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

long long ans;
vector<int> seg;
vector<int> heights;
int n;

int init(int node, int start, int end)
{
    if (start == end)
        return seg[node] = start;
    int mid = (start + end) / 2;
    int left_index = init(2 * node, start, mid);
    int right_index = init(2 * node+1, mid + 1, end);
    return seg[node] = heights[left_index] < heights[right_index] ? left_index : right_index;
}

int query(int node, int start, int end, int left, int right)
{
    if (left > end || start > right)
    {
        return -1;
    }
    if (left <= start && end <= right)
    {
        return seg[node];
    }
    int mid = (start + end) / 2;
    int right_index = query(2 * node + 1, mid + 1, end, left, right);
    int left_index = query(2 * node, start, mid, left, right);
    if (right_index == -1)
        return left_index;
    else if (left_index == -1)
        return right_index;
    else
        return heights[left_index] < heights[right_index] ? left_index : right_index;
}

void solve(int left, int right)
{
    if (left > right)
        return;
    int index = query(1, 0, n - 1, left, right);
    ans = max(ans, (long long)heights[index] * (right - left + 1));
    // cout << "ans:" << ans << " index:" << index << " left:" << left << " right:" << right << '\n';
    solve(left, index - 1);
    solve(index + 1, right);
}

int main()
{

    // cin.tie(nullptr);
    // cout.tie(NULL);
    // ios_base::sync_with_stdio(false);

    while (true)
    {
        ans = 0;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        else
        {
            int tree_height = (int)ceil(log2(n));
            int tree_size = (1 << (tree_height + 1));

            heights.resize(n);
            seg.resize(tree_size);
            for (int i = 0; i < n; i++)
            {
                int height;
                cin >> height;
                heights[i] = height;
            }
            int start = 0;
            int end = heights.size();
            init(1, start, end - 1);
            // for (auto p : seg)
            // {
            //     cout << p << " ";
            // }
            solve(start, end - 1);
        }
        cout << ans << '\n';
    }
}