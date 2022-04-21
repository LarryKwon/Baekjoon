#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<numeric>

using namespace std;

static bool numbers[9] = {0,};
static int permutations[9] = {0,};

void back_track(int n, int m, int cnt, int prev_val){
    if(cnt == m){
        for(int j=0; j<m; j++){
            cout << permutations[j] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i=prev_val; i<=n;i++){
        if(numbers[i] == false){
            numbers[i] = true;
            permutations[cnt] = i;
            // cout << "cnt: " << cnt << " permutations[cnt]: "<< permutations[cnt] <<'\n';
            back_track(n,m,cnt+1, i);
            numbers[i] = false;
            permutations[cnt] = 0;
        }
        // true일 때는 아무짓도 하지 않아야함.
        // 기본적으로 numbers의 요소가 false인 경우에 대해서 다음 숫자를 pick하는 것
        // //back_track(n,m,i+1);
        // numbers[i] = false;
        // permutations[i] = 0;
    }
}


int main(){
    int n;
    int m;
    cin >> n >> m;
    back_track(n,m,0,1);
}