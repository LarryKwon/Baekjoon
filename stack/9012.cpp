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

int main()
{
    // cin.tie(nullptr);
    // cout.tie(NULL);
    // ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        stack<char> parenthesis;
        string line;
        getline(cin,line);
        istringstream iss{line};
        char c;
        while(iss>>c){
            if(c=='(') parenthesis.push(c);
            else if(c==')') {
                if(parenthesis.size()!=0){
                    if(parenthesis.top()=='('){
                        parenthesis.pop();
                    }else{
                        parenthesis.push(c);
                    }
                }else{
                    parenthesis.push(c);
                }
            }
        }
        if(parenthesis.size()!=0) cout << "NO\n";
        else cout << "YES\n";
        cin.clear(ios_base::goodbit);
    }
}