#include <stdio.h>
#define NMAX 310

int main(){
    char s[NMAX];
    scanf("%s", s);
    int sol = 0;
    for(int i=0;s[i]!='\0';i++){
        if((!(i%3)) && s[i]!='P')
            sol += 1;
        else if((!((i%3)-1)) && s[i]!='E')
            sol += 1;
        else if((!((i%3)-2)) && s[i]!='R')
            sol += 1;
    }
    printf("%d\n", sol);
    return 0;
}
