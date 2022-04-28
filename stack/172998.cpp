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

   
   
    // cin.tie(nullptr);
    // cout.tie(NULL);
    // ios_base::sync_with_stdio(false);
int main(){

    int n;
    cin >> n;
    vector<int> numbers(n);
    vector<int> ans(n,-1);
    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        numbers[i] = number;
    }

    int o_num = -1;
    for(int i= (n-2); i>=0; i--){
        if(numbers[i] < o_num && numbers[i] < numbers[i+1]){
            o_num =  numbers[i+1];
            ans[i] = o_num;
        }else if(numbers[i] < o_num && numbers[i] >= numbers[i+1]){
            ans[i] = o_num;
        }else if(numbers[i] >= o_num && numbers[i] < numbers[i+1]){
            o_num = numbers[i+1];
            ans[i] = o_num;
        }else if(numbers[i] >= o_num && numbers[i] >= numbers[i+1]){
            o_num = -1;
            ans[i] = o_num;
        }
    }
    for(auto p: ans){
        cout << p << " ";
    }
    cout << '\n';
}