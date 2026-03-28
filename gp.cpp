int gp(int a, int n) {
    if(n <= 0) return 0;

    int r = a;
    if (r == 1) {
        return (1LL * a * n) % mod;
    }

    int numerator = (modExp(r, n) - 1 + mod) % mod;
    int denominator = modInverse((r - 1 + mod) % mod);

    return (1LL * a * numerator % mod * denominator % mod) % mod;
}
int binpow(int x, int n) {
    int result = 1;
    x %= mod;

    while (n > 0) {
        if (n & 1)
            result = (result * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }

    return result;
}

int modInverse(int x) {
    return binpow(x, mod - 2);
}
