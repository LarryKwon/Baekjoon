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

int cnt;
vector<pair<int,int>> times;

bool compare(pair<int,int>& a, pair<int,int>& b){
    if(a.second < b.second){
        return true;
    }else if(a.second == b.second){
        if(a.first < b.first) return true;
        return false;
    }else{
        return false;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    cin >> cnt;
    times.resize(cnt);

    for(int i=0; i<cnt; i++){
        int start;
        int end;
        cin >> start >> end;
        times[i] = make_pair(start,end);
    }

    sort(times.begin(),times.end(),compare);

    // for(auto p : times){
    //     cout << p.first << ' ' << p.second << '\n';
    // }

    int count = 0;
    int start = -1;
    int end = -1;
    for(int i=0; i<cnt; i++){
        int cur_start = times[i].first;
        int cur_end = times[i].second;
        
        // if(cur_end == end){
        //     if(cur_end == cur_start) count += 1;
        //     else{
        //         continue;
        //     }
        // }
        // else if(cur_start >= end){
        //     // cout << cur_start << ' ' << cur_end << '\n';
        //     start = cur_start;
        //     end = cur_end;
        //     count += 1;
        // }

        if(cur_end > end){
            if(cur_start >= end){
                start = cur_start;
                end = cur_end;
                count += 1;
            }
        }else{
            if(cur_start == cur_end) count += 1;
            else continue;
        }

    }

    cout << count << '\n';
}