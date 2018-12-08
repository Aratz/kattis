#include <cstdio>
#define NMAX 110

long cnx[NMAX][NMAX];
long nodes[NMAX];
long N;

bool fill(long i){
    long j;
    for(long c=1;c<5;c++){
        for(j=0;j<i;j++){
            if(cnx[i][j] && nodes[j]==c){
                j=-1;
                break;
            }
        }
        if(j==-1)
            continue;
        else{
            nodes[i] = c;
            if(i<N-1){
                bool res = fill(i+1);
                if(res)
                    return res;
                else
                    continue;
            }
            else
                return true;
        }
    }
    return false;
}

int main(){
    long a;
    char c;
    bool end=false;
    scanf("%ld",&N);
    while(true){
        for(long i=0;i<N;i++)
            nodes[i]=0;
        for(long i=0;i<N;i++){
            for(long j=0;j<N;j++){
                cnx[i][j] = 0;
            }
        }
        long a,b;
        while(true){
            if(scanf("%ld%c",&a,&c)==EOF){
                end = true;
                break;
            }
            if(c!='-'){
                break;
            }
            else
                scanf("%ld",&b);
            cnx[a-1][b-1]=1;
            cnx[b-1][a-1]=1;
        }
        fill(0);
        for(long i=0;i<N;i++){
            printf("%ld %ld\n",i+1,nodes[i]);
        }
        if(end)
            break;
        else{
            printf("\n");
            N = a;
        }
    }
    return 0;
}
