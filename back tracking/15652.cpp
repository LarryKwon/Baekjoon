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

static bool numbers[9] = {
    0,
};
static int permutations[9] = {
    0,
};

void back_track(int n, int m, int cnt, int prev_val)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << permutations[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = prev_val; i <= n; i++)
    {
        if (numbers[i] == false)
        {
            permutations[cnt] = i;
            // cout << "cnt: " << cnt << " permutations[cnt]: "<< permutations[cnt] <<'\n';
            back_track(n, m, cnt + 1, i);
        }
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    back_track(n, m, 0, 1);
}