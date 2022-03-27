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


static int n;
static vector<pair<int,bool> > operations;
static vector<int> numbers;
static set<int> results;

void print_operations(vector<pair<int,bool> >& operations){
    for(int i=0; i<operations.size(); i++){
        switch(operations[i].first){
            case 0:
                cout << "plus:" << ' ' << operations[i].second << '\n';
                break;
            case 1:
                cout << "minus:" << ' ' << operations[i].second << '\n';
                break;
            case 2:
                cout << "multiply:" << ' ' << operations[i].second << '\n';
                break;
            case 3:
                cout << "divide:" << ' ' << operations[i].second << '\n';
                break;
        }
    }
}

void print_numbers(vector<int>& numbers)
{
    for(int i=0; i<numbers.size(); i++){
        cout << numbers[i] << ' ';
    }
    cout << '\n';
}

void calculate(vector<pair<int,bool> >& operations, vector<int>& numbers, int nth, int result){
    if(nth == numbers.size()){
        results.insert(result);
    }
    else{
        int prev_result = result;
        for(int i=0; i<operations.size(); i++){
            if(operations[i].second == false){
                operations[i].second = true;
                switch (operations[i].first)
                {
                case 0:
                    result += numbers[nth];
                    break;
                case 1:
                    result -= numbers[nth];
                    break;
                case 2:
                    result *= numbers[nth];
                    break;
                case 3:
                    result /= numbers[nth];
                    break;
                }
                // cout << operations[i].first << " " << numbers[nth] << '\n';
                calculate(operations,numbers,nth+1,result);
                operations[i].second = false;
                result = prev_result;
            }
        }
    }
}

int main(){

    int n;
    cin >> n;
    // 숫자들 입력
    int number;
    while(n>0){
        cin >> number;
        numbers.push_back(number);
        n--;
    }
    // print_numbers(numbers);

    for(int i=0; i<4; i++){
        int num_of_op;
        cin >> num_of_op;
        while(num_of_op > 0){
            pair<int,bool> operation(i,false);
            operations.push_back(operation);
            num_of_op --;
        }
    }
    // print_operations(operations);

    int result = numbers[0];
    calculate(operations,numbers,1,result);
    set<int>::iterator min = results.begin();
    set<int>::iterator max = min;
    while(true){
        set<int>::iterator next = max;
        if(++next == results.end()) break;
        max = next;
    }
    cout << *max << '\n';
    cout << *min << '\n';

}