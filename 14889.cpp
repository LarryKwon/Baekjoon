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

static set<int> diff;

static int n;

void cal_point(vector<pair<int,bool>> team, int nth, int& point, vector<int>& comb_team,vector<vector<int>>& points,int num){
  if(nth == 2){
    int first = comb_team[0];
    int second = comb_team[1];
    point += points[first-1][second-1];
    point += points[second-1][first-1];
    return ;
  }
  else{
    for(int i=num; i<n/2;i++){
      if(team[i].second == false){
        team[i].second = true;
        comb_team[nth] = team[i].first;
        cal_point(team,nth+1,point,comb_team,points,i+1);
        team[i].second = false;
        comb_team[nth] = 0;
      }
    }
  }
}

void calculate_diff(vector<bool>& people,vector<vector<int>>& points){
  vector<pair<int,bool>> team1;
  vector<pair<int,bool>> team2;
  for(int i=1; i<=n; i++){
    if(people[i]  == true) team1.push_back(pair<int,bool>(i,false));
    else{
      team2.push_back(pair<int,bool>(i,false));
    }
  }
  // cout << "team1\n";
  // for(auto p: team1){
  //   cout << "first: " << p.first << " second: " << p.second << '\n';
  // }
  // cout << "team2\n";

  // for(auto p: team2){
  //   cout << "first: " << p.first << " second: " << p.second << '\n';
  // }

  int team1_point = 0;
  int team2_point = 0;
  
  vector<int> comb_team1(2);
  vector<int> comb_team2(2);

  cal_point(team1,0,team1_point,comb_team1,points,0);
  cal_point(team2,0,team2_point,comb_team2,points,0);
  int point_diff = abs(team1_point - team2_point);
  diff.insert(point_diff);
  return ;
}

void make_team(vector<bool>& people,int nth,vector<vector<int>>& points,int num){
  if(nth == n/2){
    // for(auto p: people){
    //   cout << p << " ";
    // }
    // cout << '\n';
    calculate_diff(people,points);
    return;
  }
  else{
    for(int i=num; i<=n; i++){
      if(people[i]==false){
        people[i] = true;
        make_team(people,nth+1,points,i+1);
        people[i] = false;
      }
    }
  }
}



int main(){

  cin >> n;
  vector<bool> people(n+1);
  vector<vector<int>> points(n);
  cin.ignore();
  int cycle = n;
  int y = 0;
  while(cycle>0){
    string line;
    getline(cin,line);
    istringstream iss{line};
    int point;
    while(iss>>point){
      points[y].push_back(point);
    }
    ++y;
    --cycle;
  }

  // for(int i=0; i<n; i++){
  //   for(int j=0; j<n; j++){
  //     cout << points[i][j] << " ";
  //   }
  //   cout << "\n";
  // }

  make_team(people,0,points,1);
  cout << *diff.begin() << '\n';
}