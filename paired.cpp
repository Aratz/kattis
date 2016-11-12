#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int analyse(const vector<int> &array){
    if(!array.size())
        return 0;
    map<int, queue<int>> counts;
    for(int i=0;i<array.size();i++)
        counts[array[i]].push(i);
    priority_queue<int, vector<int>, greater<int>> single_ladies;
    for(auto v : counts)
        if(v.second.size() == 1)
            single_ladies.push(v.second.front());

    if(single_ladies.empty())
        return array.size();
    else
        single_ladies.push(array.size());

    int s = -1, t = -1, sol = 0;
    while(!single_ladies.empty()){
        s = t + 1;
        t = single_ladies.top(); single_ladies.pop();
        sol = max(sol, analyse(vector<int>(array.begin() + s, array.begin() + t)));
    }
    return sol;
}
int main(){
    int N;
    scanf("%d", &N);
    vector<int> array(N);
    for(int i=0;i<N;i++)
        scanf("%d", &array[i]);

    map<int, queue<int>> counts;
    int s=0, t=0;
    int sol = 0;
    counts[array[s]].push(0);

    while(t<N){
        t += 1;
        if(counts[array[t]].size()>=2 || t == N){ //max size reached, launch analysis
            sol = max(sol, analyse(vector<int>(array.begin()+s, array.begin()+t)));
        }
        if(t==N) break;
        counts[array[t]].push(t);
        while(counts[array[t]].size() > 2){ //drop elements until we have doublons at most
            counts[array[s]].pop();
            if(!counts[array[s]].size())
                counts.erase(array[s]);
            s += 1;
        }
    }
    printf("%d\n", sol);
}
