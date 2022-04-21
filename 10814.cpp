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

struct compare{
  bool operator()(const pair<int,string>& a, const pair<int,string>& b) const{
    if(a.first < b.first) return true;
    return false;
  }
};

int main(){
  int n;
  vector<pair<int,string>> members;
  cin >> n;
  cin.ignore();
  while(n>0){
    int age;
    string name;
    cin >> age >> name;
    pair<int,string>member(age,name);
    members.push_back(member);
    --n;
  }

  stable_sort(members.begin(),members.end(),compare());

  for(auto p: members){
    cout << p.first << ' ' << p.second << '\n';
  }
}