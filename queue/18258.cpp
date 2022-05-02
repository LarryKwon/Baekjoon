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
class queue{
    vector<Elem> elements;
    int index;

    public:
    queue()
    :elements{vector<Elem>(0)}, index(0){}

    void push(Elem e);
    Elem pop();
    int size();
    int empty();
    int front();
    int back();
};

template<typename Elem>
void queue<Elem>::push(Elem e){
    elements.push_back(e);
}

template <typename Elem>
Elem queue<Elem>::pop()
{
    if(this->size()==0) return -1;
    else {
        Elem e = elements[index];
        index ++;
        return e;
    }
}

template <typename Elem>
int queue<Elem>::size()
{
    return elements.size() - index;
}
template <typename Elem>
int queue<Elem>::empty()
{
    if(this->size()==0) return 1;
    else return 0;
}

template <typename Elem>
int queue<Elem>::front()
{
    if(this->empty()) return -1;
    else return elements[index];
}

template <typename Elem>
int queue<Elem>::back()
{
    if(this->empty()) return -1;
    else return elements.back();
}

int main(){
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    queue<int> queues;
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
            queues.push(val);
        }else if(command.find("pop")!= string::npos){
            cout << queues.pop() << '\n';
        }else if(command.find("size")!= string::npos){
            cout << queues.size() << '\n';
        }else if(command.find("empty")!= string::npos){
            cout << queues.empty() << '\n';
        }else if(command.find("front")!=string::npos){
            cout << queues.front() << '\n';
        }else if(command.find("back")!=string::npos){
            cout << queues.back() << '\n';
        }
    }
}