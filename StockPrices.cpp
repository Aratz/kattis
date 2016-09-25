#include <utility>
#include <queue>
#include <cstdio>

using namespace std;

typedef pair<int, int> ii; //<price, shares>

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int n; scanf("%d", &n);
        priority_queue<ii> buy, sell;
        int s = -1;
        char order[10]; int nb, price;
        while(n--){
            scanf("%s %d shares at %d\n", order, &nb, &price);
            if(order[0] == 'b')
                buy.push(ii(price, nb));
            else
                sell.push(ii(-price, nb));

            while(!(buy.empty() || sell.empty())){
                ii b_order = buy.top();
                ii s_order = sell.top();
                if (b_order.first < -s_order.first)
                    break;
                s = -s_order.first;
                buy.pop(); sell.pop();
                if(b_order.second < s_order.second)
                    sell.push(ii(s_order.first, s_order.second - b_order.second));
                else if(b_order.second > s_order.second)
                    buy.push(ii(b_order.first, b_order.second - s_order.second));
            }

            if(sell.empty())
                printf("- ");
            else
                printf("%d ", -sell.top().first);

            if(buy.empty())
                printf("- ");
            else
                printf("%d ", buy.top().first);

            if(s==-1)
                printf("-\n");
            else
                printf("%d\n", s);
        }

    }

    return 0;
}
