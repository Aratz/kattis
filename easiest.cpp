#include <cstdio>

int sum(int n){
    int res = 0;
    while(n){
        res += n%10;
        n /= 10;
    }
    return res;
}

int main(){
    int N;
    scanf("%d", &N);
    while(N){
        int p = 10;
        while(sum(N) != sum(N*(++p))) ;
        printf("%d\n", p);
        scanf("%d", &N);
    }
    return 0;
}
