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


int main(){
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int cnt;
    cin >> cnt;
    for(int i=0; i<cnt; i++){
        int n, m;
        cin >> n >> m;
        // cin.ignore();
        string numbers;
        istringstream iss{numbers};
        getline(cin,numbers);

        queue<pair<int,int>> items;
        priority_queue<int> priorities;
        int priority;
        int index = 0;
        for(int i=0; i<n; i++){
            cin >> priority;
            pair<int,int> item = pair<int,int>(priority,index);
            index ++;
            items.push(item);
            priorities.push(priority);
        }
        cin.clear(ios_base::goodbit);
        int count = 0;
        while(!items.empty()){
            pair<int,int> item = items.front();
            int priority = items.front().first;
            int index = items.front().second;
            items.pop();

            if(priorities.top()==priority){
                priorities.pop();
                count ++;
                if(m==index){
                    cout << count << '\n';
                    break;
                }
            }else items.push(item);
        }
    }

}