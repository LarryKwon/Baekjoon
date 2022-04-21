// #include<iostream>
// #include<sstream>
// #include<fstream>
// #include<string>
// #include<algorithm>
// #include<cmath>
// #include<stdexcept>
// #include<memory>
// #include<vector>
// #include<list>
// #include<map>
// #include<set>
// #include<numeric>

// using namespace std;



// int main(){
//   vector<int> sums(6);
//   vector<int> prev(3);

//   int cycle;
//   cin >> cycle;
//   cin.ignore();
//   while(cycle>0){
//     string line;
//     getline(cin,line);
//     istringstream iss{line};

//     vector<int> next(3);
//     int first;
//     int second;
//     int third;
//     iss >> first >> second >> third;
//     next[0] = first;
//     next[1] = second;
//     next[2] = third;

//     sums[0] = prev[0] + second;
//     sums[1] = prev[0] + third;
//     sums[2] = prev[1] + first;
//     sums[3] = prev[1] + third;
//     sums[4] = prev[2] + first;
//     sums[5] = prev[2] + second;

//     prev[0] = min(sums[2],sums[4]);
//     prev[1] = min(sums[0],sums[5]);
//     prev[2] = min(sums[1],sums[3]);
//     --cycle;
//   }

//   cout << *min_element(prev.begin(),prev.end()) << '\n';
// }