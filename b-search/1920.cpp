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

vector<int> num_lists;

bool bSearch(vector<int> &num_lists, int target, int start, int end)
{
    if (start == end)
    {
        if (start >= num_lists.size())
        {
            return false;
        }
        if (target == num_lists[start])
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int mid = (start + end) / 2;
        int mid_elem = num_lists[mid];
        if (target == mid_elem)
        {
            return true;
        }
        else if (target > mid_elem)
        {
            return bSearch(num_lists, target, mid + 1, end);
        }
        else if (target < mid_elem)
        {
            return bSearch(num_lists, target, start, mid);
        }
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    num_lists.resize(N);

    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        num_lists[i] = number;
    }
    sort(num_lists.begin(), num_lists.end());

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int elem;
        cin >> elem;
        int result = bSearch(num_lists, elem, 0, N);
        cout << result << '\n';
    }
}