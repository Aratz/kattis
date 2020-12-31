#include <stdio.h>
#define NMAX 110
#define SMAX 210
#define contrib(n,i) ((f1[n]!=(i+'0'))+(f2[n]!=(i+'0')))

int n, q, D;
char f1[NMAX], f2[NMAX];
long long dp[NMAX][SMAX];

long long fill_dp(int n, int s){
    if(dp[n][s] != -1)
        return dp[n][s];

    long long res = 0;
    if(n==0)
        for(int i=0;i<q;i++)
            res += contrib(n,i) == s;
    else
        for(int i=0;i<q;i++)
            if(contrib(n,i) <= s)
                res += fill_dp(n-1, s-contrib(n,i));
    return dp[n][s] = res;
}

int main(){
    scanf("%d %d %d",&q, &n, &D);
    scanf("%s", f1);
    scanf("%s", f2);

    for(int i=0;i<n;i++)
        for(int j=0; j<=D; j++)
            dp[i][j] = -1;

    printf("%lld\n", fill_dp(n-1, D));
    return 0;
}
