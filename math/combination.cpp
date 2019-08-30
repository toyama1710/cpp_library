#include <iostream>
#include <cstdio>
using namespace std;

//===
// nCr mod p
// p is prime
// 1 <= k <= n <= 1e7

void init_comb(long long modulus);
void init_comb(void);
long long combination(long long n, long long k);
long long pow_mod(long long n, long long m);

long long _modulus = (long long)1e9 + 7;
long long fact[10000007];
long long fact_inv[10000007];

void init_comb(long long modulus) {_modulus = modulus; }
void init_comb(void) {
    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    for (int i = 2; i <= 10000000; i++) {
        fact[i] = fact[i - 1] * i % _modulus;
        fact_inv[i] = pow_mod(fact[i], _modulus - 2);
    }
}

long long combination(long long n, long long k) {
    static long long f;

    if (f != _modulus) f = _modulus, init_comb();

    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;

    return fact[n] * (fact_inv[k] * fact_inv[n - k] % _modulus) % _modulus;
}

long long pow_mod(long long n, long long m) {
    //n ** m;
    long long ret = 1;

    while (m) {
        if (m & 1) {
            ret = ret * n % _modulus;
        }

        n = n * n % _modulus;
        m = m >> 1;
    }

    return ret;
}
//===

int main() {
    long long mod;
    long long n, r;

    printf("mod: ");
    scanf("%lld", &mod);
    init_comb(mod);

    while (printf("nCr: "), scanf("%lld %lld", &n, &r), n != -1 && r != -1) {
        printf("%lld\n", combination(n, r));
    }
    
    return 0;
}
