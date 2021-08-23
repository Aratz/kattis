#include <iostream>
#include <utility>

using namespace std;

typedef pair<long long, long long> ll;
typedef pair<long long, ll> lll;

long long mulmod(long long a, long long b, long long mod) {
    long long res = 0;
    a = a % mod;

    if(b < 0) {
        a = -a;
        b = -b;
    }

    while(b > 0) {
        if (b % 2 == 1) {
            res += a;
            res %= mod;
        }

        a *= 2; a %= mod;

        b /= 2;
    }

    return res % mod;
}

lll xgcd(long long a, long long b) {
    long long old_r = a; long long r = b;
    long long old_s = 1; long long s = 0;
    long long old_t = 0; long long t = 1;

    while(r != 0) {
        long long quotient = old_r / r;

        long long temp_r = old_r;
        old_r = r;
        r = temp_r - quotient*r;

        long long temp_s = old_s;
        old_s = s;
        s = temp_s - quotient*s;

        long long temp_t = old_t;
        old_t = t;
        t = temp_t - quotient*t;
    }

    return make_pair(old_r, make_pair(old_s, old_t));
}

int main() {
    int T;
    cin >> T;
    while(T--) {
        long long a, n, b, m;
        cin >> a >> n >> b >> m;

        lll uv = xgcd(n, m);
        long long g = uv.first;
        if(a % g == b % g) {
            long long u = uv.second.first; long long v = uv.second.second;

            long long K = m*(n/g);

            //long long x = ((a*(v*(m/g) % K) % K) + (b*(u*(n/g) % K) % K)) % K;
            long long x = mulmod(a, mulmod(v, m/g, K), K) + mulmod(b, mulmod(u, n/g, K), K);
            x %= K;
            cout << (x + K)%K << " " << K << "\n";
        }
        else {
            cout << "no solution\n";
        }
    }
    return 0;
}
