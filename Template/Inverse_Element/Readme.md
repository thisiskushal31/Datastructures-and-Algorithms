In general, we say that if a and b satisfy the following properties:

```
x / a ≡ x * b (mod M)
```

Formally, b seems to be equivalent to 1/a (in the sense of congruence), so we call b the inverse of a, denoted b = inv(a) (and vice versa).
For a, the necessary and sufficient condition for the existence of an inverse element is that a and M are relatively prime. Of course, M is usually a prime number when we do the problem.

#### Calculation method of inverse element

##### Method 1: Fast Power Method

According to Fermat's little theorem, we have

```
inv(a) ≡ a ^ (M-2)  (mod M)
```

Obviously, we need to use fast powers to calculate this number.

##### Method 2: Linear inversion

If we want to find the inverse of each number 1,2,3...N：

```cpp
const ll N = 1e6+7, M = 998244353;
ll inv[N];
int i;
for(inv[1]=1, i=2; i<N; ++i)
    inv[i] = (M - M/i) * inv[M % i] % M
```

#### Some properties of inverse elements

The calculation of the inverse element has the following properties：

```
x1/y1 + x2/y2 ≡ x1 * y1^-1 + x2 * y2^-1 (mod M)
x1/y1/y2 ≡ x1 * y1^-1 * y2^-1 (mod M)
```
