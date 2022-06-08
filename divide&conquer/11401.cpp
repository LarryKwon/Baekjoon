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

#define DIVISOR 1000000007;

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

long long int fibonacci_mod(int n, int mod)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return ((n % mod) * (fibonacci_mod(n - 1, mod) % mod)) % mod;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    // dividend: n*(n-1)....(n-k+1)
    // divisor: n-k *(n-k-1)...1

    long long int dividend = 1;
    for (int i = 0; i < (N - K); i++)
    {
        dividend = ((dividend % 1000000007) * ((N - i) % 1000000007)) % 1000000007;
    }

    long long int divisor = 1;
    int divisor_mod = fibonacci_mod(N - K, 1000000007);
    long long int reverse_divisor = power_remain(divisor_mod, 1000000005, 1000000007);
    long long int result = ((dividend % 1000000007 * reverse_divisor % 1000000007)) % 1000000007;
    cout << result << '\n';
}