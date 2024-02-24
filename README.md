# GRMJacobi-paper
source codes of the varification of some parameters about Conjecture in the paper

## Source code
calculate the value:
$$f(x, y) = \{x + (q - 1)y\}^{q^{m-1} - 3}(x - y)^{(q-1)q^{m-1} - 3}$$
and assert for every $k = 0,\dots, q^m-6$ the coefficient of $x^{q^m-k-6}y^k$ is not equal to zero.

$$ 
\begin{align*} 
f(x, y) &= \{x + (q - 1)y\}^{q^{m-1} - 3}(x - y)^{(q-1)q^{m-1} - 3} \\
&= \sum_{k = 0}^{q^m - 6}\left\{ \sum_{i = 0}^k (q-1)^i(-1)^{k-i} 
{}_{q^{m-1}-3}C_{i} \cdot {}_{(q-1)q^{m-1}-3}C_{k-i}  \right\}x^{q^m-k-6}y^k
\end{align*}
$$