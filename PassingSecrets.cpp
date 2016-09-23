#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int count(string s, char c){
    int res = 0;
    for(auto i=0; i<s.size(); i++)
        res += (s[i]==c)?1:0;
    return res;
}

int main(){
    string line;
    getline(cin, line);
    int nword = count(line, ' ') + 1;
    stringstream stream(line);
    while(nword--){
        string name;
        stream >> name;
        cout << name << "\n";
    }
}
