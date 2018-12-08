#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#define SMAX 40

using namespace std;

int main(){
    vector<string>::iterator i;
    string str;

    vector<string> species;
    map<string,long> count;
    long size=0;

    getline(cin,str);

    while(!str.empty()){
        if(!count[str])
            species.push_back(str);
        count[str]+=1;
        size++;
        getline(cin,str);
    }
    sort(species.begin(),species.end());
    for(i=species.begin();i!=species.end();i++){
        cout << *i << setprecision(4) << fixed << ' ' << count[*i]*100./size << '\n';
    }

    return 0;
}
