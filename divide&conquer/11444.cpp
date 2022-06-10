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

map<long long, long long> stores;
long long solve(long long n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else if (n == 2)
    {
        return 1;
    }
    else if (stores.count(n) > 0)
    {
        return stores[n];
    }
    else
    {
        if (n % 2 == 0)
        {
            long long doganu_1 = solve(n / 2) % DIVISOR;
            long long doganu_2 = solve(n / 2 - 1) % DIVISOR;
            long long result = (2 * doganu_2 + doganu_1) % DIVISOR * doganu_1 % DIVISOR;
            stores[n] = result;
            return stores[n];
        }
        else
        {
            long long doganu_1 = solve(n / 2) % DIVISOR;
            long long doganu_3 = solve(n / 2 + 1) % DIVISOR;
            long long result = ((doganu_1 * doganu_1) % 1000000007 + (doganu_3 * doganu_3) % 1000000007) % DIVISOR;
            stores[n] = result;
            return stores[n];
        }
    }
}

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long n;
    cin >> n;
    // stores.resize((long long)n + 1, 0LL);
    // stores = (long long *)malloc(sizeof(long long) * (n + 1));
    // memset(stores, 0, sizeof(long long) * (n + 1));
    // stores.resize(n + 1);
    long long result = solve(n);
    cout << result << '\n';
    // free(stores);
}