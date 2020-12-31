#include <queue>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    int servers = 0, queries = 0;
    queue<int> load;
    int t;
    while(n--){
        scanf("%d", &t);
        while(!load.empty() && load.front()<=t){
            load.pop();
            queries -= 1;
        }
        load.push(t + 1000);
        queries += 1;
        servers = max(servers, (int) ceil(1.*queries/k));
    }
    printf("%d\n", servers);
    return 0;
}
