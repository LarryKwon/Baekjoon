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
#include<queue>
#include <numeric>

using namespace std;

void move(queue<int>& queue){
    int top = queue.front();
    queue.pop();
    queue.push(top);
}


int main(){
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    queue<int> crowd;

    int n, k;
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        crowd.push(i);
    }

    vector<int> ans;

    while(crowd.size()>0){
        for(int i=0; i<k-1; i++){
            move(crowd);
        }
        int number = crowd.front();
        crowd.pop();
        ans.push_back(number);
    }
    ostringstream oss;
    oss << '<';
    for(int i=0; i<ans.size()-1; i++){
        oss << ans[i] << ", ";
    }
    oss << ans.back() << ">";
    cout << oss.str() << '\n';
}