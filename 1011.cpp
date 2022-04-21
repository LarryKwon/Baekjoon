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
//   int n;
//   int x;
//   int y;
//   scanf("%d",&n);

  
//   int count = 1;

//   while(n>0){
//     scanf("%d %d",&x,&y);
//     long long int dist = y - x;
//     long long int i = 1;
//     long long int num_of_jump = 1;
//     long long int max = 0;
    
//     while(true){
//       max = i*(i+1);
//       if(dist <= max){
//         break;
//       }
//       i++;
//     }

//     long long int min = i*(i-1);
//     // cout << i << " " << min << " " << max << '\n';
//     long long int range = max - min;
//     long long int middle = min + range/2;
    
//     if(middle < dist){
//       num_of_jump = 2*i;
//     }else{
//       num_of_jump = 2*i-1;
//     }
//     printf("%lld\n",num_of_jump);
//     --n;
//   }
// }