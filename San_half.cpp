#include <iostream>
#include <vector>
#include <map>

using namespace std;

#include "San.cpp"

int main(){
    map<long long, long long> dp;
    long long add;
    long long N = 100;
    for(auto i=1;i<N;i++){
        long long new_i = i + rev(i);
        if(new_i>N)
            continue;
        if(dp.find(i)==dp.end())
            add=1;
        else{
            dp[i]+=1;
            add = dp[i];
        }

        if(dp.find(new_i)==dp.end())
            dp[new_i] = add;
        else
            dp[new_i] += add;
    }
    long long prev = 0;
    cout << "dp[" << 0 << "]=" << 0 << ";\n";
    for(auto it = dp.begin(); it!=dp.end(); it++){
        if (it->first == 1)
            continue;

        cout << "dp[" << it->first << "]=" << it->second + prev - 1 << ";\n";
        prev += it->second-1;
    }
    return 0;
}
