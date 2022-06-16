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

long long DIVISOR = 1000000007;

using namespace std;

long long ans;

long long solve(vector<int> &heights, int start, int end)
{
    if (start >= end)
    {
        return -1;
    }

    auto start_iter = heights.begin() + start;
    auto end_iter = heights.begin() + end;
    auto min_height_iter = min_element(start_iter, end_iter);
    int min_height = *min_height_iter;
    int min_height_index = distance(heights.begin(), min_height_iter);
    long long temp = (long long)min_height * (end - start);
    // cout << "start: " << start << " end: " << end << "min_height: " << min_height << " temp: " << temp << '\n';
    long long right_temp = solve(heights, min_height_index + 1, end);
    long long left_temp = solve(heights, start, min_height_index);

    long long result = max(max(temp, left_temp), right_temp);
    if (ans <= result)
    {
        ans = result;
    }
    return result;
}

int main()
{

    // cin.tie(nullptr);
    // cout.tie(NULL);
    // ios_base::sync_with_stdio(false);

    while (true)
    {
        ans = 0;
        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        else
        {
            vector<int> heights(n);
            for (int i = 0; i < n; i++)
            {
                int height;
                cin >> height;
                heights[i] = height;
            }
            int start = 0;
            int end = heights.size();
            solve(heights, start, end);
        }
        cout << ans << '\n';
    }
}