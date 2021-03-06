#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <map>
#include <utility>

#define DMAX 10000010

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

int reach(int t, const vi & edge){
    /**
     * Time at which node `edge[1]` will be reached.
     */
    int u = edge[0];
    int v = edge[1];
    int t_0 = edge[2];
    int P = edge[3];
    int d = edge[4];

    if (t < t_0)
        return t_0 + d;
    else if (P)
        return t_0 + ((int) ceil(1.0 * (t - t_0) / P))*P + d;
    else
        return -1;
}

int main(){
    while(true){
        int N, M, Q, s;
        scanf("%d %d %d %d", &N, &M, &Q, &s);

        if (!N)
            break;

        map<int, vvi> graph;
        vi dist(N, DMAX);
        priority_queue<ii> pq;

        while(M--){
            int u, v, t_0, P, d;
            scanf("%d %d %d %d %d", &u, &v, &t_0, &P, &d);
            vi edge {u, v, t_0, P, d};
            graph[u].push_back(edge);
        }

        dist[s] = 0;

        int current_node = s;
        while(true){
            for(auto edge:graph[current_node]){
                int d = reach(dist[edge[0]], edge);
                if (d == -1)
                    continue;
                if (d < dist[edge[1]]){
                    dist[edge[1]] = d;
                    pq.push(ii(dist[edge[0]] - d, edge[1]));
                }
            }

            if(pq.empty())
                break;

            current_node = pq.top().second; pq.pop();
        }

        while(Q--){
            int q;
            scanf("%d", &q);
            if (dist[q] < DMAX)
                printf("%d\n", dist[q]);
            else
                printf("Impossible\n");
        }

        printf("\n");
    }

    return 0;
}
