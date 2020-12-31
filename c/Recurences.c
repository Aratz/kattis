#include <stdio.h>
#include <math.h>
#define NMAX 50

int N, M, Q;
long long T;
long long X[NMAX], a[NMAX];
long long A[NMAX][NMAX], At[NMAX][NMAX], res[NMAX][NMAX];

long long mod(long long a, long long b)
{
    long long r = a % b;
    return r < 0 ? r + b : r;
}

void vecmul(long long A[NMAX][NMAX], long long X[NMAX], long long R[NMAX]){
    for(int i=0;i<N+1;i++){
        R[i] = 0;
        for(int j=0;j<N+1;j++){
            R[i] = mod(R[i] + mod(A[i][j]*X[j],M),M);
        }
    }
}

void matmul(long long A[NMAX][NMAX], long long B[NMAX][NMAX], long long C[NMAX][NMAX]){
    for(int i=0;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            C[i][j] = 0;
            for(int k=0;k<N+1;k++){
                C[i][j] = mod(C[i][j] + mod(A[i][k]*B[k][j],M),M);
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    for(int i=0;i<N+1;i++){
        scanf("%lli", a+i);
    }

    for(int i=0;i<N+1;i++){
        A[0][i] = (i?0:1);
    }
    for(int i=0;i<N+1;i++){
        A[1][i] = a[i];
    }
    for(int i=2;i<N+1;i++){
        for(int j=0;j<N+1;j++){
            A[i][j] = (i==j+1?1:0);
        }
    }

    X[0] = 1;
    for(int i=0;i<N;i++){
        scanf("%lli", X+N-i);
    }

    scanf("%d", &Q);
    while(Q--){
        scanf("%lli %d", &T, &M);
        long long res[NMAX][NMAX], At[NMAX][NMAX], Att[NMAX][NMAX];
        for(int i=0;i<N+1;i++){
            for(int j=0;j<N+1;j++){
                res[i][j] = (i==j?1:0);
            }
        }
        for(int i=0;i<N+1;i++){
            for(int j=0;j<N+1;j++){
                At[i][j] = A[i][j];
            }
        }

        if(T<N){
            printf("%lli\n", mod(X[N-T],M));
        }
        else{
            //for(int i=0;i<log(T-N+1)/log(2)+1;i++){
            int imax = 0;
            while ((((long long) 1) << imax++) < T - N + 1);
            for(int i=0;i<imax+1;i++){
                if(i){
                    matmul(At, At, Att);
                    for(int i=0;i<N+1;i++){
                        for(int j=0;j<N+1;j++){
                            At[i][j] = Att[i][j];
                        }
                    }
                }
                if(T-N+1 & (((long long)1)<<i)){
                    matmul(res,At,Att);
                    for(int i=0;i<N+1;i++){
                        for(int j=0;j<N+1;j++){
                            res[i][j] = Att[i][j];
                        }
                    }

                }
            }
            long long R[NMAX];
            vecmul(res, X, R);
            printf("%lli\n", mod(R[1],M));
        }
    }
    return 0;
}
