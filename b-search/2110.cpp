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

vector<long long> locations;
long long max_dist = 0;

bool check(vector<long long> &locations, long long mid, long long amount)
{

    long long cnt = 1;
    long long prev = locations[0];
    for (int i = 1; i < locations.size(); i++)
    {
        if ((locations[i] - prev) >= mid)
        {
            cnt++;
            prev = locations[i];
        }
    }

    if (cnt >= amount)
    {
        // cout << "mid: " << mid << " cnt:" << cnt << " amount: " << amount << '\n';
        return true;
    }
    else
    {
        // cout << "mid: " << mid << " cnt:" << cnt << " amount: " << amount << '\n';
        return false;
    }
}

bool parameticSearch(vector<long long> &locations, long long start, long long end, long long amount)
{
    long long mid = (start + end) / 2;
    if (start > end)
    {
        // // // cout << "??: " << mid << " start:" << start << " end:" << end << '\n';
        // if (check(locations, mid, amount))
        // {
        //     if (mid >= max_dist)
        //         max_dist = mid;
        //     return true;
        // }
        return true;
    }
    else
    {
        if (check(locations, mid, amount))
        {
            if (mid >= max_dist)
                max_dist = mid;
            return parameticSearch(locations, mid + 1, end, amount);
        }
        else
        {
            return parameticSearch(locations, start, mid - 1, amount);
        }
    }
}

int main()
{

    long long N, C;
    cin >> N >> C;
    locations.resize(N);
    for (int i = 0; i < N; i++)
    {
        long long location;
        cin >> location;
        locations[i] = location;
    }
    sort(locations.begin(), locations.end());
    long long end = locations[N - 1] - locations[0];

    // if (!check(locations, 1, C))
    // {
    //     cout << 0 << '\n';
    //     return 0;
    // }
    parameticSearch(locations, 1, end, C);
    cout << max_dist << '\n';
}