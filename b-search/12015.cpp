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

vector<int> numbers;
vector<int> sequence;

int binary_search(int start, int end, int want)
{
    int result = 1000000007;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int find_num = sequence[mid];
        if (find_num >= want)
        {
            if (result > mid)
            {
                result = mid;
            }
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    // cout << "start:" << start << " end:" << end << " result:" << result << '\n';
    return result;
}

int find_list()
{
    sequence.push_back(numbers[0]);
    for (int i = 1; i < numbers.size(); i++)
    {
        int number = numbers[i];
        if (number > sequence.back())
        {
            sequence.push_back(number);
        }
        else
        {
            int replace_index = binary_search(0, sequence.size() - 1, number);
            sequence[replace_index] = number;
        }
    }
    return sequence.size();
}

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    numbers.resize(N);
    for (int i = 0; i < N; i++)
    {
        int number;
        cin >> number;
        numbers[i] = number;
    }
    find_list();
    cout << sequence.size() << '\n';
    // for (auto p : sequence)
    // {
    //     cout << p << " ";
    // }
}