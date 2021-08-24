#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> h(N);

    for(int n=0; n<N; n++) {
        int hn;
        cin >> hn;
        h[n] = hn;
    }

    stack<int> left;

    int best_bungee = 0;

    for(int n=0; n<N-1; n++) {
        if(h[n] >= h[n+1]) {
            left.push(n);
        }
        else if(!left.empty() && h[n] < h[n+1]) {
            int right = n+1;
            int best_left = left.top();
            left.pop();
            while(!left.empty() && h[left.top()] < h[right]) {
                best_left = left.top();
                left.pop();
            }
            left.push(best_left);
            int low = h[best_left];
            for(int i=best_left + 1; i<right; i++) {
                low = min(low, h[i]);
            }
            best_bungee = max(best_bungee, min(h[right], h[best_left]) - low);
        }
    }

    cout << best_bungee << "\n";

    return 0;
}
