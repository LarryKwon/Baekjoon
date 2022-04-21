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
/* pseudo code 
vector<vector<int>> costs(n,vector<int>(3));
vector<vector<int>> mins(n,vector<int>(3));

min_costs(int n, int color){
    if(n==0){
        switch(color){
            case 0:
            return costs[0][0];
            case 1:
            return costs[0][1];
            case2:
            return costs[0][2];
        }
    }else{
        int prev_red;
        int prev_green;
        int prev_blue;
        if(mins[n-1][0]!=0){
            prev_red = mins[n-1][0];
        }else{
            prev_red = min_costs(n-1, 0);
        } 
        if(mins[n-1][1]!=0){
            prev_green = mins[n-1][1];
        }else{
            prev_green = min_costs(n-1,1);
        }
        if(mins[n-1][2]!=0){
            prev_blue = mins[n-1][2];
        }else{
            prev_blue = min_costs(n-1,2);
        }

        switch(color){
            case 0:
            mins[n][0] = min(prev_green,prev_blue) + costs[n][0];
            return mins[n][0];
            case 1:
            mins[n][1] = min(prev_red, prev_blue) + costs[n][1];
            return mins[n][1]
            case 2:
            mins[n][2] = min(prev_green,prev_blue) + costs[n][2];
            return mins[n][2]
        }

    }
}

*/

int min_costs(int n, int color, vector<vector<int>>& costs, vector<vector<int>>& mins)
{
    if (n == 0)
    {
        switch (color)
        {
        case 0:
            mins[0][0] = costs[0][0];
            return mins[0][0];
        case 1:
            mins[0][1] = costs[0][1];
            return mins[0][1];
        case 2:
            mins[0][2] = costs[0][2];
            return mins[0][2];
        }
    }
    else
    {
        int prev_red;
        int prev_green;
        int prev_blue;
        if (mins[n - 1][0] != 0)
        {
            prev_red = mins[n - 1][0];
        }
        else
        {
            prev_red = min_costs(n - 1, 0,costs,mins);
        }
        if (mins[n - 1][1] != 0)
        {
            prev_green = mins[n - 1][1];
        }
        else
        {
            prev_green = min_costs(n - 1, 1,costs,mins);
        }
        if (mins[n - 1][2] != 0)
        {
            prev_blue = mins[n - 1][2];
        }
        else
        {
            prev_blue = min_costs(n - 1, 2,costs,mins);
        }

        switch (color)
        {
        case 0:
            mins[n][0] = min(prev_green, prev_blue) + costs[n][0];
            return mins[n][0];
            break;

        case 1:
            mins[n][1] = min(prev_red, prev_blue) + costs[n][1];
            return mins[n][1];
            break;

        case 2 : mins[n][2] = min(prev_red, prev_green) + costs[n][2];
            return mins[n][2];
            break;
        }
    }
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> costs(n, vector<int>(3));
    vector<vector<int>> mins(n, vector<int>(3));
    for(int i=0; i<n; i++){
        int n1,n2,n3;
        cin >> n1 >> n2 >> n3;
        costs[i][0] = n1;
        costs[i][1] = n2;
        costs[i][2] = n3;
    }

    int red = min_costs(n-1,0,costs,mins);
    int green = min_costs(n-1,1,costs,mins);
    int blue = min_costs(n-1,2,costs,mins);
    cout <<  min(red,min(green,blue)) << '\n';

}