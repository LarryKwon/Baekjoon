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

int m, n;
vector<vector<pair<int, int>>> input;

bool compare(pair<int, int>& a, pair<int, int>& b) {
    // if(a.second == b.second){
    //     if(a.first < b.first) return true;
    //     return false;
    // }
    if(a.second < b.second) return true;
    else return false;
}

bool check(const vector<pair<int,int>>& a, const vector<pair<int,int>>& b){
    int size = a.size();
    for(int i=0; i<n; i++){
        if(a[i].first != b[i].first) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    cin >> m >> n;
    input.resize(m, vector<pair<int, int>>(n));
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            int tmp;
            cin >> tmp;
            input[i][j] = make_pair(j, tmp);    
        }
    }

    for(int i=0; i<m; i++) {
        stable_sort(input[i].begin(), input[i].end(), compare);
    }

    int answer = 0;
    for(int i=0; i<m-1; i++){
        for(int j=i+1; j<m;j++){
            if(check(input[i],input[j])){
                answer++;
            }
        }
    }

    cout << answer << '\n';

    // for(int i=0; i<m; i++) {
    //     for(int j=0; j<n; j++) cout << input[i][j].first << " ";
    //     cout << "\n";
    // }

}