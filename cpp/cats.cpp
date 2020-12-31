#include <cstdio>
#include <vector>
#include <utility> //pair
#include <algorithm> //sort

#define CMAX 2020

using namespace std;

typedef pair<int, pair<int, int> > iii;

int cats[CMAX];

int find(int cat){
    if (cat != cats[cat]) cats[cat] = find(cats[cat]);
    return cats[cat];
}

void uunion(int cat1, int cat2){
    cats[find(cat1)] = cats[find(cat2)];
    cats[cat1] = cats[find(cat2)];
}

bool comp(const iii& edge1, const iii& edge2){
    return edge1.first < edge2.first;
}

int main(){
    int T, M, C;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &M, &C);
        vector<iii> edges(C*(C-1)/2);

        for(int cat=0; cat<C; cat++)
            cats[cat] = cat;

        for(int k=0; k<C*(C-1)/2; k++){
            int i, j, dij;
            scanf("%d %d %d", &i, &j, &dij);
            edges[k] = make_pair(dij, make_pair(i, j));
        }

        sort(edges.begin(), edges.end(), comp);

        int tree = 0, k = 0, w = 0;
        while(tree < C-1){
            if(find(edges[k].second.first) != find(edges[k].second.second)){
                uunion(find(edges[k].second.first),find(edges[k].second.second));
                w += edges[k].first;
                tree += 1;
            }
            k += 1;
        }
        if(w + C <= M) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
