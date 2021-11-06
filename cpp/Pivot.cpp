#include <cstdio>
#include <algorithm>
#define NMAX 100010

using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    int list[NMAX];
    int lmin[NMAX];
    int lmax[NMAX];
    for(int i=0;i<n;i++){
        scanf("%d",list+i);
    }
    lmax[0] = list[0];
    for(int i=1;i<n;i++){
        lmax[i] = max(list[i], lmax[i-1]);
    }
    lmin[n-1] = list[n-1];
    for(int i=n-2;i>=0;i--){
        lmin[i] = min(list[i], lmin[i+1]);
    }
    
    int res = 0;
    if(lmin[1] > list[0])
        res+=1;
    if(lmax[n-2] < list[n-1])
        res+=1;
    for(int i=1;i<n-1;i++){
        if(list[i]>lmax[i-1] && list[i]<lmin[i+1])
            res+=1;
    }
    printf("%d\n",res);
    return 0;
}
