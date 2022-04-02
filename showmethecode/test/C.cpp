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

using namespace std;

int ans;

void divide_conquer(string keyword, string target){
    if(keyword.size() == 1){
        int count = 0;
        for(int i=0; i<target.size(); i++) {
            if(target[i] == 'E') count++;
        }
        ans += (int)pow(2, count) - 1;
        ans = ans % 1000000007;
        return;
    }
    
    for(int i=0; i<target.size(); i++){
        if(target[i] == keyword[0]){
            divide_conquer(keyword.substr(1,keyword.size()-1), target.substr(i+1,target.size()-(i+1)));
        }
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string str;
    cin >> str;
    divide_conquer("WHEE",str);
    cout << ans << '\n';
}