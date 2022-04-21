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
#include <numeric>

using namespace std;

int n;
vector<pair<int, int>> line_pairs;
vector<int> forward_min;
vector<int> reverse_min;

bool pair_max(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return true;
    else
        return false;
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    line_pairs.resize(n);

    for (int i = 0; i < n; i++)
    {
        int line1;
        int line2;

        cin >> line1 >> line2;
        line_pairs[i] = pair<int, int>(line1, line2);
    }

    forward_min.resize(n);
    reverse_min.resize(n);

    sort(line_pairs.begin(), line_pairs.end(), pair_max);
    forward_min[0] = 1;
    reverse_min[n - 1] = 1;

    for (int i = 1; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (line_pairs[j].second < line_pairs[i].second)
            {
                if (max < forward_min[j])
                    max = forward_min[j];
            }
        }
        forward_min[i] = max + 1;
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << line_pairs[i].first << ' ' << line_pairs[i].second << ' ' << forward_min[i] << ' ' << reverse_min[i] << '\n';
    // }

    int max1 = *max_element(forward_min.begin(), forward_min.end());
    cout << (n - max1) << '\n';
}