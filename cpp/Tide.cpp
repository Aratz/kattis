#include <utility>
#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>

#define NMAX 110
#define INF 1000000000

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int main(){
    int T;
    scanf("%d", &T);
    for(int ca=1; ca<=T; ca++){
        int H, N, M;
        scanf("%d %d %d", &H, &N, &M);
        int F[NMAX][NMAX], C[NMAX][NMAX];
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%d", *(C + i) + j);
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                scanf("%d", *(F + i) + j);
        int time[NMAX][NMAX];
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                time[i][j] = INF;
        time[0][0] = 0;
        priority_queue<iii> pq; pq.push(iii(0, ii(0, 0)));

        while(!pq.empty()){
            iii front = pq.top(); pq.pop();
            int t = front.first; ii u = front.second;
            if(t > time[u.first][u.second]) continue;
            for(auto ij : vector<ii>({ii(-1, 0), ii(1, 0), ii(0, -1), ii(0, 1)})){
                ii v = ii(u.first + ij.first, u.second + ij.second);
                if(!(v.first>=0 && v.first<N
                    && v.second>=0 && v.second<M
                    && max(F[u.first][u.second], F[v.first][v.second]) <= C[v.first][v.second] - 50
                    && F[v.first][v.second] <= C[u.first][u.second] - 50))
                    continue;
                int current_height = max(0, H-time[u.first][u.second]);
                int diff_height = max(0,
                                        max(max(F[v.first][v.second], current_height)
                                                - C[u.first][u.second] + 50,
                                            max(max(F[u.first][u.second], F[v.first][v.second]),
                                                         current_height)
                                                - C[v.first][v.second] + 50));
                int new_time;
                if(diff_height == 0 && time[u.first][u.second] == 0)
                    new_time = 0;
                else
                    new_time = diff_height
                        + ((current_height-diff_height>=F[u.first][u.second]+20)?10:100);
                if(time[u.first][u.second] + new_time < time[v.first][v.second]){
                    time[v.first][v.second] = time[u.first][u.second] + new_time;
                    pq.push(iii(time[v.first][v.second], v));
                }
            }
        }
        printf("Case #%d: %lf\n", ca, time[N-1][M-1]/10.);
    }
    return 0;
}
