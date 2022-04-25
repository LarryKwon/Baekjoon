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

template<typename Elem>
class stack{
    vector<Elem> elements;

    public:
    stack()
    :elements{vector<Elem>(0)}{}

    void push(Elem e);
    Elem pop();
    int size();
    Elem top();
    int empty();
};

template<typename Elem>
void stack<Elem>::push(Elem e){
    elements.push_back(e);
}

template <typename Elem>
Elem stack<Elem>::pop()
{
    if(elements.size()==0) return -1;
    else {
        Elem e = elements.back();
        elements.pop_back();
        return e;
    }
}
template <typename Elem>
Elem stack<Elem>::top()
{
    if(elements.size()==0) return -1;
    else return elements.back();
}
template <typename Elem>
int stack<Elem>::size()
{
    return elements.size();
}
template <typename Elem>
int stack<Elem>::empty()
{
    if(elements.size()==0) return 1;
    else return 0;
}

int main(){
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    stack<int> stack;
    int n;
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string command;
        getline(cin,command);
        // cin.ignore();
        // cout << command << '\n';
        if(command.find("push")!=string::npos){
            istringstream iss{command};
            string s1;
            int val;
            iss >> s1 >> val;
            stack.push(val);
        }else if(command.find("pop")!= string::npos){
            cout << stack.pop() << '\n';
        }else if(command.find("size")!= string::npos){
            cout << stack.size() << '\n';
        }else if(command.find("empty")!= string::npos){
            cout << stack.empty() << '\n';
        }else if(command.find("top")!=string::npos){
            cout << stack.top() << '\n';
        }
    }
}