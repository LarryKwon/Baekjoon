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

template <typename Elem>
class dequeue
{
    vector<Elem> elements;
    int index;

public:
    dequeue()
        : elements{vector<Elem>(0)}, index(0) {}

    void push_front(Elem e);
    void push_back(Elem e);
    Elem pop_front();
    Elem pop_back();
    int size();
    int empty();
    int front();
    int back();
};

template <typename Elem>
void dequeue<Elem>::push_back(Elem e)
{
    elements.push_back(e);
}

template <typename Elem>
void dequeue<Elem>::push_front(Elem e)
{
    if(index == 0){
        elements.insert(elements.begin(), e);
    }else{
        elements[index-1] = e;
        index--;
    }
    
}

template <typename Elem>
Elem dequeue<Elem>::pop_front()
{
    if (this->size() == 0)
        return -1;
    else
    {
        Elem e = elements[index];
        index++;
        return e;
    }
}

template <typename Elem>
Elem dequeue<Elem>::pop_back()
{
    if (this->size() == 0)
        return -1;
    else
    {   
        Elem e = this->elements.back();
        this->elements.pop_back();
        return e;
    }
}

template <typename Elem>
int dequeue<Elem>::size()
{
    return elements.size() - index;
}
template <typename Elem>
int dequeue<Elem>::empty()
{
    if (this->size() == 0)
        return 1;
    else
        return 0;
}

template <typename Elem>
int dequeue<Elem>::front()
{
    if (this->empty())
        return -1;
    else
        return elements[index];
}

template <typename Elem>
int dequeue<Elem>::back()
{
    if (this->empty())
        return -1;
    else
        return elements.back();
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    dequeue<int> dequeues;
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string command;
        getline(cin, command);
        // cin.ignore();
        // cout << command << '\n';
        if (command.find("push_back") != string::npos)
        {
            istringstream iss{command};
            string s1;
            int val;
            iss >> s1 >> val;
            dequeues.push_back(val);
        }
        else if(command.find("push_front")!= string::npos){
            istringstream iss{command};
            string s1;
            int val;
            iss >> s1 >> val;
            dequeues.push_front(val);
        }
        else if (command.find("pop_front") != string::npos)
        {
            cout << dequeues.pop_front() << '\n';
        }
        else if(command.find("pop_back")!=string::npos){
            cout << dequeues.pop_back() << '\n';
        }
        else if (command.find("size") != string::npos)
        {
            cout << dequeues.size() << '\n';
        }
        else if (command.find("empty") != string::npos)
        {
            cout << dequeues.empty() << '\n';
        }
        else if (command.find("front") != string::npos)
        {
            cout << dequeues.front() << '\n';
        }
        else if (command.find("back") != string::npos)
        {
            cout << dequeues.back() << '\n';
        }
    }
}