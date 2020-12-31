#include <iostream>
#include <string>
#include <set>

using namespace std;

int rev(int n){
    string s = to_string(n);
    string res;
    for(auto it=s.rbegin();it!=s.rend();it++)
        res.push_back(*it);
    return stoi(res);
}

int main(){
    const long long N = 1000000000;
    set<long long> visited;

    cout << "vector<int> rev_numbers {";
    visited.insert(1+rev(1));
    cout << 1+rev(1);
    for(long long i=2; i<=N; i++){
        if(i+rev(i) <= N && visited.find(i+rev(i))==visited.end()){
            visited.insert(i+rev(i));
            cout << " ," << i+rev(i);
        }
    }
    cout << "};\n";
}
