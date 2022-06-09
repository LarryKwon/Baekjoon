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

vector<vector<long long>> calculate_matrix(vector<vector<long long>> A, vector<vector<long long>> B)
{
    vector<vector<long long>> result = vector<vector<long long>>(A.size(), vector<long long>(B[0].size()));

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            long long multiply = A[i][j];
            for (int k = 0; k < B[j].size(); k++)
            {
                result[i][k] += ((multiply % 1000) * (B[j][k] % 1000)) % 1000;
                result[i][k] %= 1000;
            }
            result[i][j] %= 1000;
        }
    }
    return result;
}

vector<vector<long long>> solve(vector<vector<long long>> base, int size, long long power)
{
    if (power == 1)
    {
        for (int i = 0; i < base.size(); i++)
            for (int j = 0; j < base.size(); j++)
                base[i][j] %= 1000;
        return base;
    }
    else if (power % 2 == 0)
    {
        vector<vector<long long>> prev_step = solve(base, size, power / 2);
        return calculate_matrix(prev_step, prev_step);
    }
    else
    {
        vector<vector<long long>> prev_step = solve(base, size, power - 1);
        return calculate_matrix(base, prev_step);
    }
}

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    long long power;
    cin >> N >> power;
    vector<vector<long long>> A(N, vector<long long>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            long long number;
            cin >> number;
            A[i][j] = number;
        }
    }

    vector<vector<long long>> result = solve(A, N, power);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}