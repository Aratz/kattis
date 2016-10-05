#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 1000000000
#define NMAX 510

using namespace std;

typedef vector<vector<int>> vvi;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vvi adj_list(n);
    int dist[n];
    int ancestor[n];

    while(m--){
        int e1, e2;
        scanf("%d %d", &e1, &e2);
        adj_list[e1].push_back(e2);
        adj_list[e2].push_back(e1);
    }

    int res = INF;

    for(int s=0; s<n; s++){
        for(int i=0; i<n; i++){
            dist[i] = -1;
            ancestor[i] = -1;
        }
        dist[s] = 0;
        ancestor[s] = s;

        queue<int> q; q.push(s);
        while(!q.empty()){
            int u = q.front(); q.pop();
            int bk = 0;
            for(auto v : adj_list[u]){
                if(ancestor[v] == -1){
                    dist[v] = dist[u] + 1; ancestor[v] = u;
                    q.push(v);
                }
                else if(v != ancestor[u]){
                    bk = 1;
                    res = min(res, dist[u] + dist[v] + 1);
                }
            }
        }
    }
    if(res==INF)
        printf("impossible\n");
    else
        printf("%d\n", res);

    return 0;
}
