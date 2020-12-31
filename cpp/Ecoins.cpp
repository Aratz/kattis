#include <cstdio>
#define NMAX 110
#define MMAX 50
#define SMAX 350

using namespace std;

long n;
long m;
long S;
long p[MMAX][2];
long DP[SMAX][SMAX];

long fill(long s1, long s2){
    if(DP[s1][s2]==-2){
    long min = 2*S;
    for(long i=0;i<m;i++){
        if(p[i][0] + p[i][1] > 0 && s1-p[i][0]>=0 && s2-p[i][1]>=0){
            long res = fill(s1-p[i][0],s2-p[i][1]);
            if(res!=-1 && res+1<min){
                min = res+1;
            }
        }
    }
    if(min==2*S)
        DP[s1][s2]=-1;
    else
        DP[s1][s2]=min;
    }
    return DP[s1][s2];
}

int main(){
    scanf("%ld",&n);
    while(n--){
        scanf("%ld %ld",&m,&S);
        for(long i=0;i<m;i++){
            scanf("%ld %ld",p[i],p[i]+1);
        }
        for(long s1=0;s1<=S;s1++){
            for(long s2=0;s2<=S;s2++){
                if(s1 || s2)
                    DP[s1][s2]=-2;
                else
                    DP[s1][s2]=0;
            }
        }
        long min = 2*S;
        for(long s1=0;s1<=S;s1++){
            for(long s2=0;s2<=S;s2++){
                if(s1*s1+s2*s2 == S*S){
                    long res = fill(s1,s2);
                    if(res != -1 && res<min)
                        min = res;
                }
            }
        }
        if(min==2*S)
            printf("not possible\n");
        else
            printf("%ld\n",min);

        if(n){
            scanf("\n");

        }
    }
    return 0;
}
