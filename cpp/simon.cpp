#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    scanf("%d\n", &T);
    while(T--){
        string s;
        getline(cin, s);
        if(s.substr(0,10) == "simon says" && s.size()>10)
            cout << s.substr(11) << endl;
        else
            cout << endl;
    }
    return 0;
}
