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

vector<vector<int>> sums;
vector<vector<int>> numbers;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int cnt;
    int repeat;
    cin >> cnt >> repeat;

    int sum = 0;
    sums.resize(cnt+1,vector<int>(cnt+1));
    numbers.resize(cnt+1,vector<int>(cnt+1));
    for(int i=0; i<cnt; i++){
        for(int j=0; j<cnt; j++){
            int number;
            cin >> number;
            numbers[i+1][j+1] = number;
            sums[i+1][j+1] = sums[i][j+1] + sums[i+1][j] - sums[i][j] + number;
        }
    }


    // for(auto p: sums){
    //     for(auto q: p){
    //         cout << q << ' ';
    //     }
    //     cout << '\n';
    // }

    int partialSum = 0;
    for(int i=0; i<repeat; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        // //걷어내야하는 부분
        // 0<= x <x1 && y1 < y <= y2 // 왼쪽 아래
        // 0<= y < y1 && x1 < x <= x2 // 오른쪽 위

        partialSum = 0;

        int x;
        int y;
        partialSum = sums[x2][y2] - sums[x1][y1] + numbers[x1][y1];
        // cout << "initialSum: " << partialSum << '\n';
        int sub1 = 0;
        int sub2 = 0;

            //왼쪽 아래
            sub1 = sums[x1-1][y2] - sums[x1-1][y1];
            // cout << "sub1: " << sub1 << '\n';
            
            //오른쪽 위
            sub2 = sums[x2][y1-1] - sums[x1][y1-1];
            // cout << "sub2: " << sub2 << '\n';
        
        partialSum = partialSum - sub1 - sub2;
        cout << partialSum << '\n';
    }
    
    
}