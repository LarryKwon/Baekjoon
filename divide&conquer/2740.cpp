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

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> first(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int number;
            cin >> number;
            first[i][j] = number;
        }
    }

    int K;
    cin >> M >> K;
    vector<vector<int>> second(M, vector<int>(K));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < K; j++)
        {
            int number;
            cin >> number;
            second[i][j] = number;
        }
    }

    vector<vector<int>> result(N, vector<int>(K));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int a_first = first[i][j];
            for (int k = 0; k < K; k++)
            {
                result[i][k] += a_first * second[j][k];
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}