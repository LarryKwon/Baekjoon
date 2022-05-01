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
#include<stack>
#include <numeric>

using namespace std;

int main(){

    // cin.tie(nullptr);
    // cout.tie(NULL);
    // ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> numbers(n);
    vector<int> ans(n,-1);
    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        numbers[i] = number;
    }

    stack<int> stacks;
    for(int i=n-1; i>=0; i--){
        if(stacks.empty()){
            ans[i] = -1;
            stacks.push(numbers[i]);
        }else{
            while( !stacks.empty() && stacks.top() <= numbers[i]){
                stacks.pop();
            }
            if(stacks.empty()){
                ans[i] = -1;
                stacks.push(numbers[i]);
            }else{
                ans[i] = stacks.top();
                stacks.push(numbers[i]);
            }
        }
    }

    int o_num = -1;
    for(auto p: ans){
        cout << p << " ";
    }
    cout << '\n';
}