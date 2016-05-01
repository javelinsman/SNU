#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int n = 4;

double M[4][4] = {
    { 0.0, 1.0/2.0, 1.0, 0.0 },
    { 1.0/3.0, 0.0, 0.0, 1.0/2.0 },
    { 1.0/3.0, 0.0, 0.0, 1.0/2.0 },
    { 1.0/3.0, 1.0/2.0, 0.0, 0.0 }
};

double r[4] = { 1.0/4.0, 1.0/4.0, 1.0/4.0, 1.0/4.0 }, prev_r[4];
double temp[4];

bool is_telset[4] = {true,true,true,true};
int tn = 4;

void precalc(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            M[i][j] *= 0.8;
            if(is_telset[i]) M[i][j] += 0.2 / tn;
        }
    }
}

void iterate(){
    for(int i=0;i<n;i++){
        prev_r[i] = r[i];
        temp[i] = 0;
        for(int j=0;j<n;j++){
            temp[i] += M[i][j] * r[j];
        }
    }
    for(int i=0;i<n;i++) r[i] = temp[i];
}


int main(){
    int it; scanf("%d", &it);
    precalc();
    for(int ii=0;ii<it;ii++){
        iterate();
        double err = 0;
        for(int k=0;k<n;k++){
            err += fabs(r[k] - prev_r[k]);
        }
        printf("[iter %d] r = (%.16f, %.16f, %.16f, %.16f) with err = %.7f\n",
                ii + 1, r[0], r[1], r[2], r[3], err);
    }
    return 0;
}
