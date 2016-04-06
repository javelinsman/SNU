#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

int least_zero_index(int d){
    for(int i=0;i<32;i++){
        if(!((d>>i)&1)) return i;
    }
    return 32;
}

int main(){
    srand(time(NULL));
    int cnt[33] = {};
    int a = rand(), b = rand();
    for(int i=0;i<1000000;i++){
        int x = rand();
        int t;
        cnt[t = least_zero_index(a*x+b)]++;
    }
    for(int i=0;i<33;i++){
        printf("%d %d\n", i, cnt[i]);
    }
    return 0;
}
