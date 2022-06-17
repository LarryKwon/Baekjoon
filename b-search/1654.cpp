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

long long result = 0;
vector<int> lines;

bool parameticSearch(vector<int> &lines, long long start, long long end, long long want)
{

    long long frag_cnt = 0;
    long long mid = (start + end) / 2;
    if (start >= mid)
    {
        if (result <= mid)
            result = mid;
        // cout << "???: " << start << " " << end << " " << mid;
        return true;
    }

    for (auto p : lines)
    {
        frag_cnt += p / mid;
    }
    // cout << "start: " << start << " end: " << end << " mid: " << mid << " frag_cnt: " << frag_cnt << '\n';

    if (frag_cnt >= want)
    {
        result = mid;
        return parameticSearch(lines, mid, end, want);
    }
    else if (frag_cnt < want)
    {
        return parameticSearch(lines, start, mid, want);
    }
}

int main()
{

    int K;
    long long N;
    cin >> K >> N;
    lines.resize(K);
    for (int i = 0; i < K; i++)
    {
        int length;
        cin >> length;
        lines[i] = length;
    }

    sort(lines.begin(), lines.end());

    long long start = 1;
    long long end = (long long)lines[lines.size() - 1] + 1;
    bool possible = false;
    long long max = 0;
    for (auto p : lines)
    {
        max += p;
    }
    if (max >= N)
    {
        possible = true;
    }

    if (possible)
    {
        parameticSearch(lines, start, end, N);
    }
    else
    {
        cout << -1 << '\n';
        return 0;
    }
    cout << result << '\n';
}