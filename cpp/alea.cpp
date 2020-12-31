#include <vector>
#include <cmath>
#include <cstdio>

#define MAXI 170
#define MAXT 1050

using namespace std;

typedef vector<int> vi;

int dp[MAXI][MAXT];

vi get_hand(vi seq, int id, int reject){
    int j = id + 5;
    vi hand(seq.begin() + id, seq.begin() + j);
    vi count(6, 0);
    for(int i=0; i<10;i++)
        if(reject & (1<<i))
            hand[i%5] = seq[j++];

    for(int i=0;i<5;i++){
        count[hand[i]-1] += 1;
    }
    return count;
}

vi get_seq(int A, int C, int X0){
    vi seq;
    unsigned int X = X0;
    for(int i=0;i<11*5*3;i++){
        X = A*X + C;
        seq.push_back((X/(1<<16))%6 + 1);
    }
    return seq;
}

int get_max_score(vi seq, int id, int tab){
    if(tab==(1<<11)-1) return 0;
    if(dp[id][tab]!=-1) return dp[id][tab];

    int max_score = 0;
    for(int reject=0; reject < (1<<10); reject++){
        int n_id = id + 5;
        for(int i=0; i<10;i++)
            if(reject & (1<<i))
                n_id += 1;
        int av = 0;
        vi hand = get_hand(seq, id, reject);
        for(int choice=0; choice<11;choice++){
            if(tab & (1<<choice)) continue;
            int local_score = 0;
            if(choice<6){
                if(hand[choice]>0)
                    local_score = hand[choice]*(choice+1);
            }
            else if(choice == 6){
                if(hand[1] && hand[2] && hand[3] && hand[4] && (hand[0] || hand[5]))
                    local_score = 30;
            }
            else if(choice == 7){
                int brelan = 0, pair = 0, tmp_score = 0;
                for(int i=0; i<5;i++){
                    if(hand[i]==3){
                        brelan = 1;
                        tmp_score += 3*(i+1);
                    }
                    else if(hand[i]==2){
                        pair = 1;
                        tmp_score += 2*(i+1);
                    }
                }
                if(brelan && pair)
                    local_score = tmp_score;
            }
            else if(choice==8){
                int carre = 0, tmp_score = 0;
                for(int i =0; i<5; i++){
                    if(hand[i] == 4){
                        carre = 1;
                        tmp_score += 4*(i+1);
                    }
                    else if(hand[i] == 1){
                        tmp_score += (i+1);
                    }
                }
                if(carre)
                    local_score = tmp_score;
            }
            else if(choice == 9){
                for(int i=0;i<5;i++){
                    if(hand[i]==5)
                        local_score = 50;
                }
            }
            else{
                for(int i=0;i<5;i++)
                    local_score += (i+1)*hand[i];
            }
            if(local_score==0) continue;
            max_score = max(max_score, local_score + get_max_score(seq, n_id, tab|(1<<choice)));
            av = 1;
        }
        if(!av){
            for(int choice=0; choice<11;choice++){
                if(tab & (1<<choice)) continue;
                max_score = max(max_score, get_max_score(seq, n_id, tab|(1<<choice)));
            }

        }
    }
    dp[id][tab] = max_score;
    //printf("%d %d: %d\n", id, tab, max_score);
    return max_score;
}

int main(){
    int A, C, X0;
    scanf("%d %d %d", &A, &C, &X0);
    while(A){
        for(int i=0; i<MAXI;i++)
            for(int j=0;j<MAXT;j++)
                dp[i][j]=-1;
        printf("%d\n", get_max_score(get_seq(A, C, X0), 0, 0));

        scanf("%d %d %d", &A, &C, &X0);
    }

    return 0;
}
