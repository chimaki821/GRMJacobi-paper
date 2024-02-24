#include <iostream>
#include <vector>

const int mod = 998244353;

struct Mint {
    long long x; 
    Mint(long long x = 0): x ((x % mod + mod) % mod) {}
    Mint operator-() const { return Mint(-x);}
    Mint& operator+=(const Mint a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    Mint& operator-=(const Mint a) {
        if ((x += mod-a.x) >= mod) x -= mod;
        return *this;
    }
    Mint& operator*=(const Mint a) { (x *= a.x) %= mod; return *this;}
    Mint operator+(const Mint a) const { return Mint(*this) += a;}
    Mint operator-(const Mint a) const { return Mint(*this) -= a;}
    Mint operator*(const Mint a) const { return Mint(*this) *= a;}
    Mint pow(long long t) const {
        if (!t) return 1;
        Mint a = pow(t>>1);
        a *= a;
        if (t & 1) a *= *this;
        return a;
    }

    bool operator==(const int a) const { return x == a;}
    bool operator==(const Mint a) const { return x == a.x;}

    // for prime mod
    Mint inv() const { return pow(mod-2);}
    Mint& operator/=(const Mint a) { return *this *= a.inv();}
    Mint operator/(const Mint a) const { return Mint(*this) /= a;}
};
std::istream& operator>>(std::istream& is, const Mint& a) { return is >> a.x;}
std::ostream& operator<<(std::ostream& os, const Mint& a) { return os << a.x;}

// combination mod prime
struct Combination {
    std::vector<Mint> fact, ifact;
    Combination(int n): fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    Mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
} comb(200005);