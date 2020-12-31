#include <cstdio>

int main(){
    const int model[] = {1, 1, 2, 2, 2, 8};
    for(int i=0;i<6;i++){
        int e;
        scanf("%d", &e);
        printf("%d", model[i]-e);
        if(i<5)
            printf(" ");
    }
    printf("\n");
}
