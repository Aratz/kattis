#include <iostream>
#include <vector>
#include <cmath> //log, ceil, pow
#include <string> //to_string, stoi
#include <algorithm> //min
#include <cassert> //assert

using namespace std;

typedef vector<vector<long long>> vvi;

long long rev(long long n){
    string s = to_string(n);
    string res;
    for(auto it=s.rbegin();it!=s.rend();it++)
        res.push_back(*it);
    return stoll(res);
}

vector<long long> build(vvi digits, long long s, long long t){
    long long N = t-s+1;
    vector<long long> res;
    if(s == t)
        return digits[s];
    else{
        vector<long long> first = digits[s];
        vector<long long> last = digits[t];
        vector<long long> interior;

        if(t-s > 1)
            interior = build(digits, s+1, t-1);
        else
            interior = vector<long long>({0});

        for(long long i=0;i<first.size();i++){
            long long new_number = 0;
            new_number += first[i]*pow(10,N-1) + last[i];
            for(long long j=0;j<interior.size();j++){
                res.push_back(new_number + interior[j]*10);
            }
        }
        return res;
    }

}

vector<long long> reverse(long long n, int retenue){
    if(n==0 && retenue==10)
        return vector<long long>(1, 5);
    long long N = (long long) log10(n)+1;
    string v = to_string(n);
    vvi res(N);
    vector<long long> values;
    long long callback = retenue;

    for(long long i=0; i<ceil(N/2.); i++){
        if(i==N-i-1){//If single digit
            res[i].push_back((retenue+v[i]-'0')/2);
        }
        else if(v[i]==v[N-i-1]){
            for(long long j=0;j<=min(v[i]-'0'+retenue, 9);j++){
                if(retenue+v[i]-'0'-j<=9 && (j||i)){
                    res[i].push_back(j);
                    res[N-i-1].push_back(retenue+v[i]-'0'-j);
                }
            }
            retenue = 0;
        }
        else{// if(i || v[0]!='1'){
            for(long long j=0;j<=min(v[i]-'0'+retenue-1, 9);j++){
                if(retenue+v[i]-'0'-j-1<=9 && (j||i)){
                    res[i].push_back(j);
                    res[N-i-1].push_back(retenue+v[i]-'0'-j-1);
                }
            }
            retenue = 10;
            if(N-i-3>=0)
                v[N-i-3] = v[N-i-3]-1;
            else
                break;
        }
    }

    values = build(res, 0, res.size()-1);

    v = to_string(n);
    if(!callback && v[0]=='1' && v[N-2] > '0'){
        v[N-2] = v[N-2]-1;
        v.erase(v.begin());
        vector<long long> values2 = reverse(stoll(v), 10);
        values.insert(values.end(), values2.begin(), values2.end());
    }
    return values;
}
