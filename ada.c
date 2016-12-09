#include <stdio.h>
#define NMAX 12

int main(){
    int n;
    int ply[NMAX][NMAX];
    scanf("%d", &n);
    for(int i=0;i<n;i++)
        scanf("%d", &ply[0][i]);

    int rk = 1;
    for(int i=1; i<n; i++){
        for(int j=0; j<n-i;j++){
            ply[i][j] = ply[i-1][j+1] - ply[i-1][j];
            if(j && ply[i][j]!=ply[i][j-1] && rk==i) rk += 1;
        }
        if(rk == i) break;
    }

    ply[rk][n-rk] = ply[rk][n-rk-1];
    for(int i=rk-1;i>=0;i--){
        ply[i][n-i] = ply[i][n-i-1] + ply[i+1][n-i-1];
    }

    printf("%d %d\n", rk, ply[0][n]);
    return 0;
}
