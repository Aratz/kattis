#include <stdio.h>
#include <string.h>
#define WMAX 550
#define YMAX 50


int D[YMAX][WMAX];
char Y[] = "welcome to code jam";
char W[WMAX];

int fillD(y,w){
    if (D[y][w] == -1){
        D[y][w] = 0;
        if(y == 18){
            int i;
            for(i=w;i<strlen(W);i++){
                if(W[i]==Y[y])
                    D[y][w]+=1;
            }
        }
        else{
            int i;
            for(i=w;i<strlen(W);i++){
                if(W[i]==Y[y]){
                    D[y][w]+= fillD(y+1,i)%10000;
                }
            }
        }
    }
    return D[y][w];
}

int main(){
    int N,i;
    char c;
    scanf("%d",&N);
    scanf("%c",&c);
    for(i=0;i<N;i++){
        int j,k;

        for(j=0;j<YMAX;j++){
            for(k=0;k<WMAX;k++){
                D[j][k] = -1;
            }
        }

        fgets(W,WMAX,stdin);
        printf("Case #%d: %.4d\n",i+1,fillD(0,0)%10000);


    }
    return 0;
}
