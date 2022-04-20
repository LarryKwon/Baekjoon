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

int number_cnt;
int seq_cnt;
vector<int> temperature;
vector<int> partialSum;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> number_cnt;
    cin >> seq_cnt;
    temperature.resize(number_cnt);
    for(int i=0; i<number_cnt; i++){
        int temp;
        cin >> temp;
        temperature[i] = temp;
    }
    partialSum.resize(number_cnt - seq_cnt + 1);
    int first_sum = 0;
    for(int i=0; i<seq_cnt; i++){
        first_sum += temperature[i];
    }
    partialSum[0] = first_sum;
    for(int i=1; i<partialSum.size();i++){
        partialSum[i] = partialSum[i-1] - temperature[i-1] + temperature[i+seq_cnt-1];
    }
    cout << *max_element(partialSum.begin(),partialSum.end()) << '\n';

}