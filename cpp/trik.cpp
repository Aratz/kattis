#include <string>
#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    int pos = 1;
    for(auto c : s){
        if(c=='A'){
            if(pos == 1) pos = 2;
            else if(pos == 2) pos = 1;
        }
        else if(c=='B'){
            if(pos == 2) pos = 3;
            else if(pos == 3) pos = 2;
        }
        else{
            if(pos == 1) pos = 3;
            else if(pos == 3) pos = 1;
        }
    }
    cout << pos << "\n";
    return 0;
}
