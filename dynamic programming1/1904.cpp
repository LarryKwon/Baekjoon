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
00이거나 1만을 이용해서 길이가 N인 모든 2진 수열의 갯수
N=1 : 1
N=2 : 11, 00 -> 2
N=3 : 110,011,111 -> 3
N=4 : 0011,0000, 1110, 1011, 1111 -> 5
f(n) = f(n-1)  f(n-2)

*/

static  long long int numbers[1000001] = {0,};

long long count(int N)
{
    if(N==1){
        return 1;
    }else if(N==2){
        return 2;
    }else {
        if(numbers[N] != 0){
            return numbers[N];
        }else{
            numbers[N] = (count(N-1) + count(N-2))%15746;
            return numbers[N];
        }
    }
}

int main(){
    int N;
    cin >> N;
    numbers[1] = 1;
    numbers[2] = 2;
    count(N);
    cout << numbers[N] << '\n';
}