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
vector<int> numbers;
vector<int> counts;
vector<int> reverse_counts;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    numbers.resize(n);

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        numbers[i] = number;
    }
    counts.resize(n);
    reverse_counts.resize(n);
    counts[0] = 1;
    reverse_counts[n-1] = 1;
    for (int i = 1; i < n; i++)
    {
        int max = 0;
        for (int j = 0; j < i; j++)
        {
            if (numbers[j] < numbers[i])
            {
                if (max < counts[j])
                    max = counts[j];
            }
        }
        counts[i] = max + 1;
    }

    for(int i=(n-2); i>=0; i--){
        int max = 0;
        for(int j=(n-1); j>i; j--){
            if(numbers[i] > numbers[j]){
                if(max < reverse_counts[j]) max = reverse_counts[j];
            }
        }
        reverse_counts[i] = max + 1;
    }

    int max = 0;
    for(int i=0; i<n; i++){
        // cout << counts[i] << ' ' << reverse_counts[i] << '\n';

        if(max < counts[i] + reverse_counts[i]) max = counts[i] + reverse_counts[i];
    }

    cout << (max-1) << '\n';
}