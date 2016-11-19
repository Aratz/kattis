#include <utility>
#include <algorithm>
#include <cstring>
#include <cstdio>
#define NMAX 100010

using namespace std;

typedef pair<int, int> ii;

char T[NMAX];
int n;
int RA[NMAX], tRA[NMAX];
int SA[NMAX], tSA[NMAX];
int c[NMAX];

void counting_sort(int k){
    int i, sum, maxi = max(27, n);
    memset(c, 0, sizeof c);
    for(i=0;i<n;i++)
        c[i+k<n?RA[i+k]:0] += 1;
    for(i = sum = 0; i<maxi;i++){
        int t=c[i];c[i]=sum;sum+=t;
    }
    for(i=0;i<n;i++)
        tSA[c[SA[i]+k<n?RA[SA[i]+k]:0]++] = SA[i];
    for(i=0;i<n;i++)
        SA[i]=tSA[i];
}

void constructSA(){
    int i, k, r;
    for(i=0;i<n;i++) RA[i] = T[i]-'`';
    for(i=0;i<n;i++) SA[i] = i;
    for(k=1;k<n;k<<=1){
        counting_sort(k);
        counting_sort(0);
        tRA[SA[0]] = r = 0;
        for(i=1;i<n;i++)
            tRA[SA[i]] =
                (RA[SA[i]]==RA[SA[i-1]] && RA[SA[i]+k]==RA[SA[i-1]+k])?r:++r;
        for(i=0;i<n;i++)
            RA[i] = tRA[i];
        if(RA[SA[n-1]]==n-1) break;
    }
}

int main(){
    int m;
    scanf("%d\n", &m);
    scanf("%s", T);
    n = (int)strlen(T);
    T[n++]='`';
    constructSA();

    ii res(-1, -1);

    return 0;
}
