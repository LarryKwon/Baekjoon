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

#define Long long long

using namespace std;

vector<long long> sum_dividend(1000010);


int main(){
    int n;
    cin >> n;
    // for(int i=1; i<=n; i++){
    //     for(int j=1; i*j<=n; j++){
    //         sum_dividend[i*j] += j;
    //     }
    // }

    long long sum = 0;
    for(int i=1; i<=n; i++){
        int cnt =  n/i;
        sum += cnt * i;
    }

    // auto p = sum_dividend.begin();
    // ++p;
    // while(*p!=0){
    //     // cout << *p << '\n';
    //     sum += *p;
    //     ++p;
    // }
    cout << sum << '\n';
}