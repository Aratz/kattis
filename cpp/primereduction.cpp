#include <bitset>
#include <cstdio>
#include <vector>
#include <numeric>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

vi primes;

void sieve(ll upperbound) {
    ll sieve_size = upperbound + 1;
    bitset<10000010> bs;
    bs.set();
    bs[0] = bs[1] = 0;
    for (ll i = 2; i <= sieve_size; i++) if (bs[i]) {
        for (ll j = i*i; j<= sieve_size; j += i)
            bs[j] = 0;
        primes.push_back((int) i);
    }
}

vi prime_factors(ll N) {
    vi factors;
    ll i_PF = 0, PF = primes[i_PF];
    while (PF * PF <= N) {
        while (N % PF == 0) {
            N /= PF;
            factors.push_back(PF);
        }
        PF = primes[++i_PF];
    }
    if (N!=1) factors.push_back(N);
    return factors;
}

int main() {
    sieve(100000);
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n == 4)
            break;

        int count = 1;
        vi factors = prime_factors(n);
        while (factors.size() > 1) {
            n = 0;
            for (auto& factor : factors)
                n += factor;
            factors = prime_factors(n);
            count += 1;
        }

        printf("%d %d\n", n, count);
    }
    return 0;
}
