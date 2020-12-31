#include<cstdio>

int main(){
    int n;
    scanf("%d", &n);
    while(n!=-1){
        int res = 0;
        int told = 0;
        while(n--){
            int s, t;
            scanf("%d %d", &s, &t);
            res += s*(t-told);
            told = t;
        }
        printf("%d miles\n", res);
        scanf("%d", &n);
    }
    return 0;
}
