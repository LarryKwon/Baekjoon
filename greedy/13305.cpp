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
// #define Long long long;
using Long = unsigned long long;

int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    Long n;
    cin >> n;
    vector<Long> dist(n-1);
    vector<Long> prices(n);
    for(int i=0; i<n-1; i++){
        Long distance;
        cin >> distance;
        dist[i] = distance;
    }

    for(int i=0; i<n; i++){
        Long price;
        cin >> price;
        prices[i] = price;
    }

    Long price = prices[0];
    Long total = 0;
    for(int i=0; i<n-1; i++){
        if(prices[i] < price){
            price = prices[i];
        }
        total += price * dist[i];
    }

    cout << total << '\n';

}