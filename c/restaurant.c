#include <stdio.h>

int main(){
    char cmd[5];
    int N;

    scanf("%d\n", &N);
    while(N){
        int pile1 = 0, pile2 = 0;
        int m;
        while(N--){
            scanf("%s %d\n", cmd, &m);

            if(cmd[0] == 'D'){
                printf("DROP 2 %d\n", m);
                pile2 += m;
            }
            else{
                if(pile1 < m){
                    if(pile1){
                        printf("TAKE 1 %d\n", pile1);
                        m -= pile1;
                        pile1 = 0;
                    }
                    printf("MOVE 2->1 %d\n", pile2);
                    pile1 += pile2;
                    pile2 = 0;
                }
                printf("TAKE 1 %d\n", m);
                pile1 -= m;
            }
        }
        scanf("%d\n", &N);
        if(N) printf("\n");
    }
    return 0;
}
