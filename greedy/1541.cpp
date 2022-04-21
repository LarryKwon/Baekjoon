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

int cnt;
vector<int> waits;
vector<int> sums;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> cnt;
    waits.resize(cnt);
    for (int i = 0; i < cnt; i++)
    {
        int wait;
        cin >> wait;
        waits[i] = wait;
    }

    sort(waits.begin(), waits.end());
    int sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        sum += waits[i];
        waits[i] = sum;
    }

    // for(auto p: waits){
    //     cout << p << ' ';
    // }

    int result = accumulate(waits.begin(), waits.end(), 0);
    cout << result << '\n';
}