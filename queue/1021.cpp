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
#include<deque>
#include <numeric>

using namespace std;

void move_left(deque<int>& deques){
    int front_elem = deques.front();
    deques.pop_front();
    deques.push_back(front_elem);
}

void move_right(deque<int>& deques){
    int back_elem = deques.back();
    deques.pop_back();
    deques.push_front(back_elem);
}

int left_circle(deque<int> deques, int want){
    int cnt = 0;
    while(deques.front() != want){
        // cout << "front:" << deques.front() << "want: " << want << '\n';
        cnt ++;
        move_left(deques);
        // cout << "left: " << cnt << '\n';
    }
    return cnt;
}

int right_circle(deque<int> deques, int want){
    int cnt = 0;
    while(deques.front() != want){
        // cout << "front:" << deques.front() << "want: " << want << '\n';
        cnt ++;
        move_right(deques);
        // cout << "right: " << cnt << '\n';
    }
    return cnt;
}

int move(deque<int>& deques, int want){
    int left = left_circle(deques,want);
    int right = right_circle(deques, want);
    if(left <= right){
        while(deques.front() != want){
            move_left(deques);
        }
        return left;
    }else{
        while(deques.front() != want){
            move_right(deques);
        }
        return right;
    }
}

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    deque<int> deques;
    int size;
    int loop;
    cin >> size >> loop;
    int ans = 0;
    for(int i=1;i<=size;i++){
        deques.push_back(i);
    }
    for(int i=0; i<loop; i++){
        int want;
        cin >> want;
        // cout << "want: " << want << '\n';
        ans = ans + move(deques,want);
        // cout << ans << '\n';
        if(want == deques.front()){
            deques.pop_front();
        }
    }
    cout << ans << '\n';
}