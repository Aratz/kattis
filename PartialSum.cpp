#include <cstdio>
#include <algorithm>
#define NMAX 1000100

using namespace std;

long T[NMAX];
bool neg[NMAX];

int main(){
    long N;
    while(true){
        scanf("%ld",&N);
        if(!N)
            break;
        for(long i=0;i<N;i++){
            scanf("%ld",T+i);
            neg[i] = false;
        }
        long sum = 0;
        long ans =N;
        for(long i=N-1;i>=0;i--){
            sum += T[i];
            if(sum<0){
                ans--;
                neg[i] = true;
            }
            else
                sum = 0;
        }
        if(sum<0){
            long i = N-1;
            while(sum<0&&i>=0){
                sum += T[i];
                if(sum<0&&!neg[i]){
                    neg[i] = true;
                    ans--;
                }
                i--;
            }
        }
        printf("%ld\n",ans);
    }
    return 0;
}
