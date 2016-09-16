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

map<ii, int> capacity, flow;

void add_edge(int A, int B){
    adj_list[A].push_back(B);
    flow[make_pair(A, B)] = 0;
    capacity[make_pair(A, B)] = 1;

    adj_list[B].push_back(A);
    flow[make_pair(B, A)] = 0;
    capacity[make_pair(B, A)] = 0;
}

set<ii> find_path(int s, int t, set<ii> path){
    if(s==t)
        return path;
    for(auto dest : adj_list[s]){
        auto edge = make_pair(s, dest);
        if(path.find(edge) == path.end() &&
                capacity[edge] - flow[edge] > 0){
            path.insert(edge);
            set<ii> new_path = find_path(dest, t, path);
            if(!new_path.empty())
                return new_path;
            else
                path.erase(edge);
        }
    }
    return set<ii>();
}

void match(int s, int t){
    set<ii> path = find_path(s, t, set<ii>());
    while(!path.empty()){
        //Look for smallest residual
        int min_flow = capacity[*(path.begin())] - flow[*(path.begin())];
        for(auto it=++path.begin(); it!=path.end(); it++)
            min_flow = min(min_flow, capacity[*it] - flow[*it]);

        //Apply new flow
        for(auto edge : path){
            flow[edge] += min_flow;
            flow[make_pair(edge.second, edge.first)] -= min_flow;
        }

        path = find_path(s, t, set<ii>());
    }
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

    //Add source and sink
    for(auto i=1; i<=N; i++)
        add_edge(0, i);
    for(auto i=N+1; i<=2*N; i++)
        add_edge(i, 2*N+1);

    //Determine best pair matching
    match(0, 2*N+1);

    //Count number of pairs, if != N, print impossible
    int count = 0;
    vi solution(3*N);
    for(auto item : flow){
        if(item.second == 1){
            count += item.second;
            auto edge = item.first;
            solution[edge.first] = edge.second;
        }
    }
    if(count != 3*N)
        printf("Impossible\n");
    else
        for(auto i=1; i<=N; i++)
            printf("%d\n", solution[i]-N);

    return 0;
}
