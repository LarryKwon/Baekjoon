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
//   int n = 0;
//   cin >> n;
//   cin.ignore();
//   string line;
//   while(n>0){
//     getline(cin,line);
//     istringstream ss{line};
//     int H;
//     int W;
//     int N;
//     ss >> H >> W >> N;
//     int dist = N / H + 1;
//     int height = N % H;
//     if(height == 0 ) {
//       height = H;
//       dist = N/H;
//     }

//     string dist_str = "";
//     if(dist / 10 == 0 ){
//       dist_str = "0" + to_string(dist);
//     }else{
//       dist_str = to_string(dist);
//     }
//     cout << height << dist_str<<'\n';
//     --n;
//   }
// }