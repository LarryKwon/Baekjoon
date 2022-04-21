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

vector<vector<int>> characters;

int main()
{
    cin.tie(nullptr);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    string s;
    getline(cin,s);
    int repeat;
    cin >> repeat;


    int strlen = s.size();
    characters.resize(26,vector<int>(strlen,0));
    
    // cout << s << '\n';
    cin.ignore();
    // cout << s << ' ' << repeat << '\n';
    for(int i=0; i<strlen; i++){
        int c = s[i];
        characters[c-97][i] = 1;
    }

    for(int i=0; i<26; i++){
        for(int j=1; j<strlen; j++){
            characters[i][j] += characters[i][j-1];
        }
    }

    // for(auto p: characters){
    //     for(auto q: p){
    //         cout << q << ' ';
    //     }
    //     cout << '\n';
    // }


    for(int i=0; i<repeat; i++){
        char c;
        int first;
        int last;
        cin >> c >> first >> last;
        int sum = characters[c-97][last];
        int dist = (first <= 0)? 0 : characters[c-97][first-1];
        cout << sum-dist << '\n';
    }

}