#include <iostream>
#include <string>
#define SMAX 10010

using namespace std;

int compute_string(int val, string s){
    for(auto c : s){
        if(c=='L')
            val = 2*val;
        else if(c=='R')
            val = 2*val + 1;
    }
    return val;
}

int compute_star(int val, string s){
    int first_star = s.find('*');
    if(first_star == string::npos)
        return compute_string(val, s);
    else{
        val = compute_string(val, s.substr(0, first_star));
        int l = compute_star(2*val, s.substr(first_star+1));
        int r = compute_star(2*val + 1, s.substr(first_star+1));
        int p = compute_star(val, s.substr(first_star+1));
        return l + r + p;
    }
}

int main(){
    string s;
    cin >> s;
    cout << compute_star(1, s) << "\n";
    return 0;
}
