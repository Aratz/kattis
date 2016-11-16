#include <vector>
#include <utility>
#include <cstdio>
#include <iostream>
#include <map>

#define XMAX 10000
#define RMAX 100

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef map<ii, int> mii;
typedef vector<mii> vmii;
typedef vector<vmii> vvmii;

bool check_dist(const ii &a, const ii &b, int r){
    return (a.first-b.first)*(a.first-b.first)
        + (a.second-b.second)*(a.second-b.second) <= r*r;
}

int main(){
    int n = XMAX/RMAX + 2;
    vvmii coarse_map(n);
    for(int i=0; i<n; i++)
        coarse_map[i] = vmii(n);

    vii moves;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            moves.push_back(ii(i, j));

    int g;
    scanf("%d", &g);
    for(int i=0;i<g;i++){
        int x,y;
        scanf("%d %d", &x, &y);
        auto& grain = coarse_map[x/RMAX][y/RMAX];
        if(grain.find(ii(x,y)) != grain.end())
            grain[ii(x,y)] += 1;
        else
            grain[ii(x,y)] = 1;
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

            auto& goblins = coarse_map[x/RMAX+move.first][y/RMAX+move.second];
            for(auto it=goblins.begin(); it!= goblins.end();){
                if(check_dist(it->first, ii(x,y), r)){
                    g -= it->second;
                    it = goblins.erase(it);
                }
                else
                    ++it;
            }
        }
    }
    printf("%d\n", g);
    return 0;
}
