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
  string A;
  string B;
  cin >> A >> B;
  string result;
  int sum = 0;
  while(!A.empty() || !B.empty() || sum){
    if(!A.empty()){
      sum += A.back() - '0';
      A.pop_back();
    }
    if(!B.empty()){
      sum += B.back() - '0';
      B.pop_back();
    }
    result.push_back((sum%10) + '0');
    sum = sum / 10;
  }
  reverse(result.begin(),result.end());
  cout << result << '\n';
}