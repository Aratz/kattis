#include <cstdio>
#include <cmath>
#include <algorithm>
#define NMAX 510000

using namespace std;
long N,B;
long cities[NMAX];

bool testP(long P){
    long res = 0;
    for(long i=0;i<N;i++){
        res += ceil(cities[i]*1./P);
    }
    return res<=B;
}

int main(){
    while(true){
        long Pmin=1,Pmax=1,Pmid;
        scanf("%ld %ld",&N,&B);
        if(N==-1)
            break;
        for(long i=0;i<N;i++){
            scanf("%ld",cities+i);
            Pmax=max(Pmax,cities[i]);
        }
        while(Pmin<Pmax){
            Pmid = (Pmin+Pmax)/2;
            if(testP(Pmid))
                Pmax = Pmid;
            else
                Pmin = Pmid+1;
        }
        printf("%ld\n",Pmin);
    }
}
