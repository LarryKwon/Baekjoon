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

vector<pair<int,int>> items;
vector<vector<int>> backpack;

void print(vector<vector<int>>& dp){
  for(auto p: dp){
    for(auto q: p){
      cout << q << ' ';
    }
    cout << '\n';
  }
}

int calculate(int nth, int capacity){
    if(capacity <= 0){
      return 0;
    }
    else if(backpack[nth][capacity]!=0) return backpack[nth][capacity];
    else{
        if(nth == 1){
            int weight = items[nth].first;
            if(weight <= capacity){
                backpack[nth][capacity] = items[nth].second;
                return backpack[nth][capacity];
            }
            else return 0;
        }
        
        int weight = items[nth].first;
        int candidate1;
        if(capacity-weight<0) {
            candidate1 = 0;
        }else{
            if(backpack[nth-1][capacity-weight] != 0){
                candidate1 = backpack[nth-1][capacity-weight] + items[nth].second;
            }else{
                int prev_value = calculate(nth-1,capacity-weight);
                backpack[nth-1][capacity-weight] = prev_value;
                candidate1 = prev_value + items[nth].second;
            }
        }
        
        int candidate2;
        if(backpack[nth-1][capacity] != 0){
            candidate2 = backpack[nth-1][capacity];
        }else{
            candidate2 = calculate(nth-1, capacity);
            backpack[nth-1][capacity] = candidate2;
        }
        int max_value = max(candidate1, candidate2);
        //print(backpack);
        backpack[nth][capacity] = max_value;
        return backpack[nth][capacity];
    } 
}

int main(){
  int n;
  int weight_limit;
  cin >> n >> weight_limit;
  items.resize(n);
  items.push_back(pair<int,int>(0,0));
  for(int i=1; i<=n; i++){
    int weight;
    int value;
    cin >> weight >> value;
    items[i] = pair<int,int>(weight,value);
  }
  
  backpack.resize(n+1,vector<int>(weight_limit+1));

  cout << calculate(n,weight_limit) << '\n';

//   print(backpack);
  
}