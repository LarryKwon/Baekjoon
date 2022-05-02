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
    
    queue<int> cards;

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        cards.push(i);
    }

    while(cards.size()>1){
        cards.pop();
        int top = cards.front();
        cards.pop();
        cards.push(top);
    }
    cout << cards.front() << '\n';
}