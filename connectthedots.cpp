#include <vector>
#include <string>
#include <iostream>
#include <utility>
#include <algorithm>
#define PMAX 70

using namespace std;

typedef pair<int, int> ii;
typedef vector<string> vs;
typedef vector<ii> vii;

int main(){
    while(!cin.eof()){
        vs map;
        int mp = 0;
        vii points(PMAX);

        int i = 0;
        while(1){
            string s;
            getline(cin, s);
            if(s.empty()) break;
            map.push_back(s);
            for(int j=0;j<s.size();j++){
                if(s[j]>='0' && s[j] <='9'){
                    points[s[j]-'0'] = ii(i, j);
                    mp = max(mp, s[j]-'0');
                }
                else if(s[j]>='a' && s[j] <= 'z'){
                    points[s[j]-'a'+10] = ii(i, j);
                    mp = max(mp, s[j]-'a'+10);
                }
                else if(s[j]>='A' && s[j] <= 'Z'){
                    points[s[j]-'A'+36] = ii(i, j);
                    mp = max(mp, s[j]-'A'+36);
                }
            }
            i += 1;
        }

        int r = i;

        for(int k = 0;k<mp;k++){
            if(points[k].first == points[k+1].first){
                for(int x=min(points[k].second, points[k+1].second)+1;
                        x<max(points[k].second, points[k+1].second);
                        x++){
                    if(map[points[k].first][x] == '.')
                        map[points[k].first][x] = '-';
                    else if(map[points[k].first][x] == '|')
                        map[points[k].first][x] = '+';
                }
            }
            else if(points[k].second == points[k+1].second){
                for(int x=min(points[k].first, points[k+1].first)+1;
                        x<max(points[k].first, points[k+1].first);
                        x++){
                    if(map[x][points[k].second] == '.')
                        map[x][points[k].second] = '|';
                    else if(map[x][points[k].second] == '-')
                        map[x][points[k].second] = '+';
                }
            }
        }
        for(int k = 0; k<r;k++)
            cout << map[k] << "\n";
        if(!cin.eof())
            cout << "\n";
    }
    return 0;
}
