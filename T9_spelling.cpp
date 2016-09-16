#include <iostream>
#include <regex>
#include <string>
#include <map>

using namespace std;

int main(){
    map<char, string> t9;
    t9['a'] = "2,";
    t9['b'] = "22,";
    t9['c'] = "222,";
    t9['d'] = "3,";
    t9['e'] = "33,";
    t9['f'] = "333,";
    t9['g'] = "4,";
    t9['h'] = "44,";
    t9['i'] = "444,";
    t9['j'] = "5,";
    t9['k'] = "55,";
    t9['l'] = "555,";
    t9['m'] = "6,";
    t9['n'] = "66,";
    t9['o'] = "666,";
    t9['p'] = "7,";
    t9['q'] = "77,";
    t9['r'] = "777,";
    t9['s'] = "7777,";
    t9['t'] = "8,";
    t9['u'] = "88,";
    t9['v'] = "888,";
    t9['w'] = "9,";
    t9['x'] = "99,";
    t9['y'] = "999,";
    t9['z'] = "9999,";
    t9[' '] = "0,";

    regex spacing_find("([0-9]),(?=\\1)");
    regex separator(",");
    string spacing_replace("$1 ");

    int n;
    cin >> n;
    cin.get();
    for(auto i=1;i<=n;i++){
        string s_letter, s_number;
        getline(cin, s_letter);
        for(auto it=s_letter.begin();it!=s_letter.end();it++){
            s_number.append(t9[*it]);
        }
        string res;
        res = regex_replace(
                            regex_replace(s_number, spacing_find, spacing_replace),
                            separator,
                            "");
        cout << "Case #" << i << ": " << res << "\n";
    }
    return 0;
}
