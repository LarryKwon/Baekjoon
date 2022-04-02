#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <climits>

#define DIV 1000000007

using namespace std;
int n, q;
vector<vector<int>> house;
vector<int> num;
bool visited[1010];

void dfs(int x, int end, int val) {
    if(x == end) {
        cout << val << '\n'; 
        return ;
    }
    for(int i=0; i<house[x].size(); i++) {
        int next = house[x][i];
        if (!visited[next])
        {
            visited[next] = true;
            //num[next]의 자릿수 구하기
            int power = std::to_string(num[next]).size();
            //그만큼 val에다가 10^n만큼 곱하기
            int next_val = ((((val%DIV) * ((long long)pow(10,power)%DIV))%DIV) % DIV + num[next] % DIV)%DIV;
            dfs(next, end, next_val);
            visited[next] = false; 
        }
    }
}

void solve(int start, int end) {
    int first = num[start];
    visited[start] = true;
    dfs(start, end, first);
    visited[start] = false;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> n >> q;
    house.resize(n+1, vector<int>());
    num.resize(n+1);

    for(int i=1; i<=n; i++) {
        int tmp; 
        cin >> tmp;
        num[i] = tmp;
    }

    for(int i=1; i<=n-1; i++) {
        int a, b;
        cin >> a >> b;
        house[a].push_back(b);
        house[b].push_back(a);
    }

    for(int i=0; i<q; i++) {
        int a, b;
        cin >> a >> b;
        solve(a, b);
    }

    // for(int i=1; i<=n; i++) {
    //     for(int j=0; j<house[i].size(); j++) cout << house[i][j] << " ";
    //     cout << "\n";
    // }
}