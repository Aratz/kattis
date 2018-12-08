#include <cstdio>
#include <bitset>
#include <cstdlib>
#define MAX 3100

using namespace std;

int main(){
    bitset<MAX> jolly;
    long seq[MAX];
    long n;

    long i;
    long diff;
    bool ans;
    
    while(scanf("%ld",&n)!=EOF){
        jolly.reset();
        ans = true;
        for(i=0;i<n;i++)
            scanf("%ld",seq+i);
        for(i=0;i<n-1;i++){
            diff = abs(seq[i]-seq[i+1]);
            if(diff <= n-1){
                jolly.set(diff);
            }
            else{
                ans = false;
                break;
            }
        }
        if(ans && (jolly.count() != n-1))
            ans = false;
        printf("%s\n",(ans ? "Jolly" : "Not jolly"));
    }
    return 0;
}
