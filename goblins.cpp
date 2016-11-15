#include <vector>
#include <utility>
#include <cstdio>
#include <iostream>

#define XMAX 10000
#define RMAX 100

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vvii> vvvii;

bool check_dist(const ii &a, const ii &b, int r){
    return (a.first-b.first)*(a.first-b.first)
        + (a.second-b.second)*(a.second-b.second) <= r*r;
}

int main(){
    int n = XMAX/RMAX + 2;
    vvvii coarse_map(n);
    for(int i=0; i<n; i++)
        coarse_map[i] = vvii(n);

    vii moves;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            moves.push_back(ii(i, j));

    int g;
    scanf("%d", &g);
    for(int i=0;i<g;i++){
        int x,y;
        scanf("%d %d", &x, &y);
        coarse_map[x/RMAX][y/RMAX].push_back(ii(x,y));
    }

    int m;
    scanf("%d", &m);
    while(m--){
        int x, y, r;
        scanf("%d %d %d", &x, &y, &r);
        for(ii move: moves){
            int xt = x/RMAX+move.first;
            int yt = y/RMAX+move.second;
            if(xt < 0 || xt > n-1
                    || yt < 0 || yt > n-1)
                continue;

            vii& goblins = coarse_map[x/RMAX+move.first][y/RMAX+move.second];
            for(int i=0; i<goblins.size(); i++){
                if(check_dist(goblins[i], ii(x,y), r)){
                    g -= 1;
                    goblins.erase(goblins.begin() + (i--));
                }
            }
        }
    }
    printf("%d\n", g);
    return 0;
}
