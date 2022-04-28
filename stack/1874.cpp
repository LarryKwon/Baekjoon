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

bool is_parenthesis(char c){
    if(c == '(' || c == ')' || c == '{' ||  c== '}' || c == '[' || c == ']') return true;
    else return false;
}

bool complimentary(char c1, char c2){
    if((c1 == '(' && c2 == ')')) return true;
    else if(c1 == '{' && c2 == '}') return true;
    else if(c1 == '[' && c2 == ']') return true;
    else return false;
}

int main()
{
    // cin.tie(nullptr);
    // cout.tie(NULL);
    // ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> numbers;
    numbers.resize(n);
    stack<int> wanted;
    for(int i=0; i<n; i++){
        int number;
        cin >> number;
        numbers[i] = number;
    }

    // for(auto p: numbers){
    //     cout << p << " ";
    // }

    reverse(numbers.begin(),numbers.end());
    for(int i=0; i<n; i++){
        wanted.push(numbers[i]);
    }

    stack<int> stacks;
    vector<char> marks;
    for(int i=1; i<=n;i++){
        stacks.push(i);
        marks.push_back('+');
        // cout << "push: " << i << '\n';
        while(!stacks.empty() && !wanted.empty() && stacks.top() >= wanted.top() ){
            if(stacks.top() == wanted.top()){
                // cout << "stack's top: "<< stacks.top() << '\n';
                // cout << "wanted's top: " << wanted.top() << '\n';
                stacks.pop();
                wanted.pop();
                marks.push_back('-');
            }else{
                cout << "NO\n";
                return 0;
            }
        }
    }

    for(auto p: marks){
        cout << p << '\n';
    }
}   