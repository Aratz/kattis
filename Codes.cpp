#include <cstdio>
#include <algorithm>

#define NMAX 40
#define KMAX 20

using namespace std;

int n,k;
int matMul(int mat[NMAX][KMAX], int vec[KMAX]){
    int res=0;
    for(int i=0;i<n;i++){
        int subres=0;
        for(int j=0;j<k;j++){
            subres = (subres + mat[i][j]*vec[j])%2;
        }
        res += subres;
    }
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int mat[NMAX][KMAX];
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            for(int j=0;j<k;j++){
               scanf("%d",mat[i]+j);
            }
        }

        int vec[KMAX];
        for(int i=0;i<k;i++){
            vec[i]= (i?0:1);
        }

        int sol = matMul(mat,vec);
        for(int i=2;i<(1<<k);i++){
            for(int j=0;j<k;j++){
                vec[j] = (i & (1<<j)?1:0);
            }
            sol = min(sol,matMul(mat,vec));
        }
        printf("%d\n",sol);


    }
    return 0;
}
