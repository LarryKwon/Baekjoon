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

static vector<int> points;

int count(vector<int>& maxes, int n){
    if(maxes[n]!= 0){
        return maxes[n];
    }else if(n==0){
        return points[0];
    }
    else{
        int result1;
        int result2;
        if(maxes[n-2]!=0){
            result2 = points[n] + maxes[n-2];
        }else{
            result2 = points[n]+ count(maxes, n - 2);
        }

        if(maxes[n-3]!=0){
            result1 = points[n] + points[n-1] + maxes[n-3];
        }else{
            result1 = points[n] + points[n - 1] + count(maxes, n - 3);
        }
        // cout << n << result1 << result2 << '\n';
        maxes[n] = max(result1,result2);
        return maxes[n];
    }
}


int main(){
    int n;
    cin >> n;
    int N = n;
    points.push_back(0);
    while(n>0){
        int point;
        cin >> point;
        points.push_back(point);
        n--;
    }
    vector<int> maxes(N+1);
    maxes[0] = points[0];
    maxes[1] = points[1];
    maxes[2] = points[2] + points[1];
    int result = count(maxes,N);
    // for(auto p: points){
    //     cout << p << '\n';
    // }
    // for(auto p: maxes){
    //     cout << p << '\n';
    // }
    cout << maxes[N] << '\n';
}