#include <string>
#include <iostream>

using namespace std;

int count_pairs(string s){
    string vowels("aeiouy");
    if(s.size() == 1)
        return 0;
    else{
        int count = 0;
        for(auto i=0; i<s.size()-1; i++)
            if(s[i]==s[i+1] && vowels.find(s[i])!=string::npos)
                count += 1;
        return count;
    }
}

int main(){
    int N;
    cin >> N;
    while(N){
        string s, best;
        cin >> best;
        N -= 1;
        while(N--){
            cin >> s;
            if(count_pairs(s) > count_pairs(best))
                best = s;
        }
        cout << best << "\n";
        cin >> N;
    }
}
