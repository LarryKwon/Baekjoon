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
#include<stack>
#include <numeric>

using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    stack<int> numbers;
    int sum = 0;
    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        if(number == 0) numbers.pop();
        else numbers.push(number);
    }

    while(numbers.size()!=0){
        sum += numbers.top();
        numbers.pop();
    }
    cout << sum << '\n';

}