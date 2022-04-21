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
  cout << fixed;
  cout.precision(6);
  cout << M_PI*pow(n,2) << '\n' << 2*pow(n,2) << '\n';
}