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
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    while(true){    
        stack<char> stacks;
        string line;
        getline(cin,line);
        istringstream iss{line};
        char c;
        int i;
        if(line.size()==1 && line[0]=='.') break;
        for(i=0; i<line.size();i++){
            c = line[i];
            if(is_parenthesis(c)){
                if(c == '(' || c == '{' || c=='[') stacks.push(c);
                else{
                    if(stacks.empty()){
                        cout << "no\n";
                        break;
                    }else{
                        char top = stacks.top();
                        if(complimentary(top,c)) stacks.pop();
                        else{
                            cout << "no\n";
                            break;
                        }
                    }
                }
            }
        }
        if(i==line.size()){
            if(stacks.size()==0) cout << "yes\n";
            else{
                cout << "no\n";
            }
        }
        
        
        cin.clear(ios_base::goodbit);
    }
}