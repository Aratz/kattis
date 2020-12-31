#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define BMAX 15

using namespace std;

long B;
long p[BMAX][2];

long d(long i, long j){
    return abs(p[i][0]-p[j][0])+abs(p[i][1]-p[j][1]);
}

long dt(long tab[BMAX]){
    long res =0;
    for(long i=0;i<B;i++){
        res += d(tab[i],tab[i+1]);
    }
    res += d(tab[B],tab[0]);
    return res;
}
int main(){
    long n;
    scanf("%ld",&n);
    while(n--){
        scanf("%ld %ld",p[0],p[0]+1);
        scanf("%ld %ld",p[0],p[0]+1);
        scanf("%ld",&B);
        for(long i=1;i<=B;i++){
            scanf("%ld %ld",p[i],p[i]+1);
        }
        long tab[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
        long sol = dt(tab);
        while(next_permutation(tab+1,tab+1+B)){
            sol = min(sol,dt(tab));
        }
        printf("%ld\n",sol);
    }
    return 0;
}
