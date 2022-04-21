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



int calculate(int nth, int capacity,vector<vector<int>>& dp,const vector<int>& weights, const vector<int>& values){
  int max_value = 0;
  if(dp[nth][capacity]!=0) return dp[nth][capacity];
  else{
    if(capacity <= 0){
      return 0;
    }
    else if(nth == 1){
      if(weights[nth] > capacity) max_value = 0;
      else max_value = values[1];
    }
    else{
      int value_pt1;
      int value_pt2;
      int weight_n = weights[nth];
      if(dp[nth-1][capacity]!=0) value_pt1 = dp[nth-1][capacity];
      else{
        value_pt1 = calculate(nth-1,capacity,dp,weights,values);
        dp[nth-1][capacity] = value_pt1;
      }
      if(capacity-weight_n < 0) value_pt2 = 0;
      else{ 
        if(dp[nth-1][capacity-weight_n]!=0) value_pt2 = dp[nth-1][capacity-weight_n] + values[nth];
        else{
          dp[nth-1][capacity-weight_n] = calculate(nth-1,capacity-weight_n,dp,weights,values);
          value_pt2 = dp[nth-1][capacity-weight_n] + values[nth];
        }
      }
      max_value = max(value_pt1, value_pt2);
    }
  }
  dp[nth][capacity] = max_value;
  // cout << "nth: " << nth <<  " capacity: " << capacity << " max_value: "<< max_value << '\n';
  return dp[nth][capacity];
}

int main(){

  int n;
  int capacity;
  cin >> n >> capacity;
  int cycle = n;
  vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
  vector<int> weights(1);
  vector<int> values(1);  
  
  while(cycle > 0){
    int weight;
    int value;
    cin >> weight >> value;
    weights.push_back(weight);
    values.push_back(value);
    --cycle;
  }

  // for(auto p: weights){
  //   cout << p << " ";
  // }
  // cout << '\n';

  // for(auto p: values){
  //   cout << p << " ";
  // }
  // cout << '\n';

  int result = calculate(n,capacity,dp,weights,values);
  cout << result << '\n';

}