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
int repeat;
vector<int> numbers;
vector<int> sums;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> number_cnt;
    cin >> repeat;

    numbers.resize(number_cnt);
    sums.resize(number_cnt);
    for(int i=0; i<number_cnt; i++){
        int number;
        cin >> number;
        numbers[i] = number;
    }

    int sum = 0;
    for(int i=0; i<number_cnt; i++){
        sum += numbers[i];
        sums[i] = sum;
    }

    for(int i=0; i<repeat; i++){
        int start;
        int end;
        cin >> start >> end;

        start -= 1;
        end -= 1;
        int sum1 = sums[end];
        int sum2 = (start < 0)? 0 : sums[start];
        int value = sum1 - sum2 + numbers[start];
        cout << value << '\n';
    }

}