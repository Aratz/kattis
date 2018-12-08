#include<stdio.h>
#include<string.h>
#define MAX 100001
#define MOD 21092013

long resoudre(char S[MAX], char T[MAX]);

long main(){
    char S[MAX],T[MAX];
    int  N;

    int i;
    
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",S);
        scanf("%s",T);
        printf("Case %d: %d\n",i+1,resoudre(S,T));
    }
    return 0;
}

long resoudre(char S[MAX], char T[MAX]){
    long t1[] = {1,0,0,0};
    long t2[] = {0,0,0,0};
    
    int i,k=strlen(S),j=0;
    int c;
    int len=strlen(T);
    char S2[MAX];

    for(i=0;i<k;i++){
        if(S[i]!='U'){
            S2[j]=S[i];
            j++;
        }
        else if(j>0){
            j--;
            S2[j] = '\0';
        }
    }
    S2[j] = '\0';

    k=strlen(S2)-1;

    for(i=0;i<len;i++){
        if(T[i]=='L'){
            t2[0]=(t1[0]+t1[1])%MOD;
            t2[1]=0;
            t2[2]=(t1[2]+t1[0])%MOD;
            t2[3]=(t1[3]+t1[1])%MOD;
        }
        else if(T[i]=='R'){
            t2[0]=(t1[0]+t1[2])%MOD;
            t2[1]=(t1[1]+t1[0])%MOD;
            t2[2]=0;
            t2[3]=(t1[3]+t1[2])%MOD;
        }
        else{
            if(k>=0){
                if(S2[k]=='L'){
                    t2[0]=t1[0];
                    t2[1]=t1[1];
                    t2[2]=(t1[2]+1)%MOD;
                    t2[3]=t1[3];
                }
                else{
                    t2[0]=t1[0];
                    t2[1]=(t1[1]+1)%MOD;
                    t2[2]=t1[2];
                    t2[3]=t1[3];
                }
                k--;
            }
            else{
                t2[0] = t1[0];
                t2[1] = t1[1];
                t2[2] = t1[2];
                t2[3] = t1[3];
            }
        }
        t1[0]=t2[0];
        t1[1]=t2[1];
        t1[2]=t2[2];
        t1[3]=t2[3];
    }
    return (t1[0]+t1[1]+t1[2]+t1[3])%MOD;
}
