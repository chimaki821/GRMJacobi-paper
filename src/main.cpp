#include <assert.h>
#include <cmath>
#include "combination.hpp"

const int MAX_N = 200000;
const int MAX_ITERATE = 1e9;

// O(k)
Mint coeff(int q, int m, int n, int k) {
    Mint ret;
    for (int i = 0; i <= k; i++) {
        if (k - i % 2 == 0) ret += Mint(q - 1).pow(i) * comb(n - 3, i) * comb((q - 1) * n - 3, k - i);
        else ret -= Mint(q - 1).pow(i) * comb(n - 3, i) * comb((q - 1) * n - 3, k - i);
    }
    return ret;
}

// O(q^{3m})
bool check(int q, int m) {
    int n = 1;
    for (int i = 0; i < m - 1; i++) n *= q;

    bool ret = true;
    for (int k = 0; k <= q * n - 6; k++) {
        if (coeff(q, m, n, k) == 0) ret = false;
    }
    return ret;
}

int main(){
    std::vector<int> qs({3, 4, 5, 7, 8, 9, 11, 13, 16, 17, 19});
    for (int q: qs) {
        for (int m = 2; m <= 20; m++) {
            if (std::pow(q, m) > MAX_N) continue;
            if (std::pow(q, 2 * m) > MAX_ITERATE) continue;
            std::cout << "(q, m) = (" << q << ", " << m << ") : ";
            if (check(q, m)) std::cout << "OK" << std::endl;
            else std::cout << "NG" << std::endl;
        }
    }
}
