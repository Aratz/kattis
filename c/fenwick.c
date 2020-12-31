#include <stdio.h>
#define NMAX 5000010

long long a[NMAX];
int N, Q;

long long query(int i){
    long long res=0;
    while(i){
        res += a[i];
        i -= (i & (-i));
    }
    return res;
}

void update(int i, long long delta){
    for(;i<=N;i+=(i & (-i)))
        a[i] += delta;
}

int main(){
    scanf("%d %d\n", &N, &Q);
    char c;
    int i;
    long long delta;
    while(Q--){
        scanf("%c %d", &c, &i);
        if(c == '+'){
            scanf("%lli\n", &delta);
            update(i+1, delta);
        }
        else{
            scanf("\n");
            printf("%lli\n", query(i));
        }
    }
    return 0;
}
