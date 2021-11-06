#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAX 10

using namespace std;

int main(){
    char s[MAX];
    scanf("%s",s);
    if(next_permutation(s,s+strlen(s))){
        printf("%s\n",s);
    }
    else{
        printf("0\n");
    }
    return 0;
}
