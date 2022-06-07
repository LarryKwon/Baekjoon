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

#define Long long long int;

using namespace std;

long long int power_remain(int base, int power, int divisor)
{
    if (divisor == 1)
    {
        return 0;
    }

    if (power == 1)
    {
        return base % divisor;
    }
    else if (power % 2 == 0)
    {
        long long int prev_step = power_remain(base, power / 2, divisor);
        return ((prev_step % divisor) * (prev_step % divisor)) % divisor;
    }
    else
    {
        long long int prev_step = power_remain(base, power - 1, divisor);
        return ((prev_step % divisor) * (base % divisor)) % divisor;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int A, B, C;
    cin >> A >> B >> C;

    long long int result;

    result = power_remain(A, B, C);
    cout << result << '\n';
}