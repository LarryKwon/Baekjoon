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

/*
pseudo code
필요한 자료
- Sij를 담을 2차원 벡터
- team원 정보를 담을 N/2짜리 1차원 벡터
- 전체 명수를 담을 N
- 각 팀에서 점수의 합을 계산할 s_ability, t_ability
- 각팀의 점수차이를 저장할 set 자료구조
*/

static set<int> ability_diff;

int cal_ability(vector<pair<int,bool> >& team, int nth, int sum, vector<vector<int> >& points, vector<int>& comb){
    if(nth == 2){
        // cout << "comb: " << comb[0] << comb[1] << " points: " << points[comb[0]][comb[1]] << '\n';
        return points[comb[0]][comb[1]];
    }else{
        for(int i=0; i<team.size(); i++){
            if(team[i].second == false){
                team[i].second = true;
                comb[nth] = team[i].first;
                sum  += cal_ability(team,nth+1, 0, points, comb);
                // cout << "sum: " << sum << '\n';
                team[i].second = false;
            }
        }
        return sum;
    }
}

void make_team(vector<bool>& teamMates, vector<vector<int> >& points, int nth, int prev){
    //종료조건
    if(nth == (teamMates.size())/2){
        vector<int> s_comb(2);
        vector<int> t_comb(2);

        // for(int i=0; i<teamMates.size(); i++){
        //     cout << teamMates[i] << " ";
        // }
        // cout << '\n';

        vector<pair<int, bool> > team_s;
        vector<pair<int, bool> > team_t;

        for(int i=0; i<teamMates.size(); i++){
            if(teamMates[i] == true){
                team_s.push_back(pair<int, bool>(i, false));
            }
            else{
                team_t.push_back(pair<int,bool>(i,false));
            }
        }
        // cout << "team_s: ";
        // for (int i = 0; i < teamMates.size() / 2; i++)
        // {
        //     cout << team_s[i].first << " ";
        // }
        // cout << "\n";

        // cout << "team_t: ";
        // for (int i = 0; i < teamMates.size() / 2; i++)
        // {
        //     cout << team_t[i].first << " ";
        // }
        // cout << "\n";

        int s_ability = cal_ability(team_s,0,0,points, s_comb);
        // cout << "s_ability: " << s_ability << '\n';

        int t_ability = cal_ability(team_t, 0,0,points, t_comb);
        // cout << "t_ability: " << t_ability << '\n';

        ability_diff.insert(abs(s_ability-t_ability));
    }
    else{
        for(int i=prev; i<teamMates.size(); i++){
            if(teamMates[i] == false){
                teamMates[i] = true;
                prev = i;
                make_team(teamMates, points, nth+1, prev+1);
                teamMates[i] = false;
            }
        }
    }
}

void print_points(vector<vector<int> >& points){
    for(int i=0 ; i<points.size(); i++){
        for(int j=0; j<points[i].size(); j++){
            cout << points[i][j] << " ";
        }
        cout << '\n';
    }
}

int main(){
    int N;
    cin >> N;
    cin.ignore();

    vector<bool> teamMates(N,false);
    vector<vector<int> > points(N);

    int y = 0;
    while(N>0){
        string line;
        getline(cin,line);
        istringstream iss(line);
        int point;
        while(iss>>point){
            points[y].push_back(point);
        }
        N--;
        y++;
    }
    //print_points(points);


    //make_team
    make_team(teamMates, points, 0, 0);
    cout << *ability_diff.begin() << '\n';

}