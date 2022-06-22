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

long long N;
long long K;

long long result = 0;

bool check(long long K, long long mid)
{
    long long sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += min(mid / i, N);
    }
    return sum >= K;
}

void parameticSearch(long long K, long long start, long long end)
{
    long long mid = (start + end) / 2;
    if (start > end)
    {
        return;
    }
    else
    {
        if (check(K, mid))
        {
            result = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
        parameticSearch(K, start, end);
    }
}

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;

    parameticSearch(K, 1, N * N);
    cout << result << '\n';
}

// 1 2 3 4 5 6 2 4 6 8 10 12 3 6 9 12 15 18 4 8 12 16 20 24 5 10 15 20 25 30 6 12 18 24 30 36