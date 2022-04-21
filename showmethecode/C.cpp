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
#include <deque>

using namespace std;
int n;

int ans;

void go(vector<int> &v, deque<int> dq, int depth)
{
    // 불가능한 경우
    if(!v.empty()){
        int val = v.back();
        if(val%3 == 1){
            int pos = v.size()-1;
            if(pos%3 != 1){
                return;
            }
        }
    }

    // 정답을 찾은 경우
    if(depth == 3*n) {
        ans++;
        // for(auto p: v){
        //     cout << p << " ";
        // }
        // cout << '\n';
        return ;
    }

    // 다음 경우 호출

    //앞에꺼를 넣는 경우
    int k = dq.front();
    v.push_back(k); dq.pop_front();
    go(v, dq, depth+1);
    v.pop_back(); dq.push_front(k);

    if(dq.size()!=1){
        //뒤에꺼를 넣는 경우
        k = dq.back();
        v.push_back(k); dq.pop_back();
        go(v, dq, depth+1);
        v.pop_back(); dq.push_back(k);
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    cin >> n;
    deque<int> dq;
    dq.resize(3*n);
    for(int i=0; i<3*n; i++) dq[i] = i;

    vector<int> v;
    go(v, dq, 0);

    cout << ans << '\n';
}