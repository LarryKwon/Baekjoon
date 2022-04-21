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

int N;

void calculate(vector<long long>& origin_counts, int n){
  if(n==N){
    return;
  }else{
    vector<long long> new_counts(10);
    new_counts[0] = origin_counts[1]%1000000000;
    new_counts[9] = origin_counts[8]%1000000000;
    for(int i=1; i<9;i++){
      new_counts[i] = (origin_counts[i-1] + origin_counts[i+1]) % 1000000000;
    }
    for(int i=0; i<origin_counts.size();i++){
      origin_counts[i] = new_counts[i];
    }
    calculate(origin_counts, n+1);
  }
}

int main(){
  cin >> N;
  vector<long long> counts = {0,1,1,1,1,1,1,1,1,1};
  calculate(counts,1);
  int result = 0;
  for(auto p:counts){
    result = (result+p)%1000000000;
  }
  cout << result << '\n';
  
}