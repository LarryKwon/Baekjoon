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

void get_sums(vector<int>& sums, const vector<int>& numbers){
  // for(auto p: numbers){
  //   cout << p << " ";
  // }
  // cout << '\n';

  // for(auto p: sums){
  //   cout << p << " ";
  // }
  // cout << '\n';
  // cout << "?"<<'\n';
  if(numbers.size()==1){
    sums[0] = numbers[0];
  }else{
    vector<int> sums_copy = sums;
    for(int i=0; i<(numbers.size()-1);i++){
      int sum_0 = sums_copy[i] + numbers[i];
      int sum_1 = sums_copy[i] + numbers[i+1];
      if(sums[i]!=0){
        sums[i] = max(sums[i],sum_0);
      }else{
        sums[i] = sum_0;
      }
      if(sums[i+1]!=0){
        sums[i+1] = max(sums[i+1],sum_1);
      }else{
        sums[i+1] = sum_1;
      }
    }
  }
}

int main(){
  int cycle;
  cin >> cycle;
  vector<int> sums(cycle,0);
  cin.ignore();
  while(cycle>0){
    string line;
    getline(cin,line);
    istringstream iss{line};
    vector<int> numbers;
    int n;
    while(iss >> n){
      numbers.push_back(n);
    }
    get_sums(sums,numbers);
    --cycle;
  }
  cout << *max_element(sums.begin(),sums.end()) << '\n';
}