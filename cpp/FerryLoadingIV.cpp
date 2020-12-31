#include <cstdio>
#include <deque>
#define MAX 100000

using namespace std;

int main(){
    long c,l,m;
    deque<long> banks[2];
    long cross, onboard, side;

    char tp[10];
    long car;

    scanf("%ld",&c);

    while(c--){
        scanf("%ld %ld",&l,&m);
        l*=100;
        while(m--){
            scanf("%ld",&car);
            scanf("%s",tp);
            
            if(tp[0] == 'l')
                banks[0].push_back(car);
            else
                banks[1].push_back(car);
        }
        cross = 0;
        onboard = 0;
        side = 0;
        
        while(!banks[0].empty() || !banks[1].empty()){
            while(!banks[side].empty() and onboard + banks[side].front() <= l){
                onboard += banks[side].front();
                banks[side].pop_front();
            }
            onboard = 0;
            side = !side;
            cross++;
        }
        printf("%ld\n",cross);
    }
    return 0;
}
