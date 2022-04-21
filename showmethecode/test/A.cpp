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
#include <climits>

using namespace std;

int N;
int ans = INT_MAX;
vector<vector<int>> discount_info;
bool visited [13];

vector<int> get_new_prices(vector<int> origin, int selected){
    for(int i=1; i<=N; i++){
        int discount_amount = discount_info[selected][i];
        if(origin[i]-discount_amount <= 0){
            origin[i] = 1;
        }else{
            origin[i] = origin[i] - discount_amount;
        }
    }
    return origin;
}

void go(vector<int>& v, vector<int> prices, int total){
    if(v.size()==N){
        ans = min(ans, total);
        return ;
    }
    if(total >= ans){
        return;
    }
    for(int i=1; i<=N; i++){
        if(!visited[i]){
            visited[i] = true;
            v.push_back(i);
            go(v,get_new_prices(prices,i),total+prices[i]);
            v.pop_back();
            visited[i] = false;
        }
    }
}


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<int> prices;
    cin >> N;
    cin.ignore();
    prices.push_back(0);
    discount_info.resize(N+1, vector<int>(N+1));
    string line;
    getline(cin,line);
    istringstream iss{line};

    int price;
    while(iss >> price){
        prices.push_back(price);
    }

    for(int i=1; i<= N; i++){
        int n;
        cin >> n;
        for(int j=0; j<n; j++){
            int target;
            int discount_amount;
             cin >> target >> discount_amount;
             discount_info[i][target] = discount_amount;
        }
    }
    vector<int> v;
    go(v,prices,0);
    cout << ans << '\n';
}