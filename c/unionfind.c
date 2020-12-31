#include <stdio.h>
#define NMAX 1000010

int N, Q;
int nodes[NMAX];

int find(int n){
    if(nodes[n] == n) return n;
    else return nodes[n] = find(nodes[n]);
}

void uni(int a, int b){
    nodes[find(a)] = find(b);
}

int main(){
    char c;
    int a, b;
    scanf("%d %d\n", &N, &Q);

    for(int i=0;i<N;i++)
        nodes[i] = i;

    while(Q--){
        scanf("%c %d %d\n", &c, &a, &b);
        if(c == '=') uni(a, b);
        else if(find(a) == find(b)) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
