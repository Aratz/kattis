#include <cstdio>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    while(N && M){
        vii calls;
        while(N--){
            int s, d;
            scanf("%*d %*d %d %d", &s, &d);
            calls.push_back(ii(s, d));
        }

        while(M--){
            int res=0;
            int s,d;
            scanf("%d %d", &s, &d);
            for(auto call : calls)
                if(!(call.first + call.second <= s || call.first >= s+d))
                    res += 1;
            printf("%d\n", res);
        }
        scanf("%d %d", &N, &M);
    }
    return 0;
}
