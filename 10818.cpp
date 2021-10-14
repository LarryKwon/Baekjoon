#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>

using namespace std;

int main(){
  int n;
  int number;
  vector<int> nums;
  cin >> n;
  if(!cin){
    return 0;
  }
  for(int i = 0; i<n; i++){
    cin >> number;
    nums.push_back(number);
  }
  sort(nums.begin(),nums.end());

  cout << nums[0] << ' '<< nums[n-1];
}