#include <cstdio>

int main(){
    int h, m;
    scanf("%d %d", &h, &m);
    printf("%d %d\n", (h-(m<45?1:0)+24)%24, (m-45+60)%60);
    return 0;
}
