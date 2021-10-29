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



int calculate(vector<int>& points,vector<int>& sums,int number){
  if(number == 0){
    return sums[0];
  }
  else if(number == 1){
    return sums[1];
  }else if(number == 2){
    return sums[2];
  }else{
    int fn_2;
    int fn_1;
    if(sums[number-2]!=0){
      fn_2 = sums[number-2] + points[number];
    }else{
      fn_2 = calculate(points,sums,number-2) + points[number];
    }

    if(sums[number-3]!=0){
      fn_1 = points[number] + points[number-1] + sums[number-3];
    }else{
      fn_1 = points[number] + points[number-1] + calculate(points,sums,number-3);
    }
    sums[number] = max(fn_1, fn_2);
    return sums[number];
  }
}

int main(){
  int cycle;
  cin >> cycle;
  int number = cycle;
  vector<int> points(301);
  int i = 1;
  while(cycle > 0){
    int point;
    cin >> point;
    points[i] = point;
    --cycle;
    ++i;
  }
  vector<int> sums(301);
  sums[1]=points[1];
  sums[2]=points[1]+points[2];
  int result = calculate(points,sums,number);
  cout << result << '\n';
}