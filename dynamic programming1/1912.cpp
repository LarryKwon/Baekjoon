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



int main(){
  int n;
  cin >> n;
  vector<int> numbers;
  numbers.resize(n);
  vector<int> maxes;
  maxes.resize(n);

  for(int i=0; i<n; i++){
    int number;
    cin >> number;
    numbers[i] = number;
  }

  maxes[0] = numbers[0];

  for(int i=1; i<n; i++){
    int max_sum = max(maxes[i-1]+numbers[i], numbers[i]);
    maxes[i] = max_sum;
  }
  
  int max_sum = *max_element(maxes.begin(),maxes.end());

  // for(auto p: maxes){
  //   cout << p << ' ';
  // }
  // cout << '\n';
  cout << max_sum << '\n';
  
}