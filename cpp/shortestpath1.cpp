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
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            vi edge {u, v, w};
            graph[u].push_back(edge);
        }

        dist[s] = 0;

        int current_node = s;
        while(true){
            for(auto edge:graph[current_node]){
                int d = dist[edge[0]] + edge[2];
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
