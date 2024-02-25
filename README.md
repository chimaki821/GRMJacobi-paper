# GRMJacobi-paper
This repository serves as a supplementary resource for Conjecture 4.3 presented in https://arxiv.org/abs/2309.01119.
Let $q$ be prime power and $m$ be a integer, and suppose $q \geq 3$ and $m \geq 2$. We define $f_{q, m}(x, y) \in \mathbb{Z}[x, y]$ as following:
$$f_{q, m}(x, y) = \{x + (q - 1)y\}^{q^{m-1} - 3}(x - y)^{(q-1)q^{m-1} - 3}.$$
We conjecture that for arbitrary $k = 0,\dots, q^m-6$, the coefficient of $x^{q^m-k-6}y^k$ is not equal to zero.

## About Source code

$$\begin{aligned} 
f_{q, m}(x, y) &= \{x + (q - 1)y\}^{q^{m-1} - 3}(x - y)^{(q-1)q^{m-1} - 3} \\
&= \sum_{k = 0}^{q^m - 6}\left[ \sum_{i = 0}^k (q-1)^i(-1)^{k-i} 
\binom{q^{m-1}-3}{i} \cdot \binom{(q-1)q^{m-1}-3}{k-i}  \right] x^{q^m-k-6}y^k
\end{aligned}$$

In `src/main.cpp` , we define the function `coeff(int q, int m, int n, int k)` which returns the coefficient of $x^{q^m-k-6}y^k$ in $f_{q, m}(x, y)$. To avoid overflow and reduce calculation time, we introduce a class `Mint`, which is a integer type for modular arithmetic. The `Mint` class is defined in `src/combination.hpp`. For our calculations, we set a large prime number, `998244353`, as the modulus for the Mint class. Note that if the value is not equal to $0$ modulo `998244353`, then the original value is not equal to $0$.

## Some experimental results
We varidate the conjecture for $q$, $m$ satisfying $q^{2m} < 10^9$. The results are documented in `output.txt`.
