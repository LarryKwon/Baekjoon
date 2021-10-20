#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<cmath>
#include<list>
#include<map>
#include<set>
#include<numeric>

using namespace std;

static vector<int> counts(5000);

int delivery(int number){
  if(counts[number] == -1){
    return -1;
  }

  if(counts[number] != 0){
    return counts[number];
  }

  int count_5 = delivery(number-5);
  int count_3 = delivery(number-3);


  if(count_5 == -1 && count_3 == -1){
    counts[number] = -1;
    return -1;
  }

  if(count_5 != -1 && count_5 < counts[number-5]){
    counts[number-5] = count_5;
  }
  if(count_3 != -1 && count_3 < counts[number-3]){
    counts[number-3] = count_3;
  }
  int real_count = 0;

  if(count_5 == -1){
    real_count = count_3;
  }else if(count_3 == -1){
    real_count = count_5;
  }else{
    real_count = min(count_5,count_3);
  }
  counts[number] = real_count+1;
  return counts[number]; 
}

int main(){
  int n;
  cin >> n;
  //pseudo code
  counts[0] = 0;
  counts[1] = -1;
  counts[2] = -1;
  counts[3] = 1;
  counts[4] = -1;
  counts[5] = 1;

  int count = delivery(n);
  cout << count << '\n';

}