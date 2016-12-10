#include <stdio.h>
#define RMAX 5
#define GMAX 5
#define BMAX 5
#define YMAX 5
#define SMAX 10
#define max(a,b) (b>a?b:a)

double dp[RMAX][GMAX][BMAX][YMAX][SMAX];

double fill_dp(int R, int G, int B, int Y, int S){
    if(!S) return 0.;
    if(!(R||G||B||Y)) return 1.;
    if(dp[R][G][B][Y][S] >= 0.) return dp[R][G][B][Y][S];

    double w = 0.;
    int n = 6;
    if (R) w += fill_dp(R-1, G, B, Y, S); else n -= 1;
    if (G) w += fill_dp(R, G-1, B, Y, S); else n -= 1;
    if (B) w += fill_dp(R, G, B-1, Y, S); else n -= 1;
    if (Y) w += fill_dp(R, G, B, Y-1, S); else n -= 1;

    int maxi = max(R, max(G, max(B, Y)));
    if (R == maxi) w += fill_dp(R-1, G, B, Y, S);
    else if (G == maxi) w += fill_dp(R, G-1, B, Y, S);
    else if (B == maxi) w += fill_dp(R, G, B-1, Y, S);
    else if (Y == maxi) w += fill_dp(R, G, B, Y-1, S);

    w += fill_dp(R, G, B, Y, S-1);

    w /= n;

    return dp[R][G][B][Y][S] = w;
}

int main(){
    int R, G, B, Y, S;
    scanf("%d %d %d %d %d", &R, &G, &B, &Y, &S);
    for(int r=0;r<=R;r++)
        for(int g=0;g<=G;g++)
            for(int b=0;b<=B;b++)
                for(int y=0;y<=Y;y++)
                    for(int s=0;s<=S;s++)
                        dp[r][g][b][y][s] = -1;

    printf("%.12lf\n", fill_dp(R, G, B, Y, S));
    return 0;
}
