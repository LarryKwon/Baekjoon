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

/*
pseudo code

*/

static long long numbers[101] = {0,};

long long count(int n){
    if(n<10){
        return numbers[n];
    }else{
        if(numbers[n]!=0){
            return numbers[n];
        }else{
            numbers[n] = count(n-1) + count(n-5);
            return numbers[n];
        }
    }
}

int main(){
    int N;
    cin >> N;
    numbers[1] = 1;
    numbers[2] = 1;
    numbers[3] = 1;
    numbers[4] = 2;
    numbers[5] = 2;
    numbers[6] = 3;
    numbers[7] = 4;
    numbers[8] = 5;
    numbers[9] = 7;

    while(N>0){
        int n;
        cin >> n;
        count(n);
        cout << numbers[n] << '\n';
        N--;
    }
}