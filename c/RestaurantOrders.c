#include <stdio.h>
#include <string.h>
#define NMAX 110
#define SMAX 30100

int ways_mem[NMAX][SMAX];
int price[NMAX];
int n;

int ways(int type, int cost){
    if(cost < 0) return 0;
    if(type >= n) return 0;
    if(cost == 0) return 1;
    if(ways_mem[type][cost]!=-1) return ways_mem[type][cost];

    ways_mem[type][cost] = ways(type, cost - price[type])
                            + ways(type + 1, cost);
    if(ways_mem[type][cost] > 2) ways_mem[type][cost] = 2;
    return ways_mem[type][cost];
}

int main(){
    memset(ways_mem, -1, sizeof(ways_mem));
    scanf("%d", &n);
    for(int i; i<n;i++)
        scanf("%d", price + i);
    int m;
    scanf("%d", &m);
    while(m--){
        int cost;
        scanf("%d", &cost);
        int type = 0;
        int w = ways(type, cost);
        if(w==0) printf("Impossible\n");
        else if(w > 1) printf("Ambiguous\n");
        else{
            int first = 1;
            while(cost){
                if(ways(type, cost - price[type]) == 1){
                    if(!first) printf(" ");
                    else first = 0;
                    printf("%d", type + 1);
                    cost -= price[type];
                }
                else
                    type += 1;
            }
            printf("\n");
        }
    }
    return 0;
}
