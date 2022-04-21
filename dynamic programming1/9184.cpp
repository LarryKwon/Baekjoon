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

// peudo code

/*

static int counts [21][21][21];

counts[0][0][0] = 0;

int count(int a, int b, int c){
    if(a<=0 | b<=0 | c<=0){
        return counts[0][0][0]
    }else if(a>20 | b>20 | c>20){
        if(counts[20][20][20]!= 0){
            return counts[20][20][20]
        }else{
            counts[20][20][20] = count(20,20,20);
            return counts[20][20][20];
        }
    }else{
        int n1,n2,n3,n4;
        if(counts[a-1][b][c]!=0){
            n1 = counts[a-1][b][c];
        }else{
            counts[a-1][b][c] = count(a-1,b,c);
            n1 = counts[a-1][b][c];
        }
        if(counts[a-1][b-1][c]!=0){
            n2 = counts[a-1][b-1][c];
        }else{
            counts[a-1][b-1][c] = count(a-1,b-1,c);
            n2 = counts[a-1][b-1][c];
        }
        if(counts[a-1][b][c-1]!=0){
            n3 = counts[a-1][b][c-1];
        }else{
            counts[a-1][b][c-1] = count(a-1,b,c-1);
            n3 = counts[a-1][b][c-1];
        }

        if(counts[a-1][b-1][c-1]!=0){
            n4 = counts[a-1][b-1][c-1];
        }else{
            counts[a-1][b-1][c-1] = count(a-1,b-1,c-1);
            n4 = counts[a-1][b-1][c-1];
        }
        counts[a][b][c] = n1+n2+n3-n4;
        return counts[a][b][c];
    }
}
*/
static int counts[21][21][21];

int count(int a, int b, int c)
{
    if (a <= 0 | b <= 0 | c <= 0)
    {
        return 1;   
    }
    else if (a > 20 | b > 20 | c > 20)
    {
       return count(20,20,20);
    }
    else if(a<b && b<c){
        int n1,n2,n3;
        if(counts[a][b][c-1]!=0){
            n1 = counts[a][b][c-1];
        }else{
            counts[a][b][c-1] = count(a,b,c-1);
            n1 = counts[a][b][c-1];
        }

        if(counts[a][b-1][c-1]!=0){
            n2 = counts[a][b-1][c-1];
        }else{
            counts[a][b-1][c-1] = count(a,b,c-1);
            n2 = counts[a][b-1][c-1];
        }

        if(counts[a][b-1][c]!=0){
            n3 = counts[a][b-1][c];
        }else{
            counts[a][b-1][c] = count(a,b-1,c);
            n3 = counts[a][b-1][c];
        }
        return n1+n2-n3;
    }
    else
    {
        int n1, n2, n3, n4;
        if (counts[a - 1][b][c] != 0)
        {
            n1 = counts[a - 1][b][c];
        }
        else
        {
            counts[a - 1][b][c] = count(a - 1, b, c);
            n1 = counts[a - 1][b][c];
        }
        if (counts[a - 1][b - 1][c] != 0)
        {
            n2 = counts[a - 1][b - 1][c];
        }
        else
        {
            counts[a - 1][b - 1][c] = count(a - 1, b - 1, c);
            n2 = counts[a - 1][b - 1][c];
        }
        if (counts[a - 1][b][c - 1] != 0)
        {
            n3 = counts[a - 1][b][c - 1];
        }
        else
        {
            counts[a - 1][b][c - 1] = count(a - 1, b, c - 1);
            n3 = counts[a - 1][b][c - 1];
        }

        if (counts[a - 1][b - 1][c - 1] != 0)
        {
            n4 = counts[a - 1][b - 1][c - 1];
        }
        else
        {
            counts[a - 1][b - 1][c - 1] = count(a - 1, b - 1, c - 1);
            n4 = counts[a - 1][b - 1][c - 1];
        }
        counts[a][b][c] = n1 + n2 + n3 - n4;
        return counts[a][b][c];
    }
}

int main()
{
    counts[0][0][0] = 1;
    for(int i=0; i<21; i++){
        for(int j=0; j<21; j++){
            counts[i][j][0] = 1;
            counts[i][0][j] = 1;
            counts[0][i][j] = 1;
        }
    }
    int a,b,c;
    while(cin >> a >> b >> c){
        if(a==-1 && b==-1 && c==-1){
            break;
        }
        cout << "w("<< a << ", " << b <<", " << c <<") = " << count(a,b,c) << '\n';
    }

}