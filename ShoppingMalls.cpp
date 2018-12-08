#include <cstdio>
#include <cmath>
#define NMAX 300

using namespace std;
struct coord{
    long x,y,f;
};

long N,M;
coord places[NMAX];
double cost[NMAX][NMAX];
long pred[NMAX];
bool lock[NMAX];
double weight[NMAX];

void djik(long a,long b){
    for(long i=0;i<N;i++){
        weight[i]=cost[i][b];
        pred[i] = (cost[i][b]==-1)?i:b;
        lock[i] = false;
    }
    lock[b] = true;
    while(!lock[a]){
        long min = -1;
        for(long i=0;i<N;i++){
            if(lock[i] || weight[i]<0)
                continue;
            if(min==-1){
                min = i;
            }
            else if(weight[i]<weight[min]){
                min = i;
            }
        }
        if(min==-1){
            for(long i=0;i<N;i++){
                printf("%ld %d %lf %ld\n",i,lock[i],weight[i],pred[i]);
            }
        }
        lock[min] = true;
        for(long i=0;i<N;i++){
            if(lock[i] || cost[i][min]<0)
                continue;
            if(cost[i][min]+weight[min]<weight[i] || (weight[i]<0 && cost[i][min]!=-1.)){
                weight[i] = cost[i][min]+weight[min];
                pred[i] = min;
            }
        }
    }
    long pos = a;
    while(pos != b){
        printf("%ld ",pos);
        pos = pred[pos];
    }
    printf("%ld\n",b);
}

int main(){
    scanf("%ld %ld",&N,&M);
    while(true){
    long x,y,z;
    for(long i=0;i<N;i++){
        scanf("%ld %ld %ld",&z,&x,&y);
        places[i] = (coord) {x,y,z*5};
    }
    for(long i=0;i<N;i++){
        for(long j=0;j<N;j++){
            cost[i][j]=(i==j)?0:-1;
        }
    }
    long a,b;
    char s[100];
    while(M--){
        scanf("%ld %ld %s",&a,&b,s);
        if(s[0]=='w' || s[0]=='s'){
            cost[a][b] = sqrt(
            (places[a].x-places[b].x)*(places[a].x-places[b].x)+
            (places[a].y-places[b].y)*(places[a].y-places[b].y)+
            (places[a].f-places[b].f)*(places[a].f-places[b].f));
            cost[b][a] = cost[a][b];
        }
        else if(s[0]=='l'){
            cost[a][b] = 1.;
            cost[b][a] = 1.;
        }
        else if(s[0]=='e'){
            cost[a][b] = 1;
            cost[b][a] = 3*sqrt(
            (places[a].x-places[b].x)*(places[a].x-places[b].x)+
            (places[a].y-places[b].y)*(places[a].y-places[b].y)+
            (places[a].f-places[b].f)*(places[a].f-places[b].f));
            
        }
    }
    long Q;
    scanf("%ld",&Q);
    while(Q--){
        scanf("%ld %ld",&a,&b);
        djik(a,b);
    }
    if(scanf("%ld %ld",&N,&M)==EOF)
        break;
    else
        printf("\n");
    }
    return 0;
}
