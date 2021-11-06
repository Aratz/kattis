#include <cstdio>

int main(){
    int ag1,bg1,ag2,bg2;
    int ae1,be1,ae2,be2;

    scanf("%d %d %d %d",&ag1,&bg1,&ag2,&bg2);
    scanf("%d %d %d %d",&ae1,&be1,&ae2,&be2);

    float g = (ag1+bg1+ag2+bg2)/2.;
    float e = (ae1+be1+ae2+be2)/2.;

    if(g>e){
        printf("Gunnar\n");
    }
    else if(g<e){
        printf("Emma\n");
    }
    else{
        printf("Tie\n");
    }

    return 0;
}
