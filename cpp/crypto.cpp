#include <cstdio>
#include <bitset>
#include <vector>
#include <cmath>
#include <map>
#include <utility>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef map<ll, int> mi;
typedef pair<ll, int> ii;

ll _sieve_size;
bitset<10000010> bs;
vi primes;
// compact STL for Sieve, better than vector<bool>!
// ll is defined as: typedef long long ll;
// 10^7 should be enough for most cases
// compact list of primes in form of vector<int>
void sieve(ll upperbound) {
    // create list of primes in [0..upperbound]
    _sieve_size = upperbound + 1;
    // add 1 to include upperbound
    bs.set();
    // set all bits to 1
    bs[0] = bs[1] = 0;
    // except index 0 and 1
    for (ll i = 2; i <= _sieve_size; i++) if (bs[i]) {
        // cross out multiples of i starting from i * i!
        for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
        primes.push_back((int)i);
        // add this prime to the list of primes
    }
}

mi primeFactors(ll N) {
    // remember: vi is vector<int>, ll is long long
    mi factors;
    ll PF_idx = 0, PF = primes[PF_idx]; // primes has been populated by sieve
    while (PF * PF <= N && PF_idx < primes.size()) {
        // stop at sqrt(N); N can get smaller
        int exp = 0;
        while (N % PF == 0){
            N /= PF;
            exp += 1;
        }
        if(exp)
            factors[PF] = exp;
        // remove PF
        PF = primes[++PF_idx];
        // only consider primes!
    }
    if (N != 1) factors[N] = 1;
    // special case if N is a prime
    return factors;
    // if N does not fit in 32-bit integer and is a prime
}

int main(){
    ll N;
    scanf("%lld", &N);
    sieve(sqrt(N)+1);
    mi factors = primeFactors(N);
    ii max(0, 0);
    for(auto factor : factors)
        if(factor.second > max.second)
            max = factor;
    printf("%lld\n", max.first);
    return 0;
}
