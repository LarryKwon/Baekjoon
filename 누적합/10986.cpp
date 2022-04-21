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
int divisior;

vector<long long> remainders;
int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> cnt >> divisior;
    remainders.resize(divisior);
    long long sum = 0;
    long long count = 0;
    for(int i=0; i<cnt; i++){
        long long number;
        cin >> number;
        sum += number;
        sum %= divisior;
        remainders[sum] += 1;
    }

    count += remainders[0];
    for(int i=0; i<divisior; i++){
        count += remainders[i] * (remainders[i]-1) / 2;
    }
    cout << count << '\n';
}