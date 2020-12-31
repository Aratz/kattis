#include <cstdio>
#include <map>
#include <utility>
#define NMAX 110
#define MMAX 50
#define SMAX 310

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int n;
int p[MMAX][2];

map<iii, int> DP;

int fill(int s1, int s2, int m){
    if (s1 == 0 && s2 == 0)
        return 0;
    if (m < 0)
        return -1;
    if(DP.find(iii(ii(s1, s2), m)) == DP.end()) {
        int min = s1 + s2 + 1;

        for (int i=0; s1 - i*p[m][0] >= 0 && s2 - i*p[m][1] >= 0; i++) {
            int res = fill(s1 - i*p[m][0], s2 - i*p[m][1], m - 1);
            if(res != -1 && res + i < min)
                min = res + i;
        }

        if(min==s1 + s2 + 1)
            DP[iii(ii(s1, s2), m)]=-1;
        else
            DP[iii(ii(s1, s2), m)]=min;
    }
    return DP[iii(ii(s1, s2), m)];
}

int main(){
    int S;
    int M;
    scanf("%d",&n);
    while(n--){
        DP.clear();
        scanf("%d %d",&M,&S);
        for(int i=0;i<M;i++){
            scanf("%d %d",p[i],p[i]+1);
        }

        int min = 2*S;
        for(int s1=0;s1<=S;s1++){
            for(int s2=0;s2<=S;s2++){
                if(s1*s1+s2*s2 == S*S){
                    int res = fill(s1, s2, M-1);
                    if(res != -1 && res < min)
                        min = res;
                }
            }
        }
        if(min==2*S)
            printf("not possible\n");
        else
            printf("%d\n",min);

        if(n){
            scanf("\n");
        }
    }
    return 0;
}
