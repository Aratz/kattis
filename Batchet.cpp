#include <stdio.h>
#define NMAX 1000010
#define MMAX 10

int main(){
    int n,m;

    while(scanf("%d %d", &n, &m)!= EOF){
        int stan[NMAX];
        int stones[MMAX];
        for(int i=0;i<m;i++){
            scanf("%d", stones+i);
        }
        stan[1]=1;

        for(int i=0;i<=n;i++){
            int j;
            for(j=0;j<m;j++){
                if (i < stones[j])
                    continue;
                else if(i == stones[j] || !stan[i-stones[j]]){
                    stan[i] = 1;
                    break;
                }
            }
            if (j==m)
                stan[i] = 0;
        }
        
        if(stan[n])
            printf("Stan wins\n");
        else
            printf("Ollie wins\n");
    }
    return 0;
}
