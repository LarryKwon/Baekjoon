#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<numeric>

using namespace std;

int main(){
  string line;
  getline(cin,line);
  istringstream ss{line};
  string num1;
  string num2;

  ss>> num1;
  ss >> num2;
  reverse(num1.begin(),num1.end());
  reverse(num2.begin(),num2.end());

  int num_1 = stoi(num1);
  int num_2 = stoi(num2);

  int result = (num_1 > num_2)? num_1:num_2;
  cout << result;
  
}