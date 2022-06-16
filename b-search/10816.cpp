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

int result = 0;
void bSearch(vector<int> &num_lists, int target, int start, int end)
{

    if (start > end)
    {
        return;
    }

    if (start == end)
    {
        if (start < num_lists.size() && target == num_lists[start])
        {
            result++;
            // cout << "target: " << target << " start: " << start << " end: " << end << '\n';
        }
    }
    else
    {
        int mid = (start + end) / 2;
        int mid_elem = num_lists[mid];
        if (target == mid_elem)
        {
            result++;
            // cout << "target: " << target << " start: " << start << " end: " << end << " mid: " << mid << '\n';
            if (target <= num_lists[end - 1])
            {
                bSearch(num_lists, target, mid + 1, end);
            }
            if (target >= num_lists[start])
            {
                bSearch(num_lists, target, start, mid - 1);
            }
        }
        else if (target > mid_elem)
        {
            bSearch(num_lists, target, mid + 1, end);
        }
        else if (target < mid_elem)
        {
            bSearch(num_lists, target, start, mid);
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
        int target;
        cin >> target;
        bSearch(num_lists, target, 0, N - 1);
        cout << result << " ";
        result = 0;
    }
}