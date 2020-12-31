#include <vector>
#include <utility>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    int n;
    scanf("%d", &n);
    vector<int> x(n);
    vii pos(n);
    for(int i=0;i<n;i++){
        x[i] = i;
        pos[i] = ii(i, -1);
    }
    while(1){
        for(int i=0; i<n; i++)
            printf("%d%c", x[i]+1, (i<(n-1)?' ':'\n'));

        int i=n-1;
        for(;i>=0;i--){
            int pi = pos[i].first;
            int pj = pos[i].first + pos[i].second;
            if(pj>=0 && pj<n && x[pj]<i){
                int t = x[pi];
                x[pi] = x[pj];
                x[pj] = t;

                pos[x[pi]].first = pi;
                pos[x[pj]].first = pj;

                for(int k=n-1; k>i; k--)
                    pos[k].second *= -1;
                break;
            }
        }
        if(i<0) break;
    }
    return 0;
}
