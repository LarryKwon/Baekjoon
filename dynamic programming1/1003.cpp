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

//peudo code

/*

int n;
static vector<int> numbers (n)

int fibonacci(int n){
    if(n==1){
        return numbers[1];
    }
    else if(n==0){
        return numbers[0];
    }else{
        if(numbers[n]!=0){
            return numbers[n];
        }else{
            numbers[n] = fibonacci(n-1) + fibonacci(n-2);
            return numbers[n];
        }
    }
}
*/

static vector<pair<int,int>> counts(40);

pair<int,int>& fibonacci(int n){
    if(n==1){
        return counts[1];
    }else if(n==0){
        return counts[0];
    }else{
        if(counts[n].first != 0 && counts[n].second != 0){
            return counts[n];
        }else{
            pair<int,int> prev = fibonacci(n-1);
            pair<int,int> prev_prev = fibonacci(n-2);
            counts[n].first = prev.first + prev_prev.first;
            counts[n].second = prev.second + prev_prev.second;
            return counts[n];
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> test;
    int n;
    while(N>0){
        cin >> n;
        test.push_back(n);
        N--;
    }
    counts[0].first = 1;
    counts[0].second = 0;

    counts[1].first = 0;
    counts[1].second = 1;

    for(auto p:test){
        pair<int,int>& nth = fibonacci(p);
        cout << nth.first << " " << nth.second << '\n';
    }
}