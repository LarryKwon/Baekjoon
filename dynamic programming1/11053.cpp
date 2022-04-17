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

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cin >> n;
    numbers.resize(n);

    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        numbers[i] =  number;
    }
    counts.resize(n);
    counts[0] = 1;
    for(int i=1; i<n; i++){
        int max = 0;
        for(int j=0; j<i; j++){
            if(numbers[j] < numbers[i]){
                if(max < counts[j]) max = counts[j];
            }
        }
        counts[i] = max + 1;
    }

    cout << *max_element(counts.begin(), counts.end()) << '\n';

}