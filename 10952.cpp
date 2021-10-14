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
  int a;
  int b;
  while(true){
    cin >> a >> b;
    if(!cin){
      cin.clear(ios_base::goodbit);
      cin.ignore();
    }
    if(a!= 0 && b!= 0){
      cout << a+b << '\n';
    }
    else{
      return 0;
    }
  }
}