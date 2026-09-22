
## SECRET #1: **Segmented Sieve → Primes in [L, R] up to 10¹²**

```cpp
vector<int> segmented_sieve(long long L, long long R) {
    const long long SQ = sqrt(R) + 1;
    vector<bool> is_prime(SQ + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (long long i = 2; i * i <= SQ; ++i)
        if (is_prime[i])
            for (long long j = i * i; j <= SQ; j += i)
                is_prime[j] = false;

    vector<int> primes;
    for (int i = 2; i <= SQ; ++i)
        if (is_prime[i]) primes.push_back(i);

    vector<bool> block(R - L + 1, true);
    if (L == 0) block[0] = block[1] = false;
    if (L == 1) block[0] = false;

    for (int p : primes) {
        long long start = max(p * p, (L + p - 1) / p * p);
        for (long long j = start; j <= R; j += p)
            if (j >= L) block[j - L] = false;
    }

    vector<int> res;
    for (long long i = L; i <= R; ++i)
        if (block[i - L]) res.push_back(i);
    return res;
}
```

> **Use case**: `L = 1e10`, `R = L + 1e6` → **find 6-digit primes in 10¹⁰ range**  
> **Time**: `O((R-L) log log R + sqrt(R))`  
> **Memory**: `O(R-L)` → **1e6 bits = 125 KB**

---

## SECRET #2: **Linear Sieve → All Primes + SPF in O(n)**

```cpp
vector<int> linear_sieve(int n) {
    vector<int> lp(n + 1), pr;
    for (int i = 2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int p : pr) {
            if (p > lp[i] || i * p > n) break;
            lp[i * p] = p;
        }
    }
    return pr;
}
```

> `lp[i]` = smallest prime factor  
> **Use**: Factorize in `O(log n)`

---

## SECRET #3: **Mo’s Algorithm → Offline Range Queries in O(n√n)**

```cpp
struct Query { int l, r, idx; };
int BS = 300;  // block size

void mo(vector<Query>& q, vector<int>& a) {
    sort(q.begin(), q.end(), [&](Query x, Query y) {
        int bx = x.l / BS, by = y.l / BS;
        return bx == by ? x.r < y.r : bx < by;
    });

    int cl = 0, cr = -1;
    long long cur = 0;
    vector<long long> ans(q.size());

    for (auto [l, r, idx] : q) {
        while (cl > l) cur += a[--cl];
        while (cr < r) cur += a[++cr];
        while (cl < l) cur -= a[cl++];
        while (cr > r) cur -= a[cr--];
        ans[idx] = cur;
    }
}
```

> **Use case**: 1e5 queries on array → **TLE with segment tree? → Mo’s AC**

---

## SECRET #4: **Binary Lifting → LCA in O(n log n) prep, O(log n) query**

```cpp
const int LOG = 20;
vector<vector<int>> up;
vector<int> depth;

void dfs(int u, int p, vector<vector<int>>& g) {
    up[u][0] = p;
    for (int i = 1; i < LOG; ++i)
        up[u][i] = up[up[u][i-1]][i-1];
    for (int v : g[u])
        if (v != p) {
            depth[v] = depth[u] + 1;
            dfs(v, u, g);
        }
}

int lca(int u, int v) {
    if (depth[u] > depth[v]) swap(u, v);
    for (int i = LOG-1; i >= 0; --i)
        if (depth[v] - (1<<i) >= depth[u])
            v = up[v][i];
    if (u == v) return u;
    for (int i = LOG-1; i >= 0; --i)
        if (up[u][i] != up[v][i])
            u = up[u][i], v = up[v][i];
    return up[u][0];
}
```

---

## SECRET #5: **Z-Algorithm → String Matching in O(n)**

```cpp
vector<int> z_algorithm(string s) {
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; ++i) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] > r) l = i, r = i + z[i];
    }
    return z;
}
```

> **Use**: Find all occurrences of pattern in text → **O(n + m)**

---

## SECRET #6: **Fast Walsh–Hadamard Transform → Subset Sum in O(n 2^n)**

```cpp
void fwht(vector<long long>& a) {
    int n = a.size();
    for (int len = 1; len < n; len <<= 1)
        for (int i = 0; i < n; i += len << 1)
            for (int j = 0; j < len; ++j) {
                long long x = a[i + j], y = a[i + j + len];
                a[i + j] = x + y;
                a[i + j + len] = x - y;
            }
}
```

> **Use**: Count subsets with sum `k` → **O(2^n)**

---

## SECRET #7: **Meet in the Middle → 2ⁿ/² for n=40**

```cpp
long long meet_in_middle(vector<int>& a, int target) {
    int n = a.size(), n1 = n / 2;
    vector<long long> s1, s2;

    // generate all subsets
    for (int mask = 0; mask < (1 << n1); ++mask) {
        long long sum = 0;
        for (int i = 0; i < n1; ++i)
            if (mask & (1 << i)) sum += a[i];
        s1.push_back(sum);
    }
    // same for second half
    // sort s2, binary search target - s1[i]
}
```

> **Use**: `n=40` → `2²⁰ = 1e6` → **AC**

---

## SECRET #8: **Alien Trick → Min/Max with Binary Search**

```cpp
// Want: min(max(a[i] + b[j])) over i,j
// → Binary search on answer x
bool check(int x, vector<int>& a, vector<int>& b) {
    int j = b.size() - 1;
    for (int i = 0; i < a.size(); ++i) {
        while (j >= 0 && a[i] + b[j] > x) --j;
        if (j >= 0) return true;
    }
    return false;
}
```

---

## SECRET #9: **Sqrt Decomposition → O(n√n) for Range Queries**

```cpp
class SqrtDecomp {
    int BS, n;
    vector<int> block_sum;
public:
    SqrtDecomp(vector<int>& a) {
        n = a.size(); BS = sqrt(n) + 1;
        block_sum.resize(BS, 0);
        for (int i = 0; i < n; ++i)
            block_sum[i / BS] += a[i];
    }
    int query(int l, int r) {
        int sum = 0, bl = l / BS, br = r / BS;
        if (bl == br) {
            for (int i = l; i <= r; ++i) sum += a[i];
        } else {
            for (int i = l; i < (bl+1)*BS; ++i) sum += a[i];
            for (int b = bl+1; b < br; ++b) sum += block_sum[b];
            for (int i = br*BS; i <= r; ++i) sum += a[i];
        }
        return sum;
    }
};
```

---

## SECRET #10: **Your New Habit**

> **Every week, learn ONE secret.**  
> **Implement it in a problem.**  
> **Add to `secrets.cpp`**

---


---

**You’re no longer learning DSA.**  
**You’re collecting weapons.**

---

You’re not preparing for interviews.  
**You’re preparing to dominate.**