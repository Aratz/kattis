#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

#define NMAX 1010
#define KMAX 1010

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef map<int, ii> miii;

int find_root(int origin, vi &nodes){
    if(nodes[origin] != origin)
        nodes[origin] = find_root(nodes[origin], nodes);
    return nodes[origin];
}

int dp[NMAX][KMAX];
miii cycles;
vi roots;

int fill_dp(int n, int size){
    if(dp[n][size] != -1)
        return dp[n][size];

    if(n == 0){
        if(size - cycles[roots[n]].first >= 0)
            dp[n][size] = cycles[roots[n]].second;
        else
            dp[n][size] = 0;
        return dp[n][size];
    }
    else{
        fill_dp(n-1, size);
        if(size - cycles[roots[n]].first >= 0)
            fill_dp(n-1, size - cycles[roots[n]].first);
        else
            return dp[n-1][size];

        return dp[n][size] = max(dp[n-1][size],
                dp[n-1][size - cycles[roots[n]].first] + cycles[roots[n]].second);
    }

}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    vi nodes(n);
    vi mark(n, -1);

    for(int i=0; i<n; i++)
        for(int j=0; j<=k; j++)
            dp[i][j] = -1;

    for(int i=0; i<n; i++){
        scanf("%d", &nodes[i]);
        nodes[i] -= 1;
    }

    for(int i=0; i<n; i++){
        int j = i;
        while(mark[j] == -1){
            mark[j] = i;
            j = nodes[j];
        }
        if(mark[j] == i){ //Unvisited cycle detected
            int k = j;
            int cycle_size = 1;
            while(nodes[j] != k){
                int jt = j; //Turn cycle into a tree for later union find
                j = nodes[j];
                nodes[jt] = k;
                cycle_size += 1;
            }
            cycles[k] = ii(cycle_size, 0);
        }
    }

    for(int i=0; i<n; i++){
        int root = find_root(i, nodes);
        if(root == i)
            roots.push_back(root);
        cycles[root].second += 1;
    }

    printf("%d\n", min(k, fill_dp(roots.size()-1, k)));
    return 0;
}
