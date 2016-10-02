#include <cstdio>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

typedef pair<int, int> di;

int main(){
    int S;
    scanf("%d", &S);
    for(int ca=1; ca<=S; ca++){
        int T, NA, NB;
        int curr_A, curr_B, max_A, max_B;
        curr_A = curr_B = max_A = max_B = 0;
        scanf("%d", &T);
        scanf("%d %d", &NA, &NB);
        priority_queue<di> departures, arrivals;

        while(NA--){
            int hd, md, ha, ma;
            scanf("%d:%d %d:%d", &hd, &md, &ha, &ma);
            departures.push(di(-(hd*60 + md), 0));
            arrivals.push(di(-(ha*60 + T + ma), 1));
        }
        while(NB--){
            int hd, md, ha, ma;
            scanf("%d:%d %d:%d", &hd, &md, &ha, &ma);
            departures.push(di(-(hd*60 + md), 1));
            arrivals.push(di(-(ha*60 + T + ma), 0));
        }

        while(!departures.empty()){
            di dep_time = departures.top();
            di arr_time = arrivals.top();
            if(-arr_time.first <= -dep_time.first){
                arrivals.pop();
                if(arr_time.second == 0)
                    curr_A -= 1;
                else
                    curr_B -= 1;
            }
            else{
                departures.pop();
                if(dep_time.second == 0) {
                    curr_A += 1;
                    max_A = max(max_A, curr_A);
                }
                else{
                    curr_B += 1;
                    max_B = max(max_B, curr_B);
                }
            }
        }
        printf("Case #%d: %d %d\n", ca, max_A, max_B);
    }
    return 0;
}
