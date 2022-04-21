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
vector<int> amounts;
vector<int> max_drink;

void calculate(int i)
{
    if (i >= n + 1)
    {
        return;
    }
    else
    {
        int max_amount;
        int candidate1 = amounts[i] + amounts[i - 1] + max_drink[i - 3];
        int candidate2 = amounts[i] + max_drink[i - 2];
        int candidate3 = max_drink[i - 1];
        max_amount = max(candidate3, max(candidate1, candidate2));
        max_drink[i] = max_amount;
        calculate(i + 1);
        return;
    }
}

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    amounts.push_back(0);
    for (int i = 0; i < n; i++)
    {
        int amount;
        cin >> amount;
        amounts.push_back(amount);
    }
    max_drink.resize(n + 1);
    max_drink[0] = 0;
    max_drink[1] = amounts[1];
    max_drink[2] = amounts[1] + amounts[2];
    calculate(3);
    cout << max_drink[n] << '\n';
}