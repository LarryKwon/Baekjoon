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

int cnt, value;
vector<int> coins;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> cnt >> value;
    coins.resize(cnt);

    for(int i=0; i<cnt; i++){
        int coin;
        cin >> coin;
        coins[i] = coin;
    }

    reverse(coins.begin(),coins.end());
    
    int count = 0;

    for(int i=0; i<cnt; i++){
        while(coins[i]<=value){
            count += 1;
            value -= coins[i];
        }
        if(value == 0) break;
        // cout << value << '\n';
    }

    cout << count << '\n';
}