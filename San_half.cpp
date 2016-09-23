#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "rev_numbers_sort.txt"
#include "San.cpp"

int main(){
    map<long long, long long> dp;
    dp[1] = 1;
    for(auto i: rev_numbers){
        dp[i] = 1;
        vector<long long> gen = reverse(i, 0);
        for(auto j: gen){
            if(dp.find(j)!=dp.end()){
                dp[i] += dp[j];
            }
            else{
                dp[i] += 1;
            }
        }

    }
    long long prev = 0;
    cout << "dp[" << 0 << "]=" << 0 << ";\n";
    for(auto it = dp.begin(); it!=dp.end(); it++){
        if (it->first == 1)
            continue;

        cout << "dp[" << it->first << "]=" << it->second + prev -1 << ";\n";
        prev += it->second-1;
    }
    return 0;
}
