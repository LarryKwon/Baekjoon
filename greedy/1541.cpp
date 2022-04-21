#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <numeric>

using namespace std;



int main()
{

    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    vector<int> numbers;

    string line;
    getline(cin,line);
    int result = 0;
    string num;
    bool isMinus=false;
    for(int i=0; i<=line.size(); i++){
        if(line[i] == '-' || line[i] == '+' || i == line.size()){
            // cout << num << '\n';
            if(isMinus){
                result -= stoi(num);
                num = "";
            }else{
                result += stoi(num);
                num = "";
            }
        }else{
            num += line[i];
        }
        if (line[i] == '-')
        {
            isMinus = true;
        }
    }
    cout << result << '\n';
}