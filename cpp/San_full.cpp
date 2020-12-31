#include <iostream>
#include <vector>
#include <map>

using namespace std;

map <long long, long long> dp;

int main(){
    #include "rev_map_huge.txt"

    long long A, B;
    cin >> A >> B;
    cout << B-A + 1 
        + (reverse_iterator<map<long long, long long>::iterator>(dp.upper_bound(B)))->second
        - reverse_iterator<map<long long, long long>::iterator>(dp.lower_bound(A))->second << "\n";
    cerr << (reverse_iterator<map<long long, long long>::iterator>(dp.upper_bound(B)))->first << " ";
    cerr << (reverse_iterator<map<long long, long long>::iterator>(dp.lower_bound(A)))->first << "\n";

    return 0;
}
