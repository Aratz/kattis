#include <cstdio>
#include <algorithm>
#define MAX 20

using namespace std;

int main(){
    while(true){
        long f,r,lf[MAX];
        double lr[MAX*MAX];
        long tmp;
        scanf("%ld",&f);
        if(!f)
            break;
        scanf("%ld",&r);
        for(long i=0;i<f;i++)
            scanf("%ld",lf+i);
        for(long i=0;i<r;i++){
            scanf("%ld",&tmp);
            for(long j=0;j<f;j++){
                lr[i*f+j] = tmp*1./lf[j];
            }
        }
        sort(lr,lr+r*f);
        double max=0;
        for(long i=0;i<r*f-1;i++)
            max = max<lr[i+1]/lr[i]?lr[i+1]/lr[i]:max;
        printf("%.2lf\n",max);

    }
    return 0;
}
