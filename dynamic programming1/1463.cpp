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

vector<int> counts(1000001,0);

int calculate(vector<int>& counts, int n){
    if(counts[n] != 0){
        return counts[n];
    }else if(n==1){
        return 0;
    }else if(n==0){
        return 0;
    }else{
        int divideBy2;
        int divideBy3;
        if(counts[n/2]!=0){
            divideBy2 = counts[n/2];
        }else{
            divideBy2 = calculate(counts,n/2);
        }

        if(counts[n/3]!=0){
            divideBy3 = counts[n/3];
        }else{
            divideBy3 = calculate(counts,n/3);
        }

        int remainderBy2 = n%2;
        int remainderBy3 = n%3;

        int count;
        switch(remainderBy3){
            case 0:
            if(remainderBy2 == 0){
                count = min(1+divideBy3, 1+divideBy2);
            }else{
                count = min(1+divideBy3, 2+divideBy2);
            }
            break;

            case 1:
            if(remainderBy2 == 0){
                count = min(2+divideBy3, 1+divideBy2);
            }else{
                count = min(2+divideBy3, 2+divideBy2);
            }
            break;

            case 2:
            if(remainderBy2 == 0){
                count = min(3+divideBy3, 1+divideBy2);
            }else{
                count = min(3+divideBy3, 2+divideBy2);
            }
            break;
        }
        counts[n] = count;
        return counts[n];
    }
}

int main(){
    int n;
    cin >> n;
    counts[0] = 0;
    counts[1] = 0;
    counts[2] = 1;
    counts[3] = 1;
    counts[4] = 2;

    int min_count = calculate(counts,n);
    cout << min_count << '\n';
}