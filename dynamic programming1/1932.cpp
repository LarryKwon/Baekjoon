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
vector<int> numbers;
vector<int> maxes;
int count(int y, int x){
    int index = (y+1)*(y)/2 + x;
    if(depth == 0){
        return maxes[0];
    }else{
        int max;
        int prev_index1 = (y)*(y-1)/2 + x;
        int prev_index2 = (y)*(y-1)/2 + x-1;
        int prev_max1;
        int prev_max2;
        if(x==0){
            if(maxs[prev_index1]!=0){
                prev_max1 = maxes[prev_index1];
            }else{
                prev_max1 = count(y-1,x);
            }
            max = prev_max1 + numbers[index];
            maxes[index] = max;
        }else if(x==y){
            if(maxes[prev_index2]!=0){
                prev_max2 = maxes[prev_index2]
            }else{
                prev_max2 = count(y-1,x-1);
            }
            max = prev_max2 + numbers[index];
            maxes[index] = max;
        }else{
            if(maxes[prev_index1]!=0){
                prev_max1 = maxes[prev_index1];
            }else{
                prev_max1 = count(y-1,x);
            }
            if(maxes[prev_index2]!=0){
                prev_max2 = maxes[prev_index2];
            }else{
                prev_max2 = count(y-1,x-1);
            }
            max = max(prev_max1, prev_max2) + numbers[index];
            maxes[index] = max;
        }
        return maxes[index];
    }
}
*/

static vector<int> numbers;
static vector<int> maxes;

int count(int y, int x)
{
    int index = (y + 1) * (y) / 2 + x;
    if (y == 0)
    {
        return maxes[0];
    }
    else
    {
        int max;
        int prev_index1 = (y) * (y - 1) / 2 + x;
        int prev_index2 = (y) * (y - 1) / 2 + x - 1;
        int prev_max1;
        int prev_max2;
        if (x == 0)
        {
            if (maxes[prev_index1] != 0)
            {
                prev_max1 = maxes[prev_index1];
            }
            else
            {
                prev_max1 = count(y - 1, x);
            }
            max = prev_max1 + numbers[index];
            maxes[index] = max;
        }
        else if (x == y)
        {
            if (maxes[prev_index2] != 0)
            {
                prev_max2 = maxes[prev_index2];
            }
            else
            {
                prev_max2 = count(y - 1, x - 1);
            }
            max = prev_max2 + numbers[index];
            maxes[index] = max;
        }
        else
        {
            if (maxes[prev_index1] != 0)
            {
                prev_max1 = maxes[prev_index1];
            }
            else
            {
                prev_max1 = count(y - 1, x);
            }
            if (maxes[prev_index2] != 0)
            {
                prev_max2 = maxes[prev_index2];
            }
            else
            {
                prev_max2 = count(y - 1, x - 1);
            }
            max = std::max(prev_max1, prev_max2) + numbers[index];
            maxes[index] = max;
        }
        return maxes[index];
    }
}

int main(){
    int n;
    cin >> n;
    int height = n;
    int depth = 1;
    while(n>0){
        for(int i=0; i<depth; i++){
            int number;
            cin >> number;
            numbers.push_back(number);
            if(depth == 1) maxes.push_back(numbers[0]);
            else maxes.push_back(0);
        }
        depth++;
        n--;
    }
    for(int i=0; i<height; i++){
        count(height-1,i);
    }
    int start_index = (height)*(height-1)/2;
    int end_index = start_index + height;
    auto nth = maxes.begin() + start_index;
    int max = *max_element(nth,maxes.end());
    cout << max << '\n';
    return 0;
}