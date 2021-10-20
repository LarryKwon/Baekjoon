#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<vector>
#include<cmath>
#include<list>
#include<map>
#include<set>
#include<numeric>

using namespace std;

static vector<int> primes;

bool is_prime(int m){
  if(m == 1) return false;
  for(int i = 0; i<primes.size();i++){
    if(m%primes[i] == 0){
      return false;
    }
  }
  return true;
}

int main() {

    int N, i, j;

    scanf("%d", &N);

    for (i = 2; i <= sqrt(N); i++) {
        while(N%i == 0) {
            printf("%d\n", i);
            N /= i;
        }
    }

    if (N != 1) printf("%d\n", N);

    return 0;
}
