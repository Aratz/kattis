#include <cstdio>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;


vvi adj_list;

vi match, visited;

void add_edge(int A, int B){
    adj_list[A].push_back(B);

    adj_list[B].push_back(A);
}

int Aug(int left){
    if(visited[left])
        return 0;
    visited[left] = 1;
    for(auto right : adj_list[left]){
        if(match[right]==0 || Aug(match[right])){
            match[right] = left;
            return 1;
        }
    }
    return 0;
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    adj_list = vvi(3*N);

    //Add regular edges
    for(auto i=0; i<M; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        add_edge(A, N+B);
        add_edge(B, N+A);
    }

    //Determine best pair matching
    int MCBM = 0;
    match.assign(3*N, 0);
    for(int left=1; left<=N; left++){
        visited.assign(N+1, 0);
        MCBM += Aug(left);
    }

    if(MCBM != N)
        printf("Impossible\n");
    else
        for(auto i=N+1; i<=2*N; i++)
            printf("%d\n", match[i]);

    return 0;
}
