Absolutely. And given that you've been away for ~3 months, I **wouldn't jump straight back into random 1800–2200 problems**. Your first objective should be to rebuild the mental map of DSA/CP so that when you encounter a problem, your brain has somewhere to search.

Also, one important distinction before the list:

> **“Pre-Master” vs “Post-Master” is not the same as “easy vs hard.”**

A Master can still get hit by a 1500 constructive problem, and some 2200 problems use very standard algorithms. The split below is about the **depth and breadth of techniques you should expect to encounter**, roughly corresponding to the Codeforces Expert → Master → GM/Red progression.


---

# The CP map

I would divide your knowledge into these major areas:

1. **Fundamentals & implementation**
2. **Complexity / problem analysis**
3. **Math & number theory**
4. **Combinatorics**
5. **Constructive algorithms**
6. **Greedy**
7. **Prefix/suffix / array techniques**
8. **Binary search / two pointers**
9. **Sorting & order-based techniques**
10. **Data structures**
11. **Trees**
12. **Graphs**
13. **Dynamic programming**
14. **Strings**
15. **Bit manipulation**
16. **Range queries / offline processing**
17. **Geometry**
18. **Game theory**
19. **Flows / matching**
20. **Advanced graph algorithms**
21. **Advanced data structures**
22. **Advanced DP**
23. **Advanced string algorithms**
24. **Randomization / probabilistic techniques**
25. **Meta-techniques / problem-solving patterns**

I'll mark things roughly as:

* 🟢 **Pre-Master:** should become reasonably familiar before/around Master
* 🔴 **Post-Master:** commonly appears as you move toward GM/Red
* ⭐ **Bridge:** technically learnable pre-Master, but becomes much more important later

---








COMBINE EVERYTHING WITH FEYNMAN TECHNIQUE

Lessons:
1. +1 When you face a obstacle/constraint, try to solve it instead of giving up. +1: If something disproves your solution, doesn''t mean you are completely wrong, you just need to tweak your approach instead of giving everything up.







# 1. Fundamentals & Implementation

### 🟢 Pre-Master

* Time complexity:
  The order of time it takes for an operation to complete, in relation with the size of the input.
* Space complexity:
  The order of extra space an operation consumes, in relation with the size of the input.
* Amortized complexity:
  Average cost of an operation over a long sequence of actions. It spreads the high cost of rare, expensive operations across many cheap ones to show true efficiency
* Big-O reasoning: 
  How an operation performs in the worst case, when data grows.
* Recursion:

* Iteration vs recursion
* Simulation:
WHEN you are simulating, simulate a generic algorithm first, to catch edge cases, then simulate using an example too, to prune out unreachable scenarios.
Example: https://leetcode.com/problems/number-of-matching-subsequences/ here for each char of s, we don't need to traverse all the words, just the ones waiting for that char
* Implementation-heavy problems
* Coordinate compression
* Custom sorting:
  We define a custom comparator: A function that tells which of the two objects is smaller.
  1. when we want to store primitive structures in a non default way.
  2. When we have a list of non-primitive structures like a struct or class object.
  Implementation method:
  1. Either pass a lambda/predefined custom comparator function in the the sort call.
  2. Only for structs/classes, you can also define operator(comparable function in Java) functions using operator overloading in the struct/class definition.
  Tricks: use the spaceship operator: <=>, if you want simple comparison, and tie(field1, field2) to define order of comparison.
  Default in cpp 20+: auto operator<=>(const Employee&) const = default; 
  bool operator<(const Product& other) const {
        // std::tie groups the variables into a temporary tuple and compares them in order
        return std::tie(this->category, this->price) < std::tie(other.category, other.price);
  }
* Comparators:
* Modular arithmetic
* Overflow handling
* Floating point basics
* Input/output optimization
* STL:

  * vector
  * array
  * pair
  * tuple
  * set
  * Hashing:
    - There are a lot of problems whose description seems crazy, and first thought baffles you but the solutions is pretty simple.
  * unordered_set
  * multiset
  * map
  * unordered_map
  * priority_queue
  * deque
  * stack
  * queue
  * bitset:
    - Traversing all Submasks of a mask in optimal time?
* Lambda functions
* Iterators
* Lower/upper bound
* `nth_element`
* Custom hashes
* C++ memory/reference behavior

### 🔴 Post-Master

* Advanced amortized analysis
* Cache-friendly thinking
* Constant-factor optimization
* Memory-layout considerations
* Persistent structures
* Custom allocators / specialized implementations
* Intricate randomized hashing
* Low-level optimization

---

# 2. Complexity & Problem Analysis

This is **more important than another algorithm**.

### 🟢 Pre-Master

Learn to immediately translate:

> `n ≤ 20` → exponential may work

> `n ≤ 40` → meet-in-the-middle

> `n ≤ 200` → O(n³) potentially

> `n ≤ 2000` → O(n²)

> `n ≤ 2e5` → O(n log n) / O(n)

> `n ≤ 1e9` → mathematical / logarithmic

Patterns:

* Constraint → algorithm
* Operations count
* Amortization
* Tight vs loose bounds
* Worst-case analysis
* Expected complexity
* Choosing between O(n²), O(n log n), O(n)
* State-space size estimation

### 🔴 Post-Master

* Complexity tradeoffs
* Sqrt decomposition reasoning
* O(n√n)
* O(n log² n)
* O(n² / word_size)
* Bitset acceleration
* Small-to-large complexity
* Potential-function analysis
* Randomized expected complexity

---

# 3. Mathematics & Number Theory

## 🟢 Pre-Master

### Arithmetic

* GCD
* LCM
* Euclidean algorithm
* Extended Euclidean algorithm
* Modular arithmetic
* Modular inverse
* Fast exponentiation
* Modular division
* Fermat's little theorem
* Euler's theorem
* Euler phi
* Chinese remainder theorem
* Linear congruences

### Primes

* Sieve of Eratosthenes
* Linear sieve
* Prime factorization
* SPF
* Divisor enumeration
* Number of divisors
* Sum of divisors
* Möbius function basics
* Inclusion-exclusion

### Combinatorics

* Factorials
* nCr
* nPr
* Pascal triangle
* Modular combinations
* Stars and bars
* Basic recurrence relations

### Mathematical sequences

* Fibonacci
* Arithmetic/geometric sequences
* Recurrences
* Matrix exponentiation

### Other

* Floor/ceil manipulation
* Divisibility
* Parity
* Modular patterns
* Pigeonhole principle
* Invariants
* Monovariants

## 🔴 Post-Master

* Advanced Möbius inversion
* Dirichlet convolution
* Multiplicative functions
* Inclusion-exclusion at scale
* Chinese remainder constructions
* Primitive roots
* Discrete logarithm
* Baby-step giant-step
* Pollard Rho
* Miller-Rabin
* Cipolla
* Tonelli-Shanks
* Advanced matrix techniques
* Linear recurrences via polynomial methods
* Berlekamp-Massey
* Generating functions
* Formal power series

---


# 4. Constructive Algorithms

**This deserves special attention for you.**

Constructive is not one algorithm. It's a giant collection of **ways of thinking**.

- I think that going with what the question statement tells you do is not going to work at higher levels, there's a hidden pattern underneath that. Yup, how do I learn this art of twisting the question to spot a different pattern or apply one.
- Turn your simulation/solution into proper system instead of random algorithm, to avoid WA.
- stop overthinking, the author intended a pattern, detect that.

## 🟢 Pre-Master

### Basic construction

* Build answer from smallest case
* Algebraic equation manipulation:
  - https://leetcode.com/problems/count-number-of-bad-pairs/description/
* Work backwards
* Construct incrementally
* Greedy construction
* Alternating construction
* Symmetric construction
* Pairing
* Grouping
* Rearrangement
* Permutation construction
* Rotation
* Reversal
* Swapping
* Divide into blocks
* Apply operation any number of times (Simulation is a trap)
    Flow of operation:
    https://leetcode.com/problems/minimize-maximum-of-array/description/
* Inversion (the opposite of what's asked):
  - Take away from both ends <-> what's left in the middle: 
    https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/

### Parity

* Odd/even construction
* Parity preservation
* Parity balancing
* XOR parity
* Number of odd/even elements
* Modulo-based construction

### Invariants

* Preserve sum
* Preserve parity
* Preserve XOR
* Preserve permutation structure
* Preserve connectedness
* Preserve some count

### Small cases

* n = 1, 2, 3...
* Identify sequence
* Find invariant
* Generalize

### Greedy constructions

* Largest-first
* Smallest-first
* Place extreme elements
* Fix one constraint at a time
* Construct around a forced element
* Exchange elements

### Permutation constructions

* Identity
* Reverse
* Cyclic shift
* Alternating high/low
* Pair adjacent elements
* Position-based construction
* Avoiding fixed points
* Derangements
* Inversion manipulation

### Graph constructions

* Build tree satisfying degrees
* Construct connected/disconnected graph
* Construct bipartite graph
* Construct Eulerian graph
* Construct graph with specified property

### String constructions

* Alternating characters
* Run-based construction
* Palindrome construction
* Avoiding substrings
* Frequency balancing
* Lexicographically smallest/largest construction

---

## 🔴 Post-Master constructive

This is where construction becomes much more interesting.

* Construction through invariant discovery
* Multiple interacting constraints
* Algebraic construction
* Constructing optimal objects
* Constructive + greedy
* Constructive + graph theory
* Constructive + matching
* Constructive + flow
* Constructive + number theory
* Constructive + DP
* Recursive construction
* Divide-and-conquer construction
* Self-similar constructions
* Adversarial construction
* Constructive proof from impossibility
* Turning optimization into construction
* Constructing witnesses
* Finding hidden canonical forms

### The meta-skill

Eventually you want:

> **Requirement → identify what must necessarily be true → construct around that necessity.**

Rather than:

> “Let me guess an arrangement.”

This is probably the single most useful thing for your current weakness.

---

# 5. Greedy

## 🟢 Pre-Master

* Sort + greedy
* Choose smallest/largest
* Earliest deadline
* Interval scheduling
* Activity selection
* Exchange argument
* Greedy matching
* Two-ended greedy
* Priority queue greedy
* Maintain best candidate
* Local improvement
* Frequency-based greedy
* Constructive greedy
* Greedy with prefix/suffix
* Greedy + binary search
* Greedy + DSU
* Greedy + heap
* Greedy on trees

### Important proof patterns

* Exchange argument
* Stays-ahead argument
* Cut/property argument
* Local optimality → global optimality
* Dominance
* Invariant

## 🔴 Post-Master

* Greedy matroid intuition
* Greedy with advanced data structures
* Greedy + flow
* Greedy + convexity
* Greedy + DP
* Greedy on complicated state spaces
* Non-obvious exchange arguments
* Greedy under dynamic constraints

---

# 6. Arrays / Prefix / Suffix

## 🟢 Pre-Master

* Prefix sums
* 2D prefix sums
* Difference arrays
* 2D difference arrays
* Prefix minima/maxima
* Suffix minima/maxima
* Prefix frequency
* Frequency arrays
* Prefix XOR
* Prefix GCD
* Prefix/suffix combinations
* Kadane
* Subarray counting
* Subarray sums
* Range update tricks
* Imos method

### ⭐ Bridge

* Prefix-function-like thinking
* Offline preprocessing
* Prefix + suffix decomposition
* Split at position i
* Contribution counting

---

# 7. Two Pointers / Sliding Window

## 🟢 Pre-Master

* Fixed-size window
* Variable-size window
* At-most-K
* Exactly-K via difference:
  counting subarrays with k distinct.. here f denotes at most function  exactlyK=f(K)−f(K−1)
* Monotonic window
* Two sorted arrays
* Fast/slow pointer
* Subarray 
* Distinct-element windows
* Frequency windows

### 🔴 Post-Master

* Multiple interacting windows
* Two-pointer + data structure
* Two-pointer on trees/graphs
* Advanced contribution techniques
* Non-obvious monotonicity

---

# 8. Binary Search

## 🟢 Pre-Master

* Binary search on sorted array
* Lower bound
* Upper bound
* First/last valid
* Binary search on answer
* Feasibility checking
* Monotonic predicate
* Floating-point binary search
* Ternary search basics
* Binary lifting

### 🔴 Post-Master

* Parallel binary search
* Binary search + segment tree
* Binary search + DP
* Binary search + greedy
* Nested binary search
* Parametric optimization
* Fractional binary search
* Advanced decision/optimization transformations

---

# 9. Sorting & Order Techniques

## 🟢 Pre-Master

* Standard sorting
* Custom comparator
* Sort by multiple fields
* Coordinate compression
* Counting sort
* Radix sort basics
* Inversion counting
* Merge sort
* Order statistics
* Sorting + greedy
* Sorting + two pointers
* Sorting + prefix sums

### 🔴 Post-Master

* Sorting lower-bound arguments
* Implicit ordering
* Dynamic ordering
* Advanced order statistics
* Offline sorting transformations
* CDQ-style ordering

---

# 10. Data Structures

## 🟢 Pre-Master

### Basic

- Using something for monotonicity requires same end insertion and deletion.

* Stack: 
  - LIFO
  - can be used for monotonicity (but doesn't have second rank which deque supports)
* Queue: 
  - FIFO
* Deque:
  - used for monotonicity in a moving window (with second rank support)
  problems:
  - https://leetcode.com/problems/continuous-subarrays/description/
* Set
* Multiset
* Map
* Hash map
* Priority queue

### DSU

* Union-find
* Path compression
* Union by size/rank
* Component tracking
* DSU with metadata

### Fenwick Tree

* Point update/range query
* Range update/point query
* Range update/range query
* 2D BIT
* BIT for inversion counting
* BIT for order statistics

### Segment Tree

* Point update
* Range query
* Range update
* Lazy propagation
* Min/max/sum/GCD
* Range assignment
* Range addition
* Range minimum
* Merge-sort tree
* Persistent segment tree basics

### Monotonic structures

* Monotonic stack:
  When we have to maintain a monotonic list of elements for optimal answers, with LIFO operation all the while introducing new elements.
  https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
* Monotonic queue:
  When we have to maintain a monotonic list of elements for optimal answers, with FIFO operation all the while introducing new elements.
* Sliding minimum/maximum:
  When we have to slide through a list of elements (fixed size/variable size), while always having support for getting the max/min element in the current window in optimal time.
* Next greater/smaller element

---

## 🔴 Post-Master

* Persistent segment tree
* Dynamic segment tree
* Segment tree beats
* Li Chao tree
* Treap
* Splay tree
* Link-cut tree
* Euler-tour trees
* Advanced persistent structures
* Wavelet tree
* Wavelet matrix
* Range tree
* 2D segment tree
* Fractional cascading
* DSU rollback
* Partially persistent DSU
* Small-to-large structures
* sqrt decomposition
* Mo's algorithm
* Mo's with modifications

---

# 11. Trees

## 🟢 Pre-Master

* DFS
* BFS
* Tree diameter
* Tree centers
* Tree height/depth
* Subtree sizes
* Parent/depth
* Tree DP
* Rerooting basics
* Euler tour
* Binary lifting
* LCA
* Distance between nodes
* Path queries
* Subtree queries
* Tree greedy
* Tree matching basics
* Tree coloring

### Heavy-Light Decomposition

* HLD
* Path query
* Path update
* Subtree query

## 🔴 Post-Master

* Advanced rerooting
* Virtual trees
* Centroid decomposition
* Centroid tree
* DSU on tree
* Link-cut trees
* Dynamic trees
* Tree isomorphism
* Tree hashing
* Advanced tree DP
* Tree automata-style DP
* Matroid/tree interactions
* Advanced path decomposition

---

# 12. Graphs

## 🟢 Pre-Master

### Basics

* Adjacency list/matrix
* BFS
* DFS
* Connected components
* Bipartite checking
* Cycle detection

### Shortest path

* BFS shortest path
* 0-1 BFS
* Dijkstra
* Bellman-Ford basics
* Floyd-Warshall
* DAG shortest path

### MST

* Kruskal
* Prim
* DSU

### DAG

* Topological sorting
* DAG DP
* Dependency ordering

### Connectivity

* Bridges
* Articulation points
* Biconnected components
* SCC
* Kosaraju
* Tarjan

### Euler

* Euler path
* Euler circuit
* Hierholzer

---

## 🔴 Post-Master

* 2-SAT
* Dominator concepts
* Dynamic connectivity
* Offline dynamic connectivity
* DSU rollback
* Advanced SCC condensation
* Minimum mean cycle
* Johnson's algorithm
* Advanced shortest paths
* SPFA-related theory
* Functional graphs deeply
* Randomized graph algorithms
* Graph decomposition
* Treewidth-related concepts
* Advanced DAG techniques

---

# 13. Dynamic Programming

- Don't think sequentially, dynamic programming is based on first principles. Think of a problem in states, instead of brute forcing then converting. Think alternatively to just implementation, how can I tweak the variables into independent state parameters who go back and forth to achieve the final goal. Yes, focus on decoupling the problem
MY TLE and AC soln to this problem is a good example: https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/

This is another **massive category**.

## 🟢 Pre-Master

### Basic DP

* 1D DP
* 2D DP
* Knapsack
* Subset sum
* Coin change
* LIS
* LCS
* Edit distance
* Grid DP
* Prefix DP

### State design

* Position
* Prefix
* Remaining resource
* Last element
* Count/frequency
* Bitmask
* Tree node
* Graph state

### Common structures

* DP + prefix sums
* DP + monotonic queue
* DP + binary search
* DP + greedy
* DP + sorting: https://leetcode.com/problems/maximum-strictly-increasing-cells-in-a-matrix/

### Bitmask DP
* permutation dp: https://leetcode.com/problems/special-permutations/description/
* Subset DP: 
  https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/
* TSP
* Assignment
* SOS DP basics

### Tree DP

* Independent set
* Matching
* Coloring
* Subtree states
* Rerooting

### Digit DP

* Basic digit DP
* Tight
* Leading zeros
* Digit constraints
* Counting numbers satisfying properties

---

## 🔴 Post-Master

### DP optimizations

* Divide-and-conquer optimization
* Knuth optimization
* Convex Hull Trick
* Li Chao optimization
* Monotone queue optimization
* Monotone stack optimization
* Alien trick / Lagrangian relaxation
* WQS binary search
* SMAWK
* Quadrangle inequality
* Monge optimization

### Advanced DP

* Profile DP
* Broken profile DP
* SOS DP
* Subset convolution
* Meet-in-the-middle DP
* Treewidth-style DP
* Automaton DP
* DP over subsets
* DP over partitions
* DP over DAG states
* Min-plus convolution
* Polynomial DP
* Generating-function DP

---

# 14. Strings

## 🟢 Pre-Master

* String frequency
* Prefix/suffix
* Palindromes
* String hashing
* Rolling hash
* Double hash
* KMP
* Prefix function
* Z-function
* Trie
* Basic string matching
* Lexicographic comparison
* String sorting
* Substring counting

## 🔴 Post-Master

* Suffix array
* LCP
* Suffix automaton
* Suffix tree
* Aho-Corasick
* Palindromic tree / Eertree
* Lyndon factorization
* Advanced string hashing
* String algorithms + DP
* String algorithms + trees
* Runs
* Minimal representation
* Advanced periodicity
* String combinatorics

---

# 15. Bit Manipulation

## 🟢 Pre-Master

You should become **very comfortable** here.

* AND / OR / XOR
* Bit shifts
* Set/unset/toggle
* Lowest set bit
* Popcount
* Bit masks
* Subset enumeration
* Superset enumeration
* XOR properties
* XOR basis basics
* Bitmask DP
* Bitwise greedy
* Power of two
* Binary representation
* Bitwise contribution

## 🔴 Post-Master

* Linear XOR basis deeply
* XOR Gaussian elimination
* Bitwise trie
* AND/OR convolution
* Walsh-Hadamard Transform
* SOS DP deeply
* Bitset optimization
* Word-level parallelism
* Bitwise divide-and-conquer

---

# 16. Range Queries / Offline Techniques
 
  https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/description/: instead of mapping elements to intervals, see that you can make intervals of existing elements too.

## 🟢 Pre-Master

* Prefix sums
* Difference arrays
* Fenwick
* Segment tree
* Sparse table
* Offline sorting:
* Sweep line
* Coordinate compression
* Range minimum
* Range maximum
* Range frequency

## 🔴 Post-Master

* Mo's algorithm
* Mo's with modifications
* CDQ divide and conquer
* Offline parallel binary search
* Persistent segment tree
* Wavelet tree
* Advanced sweep line
* Offline dynamic connectivity
* Divide-and-conquer on queries

---

# 17. Geometry

## 🟢 Pre-Master

* Points/vectors
* Distance
* Dot product
* Cross product
* Orientation
* Collinearity
* Line intersection
* Segment intersection
* Polygon area
* Shoelace formula
* Convex hull basics
* Rotating calipers basics
* Circle basics

## 🔴 Post-Master

* Half-plane intersection
* Minkowski sum
* Advanced rotating calipers
* Voronoi diagrams
* Delaunay triangulation
* Closest pair advanced
* Line sweep geometry
* Circle intersection problems
* Tangents
* Computational geometry data structures
* 3D geometry

---

# 18. Combinatorics

## 🟢 Pre-Master

* Permutations
* Combinations
* Inclusion-exclusion
* Pigeonhole
* Stars and bars
* Catalan numbers
* Basic recurrence
* Expected value
* Probability basics
* Counting arrangements
* Derangements
* Burnside basics

## 🔴 Post-Master

* Generating functions
* Exponential generating functions
* Ordinary generating functions
* Formal power series
* Polynomial multiplication
* NTT
* FFT
* Burnside's lemma deeply
* Polya enumeration
* Stirling numbers
* Bell numbers
* Advanced inclusion-exclusion
* Möbius inversion
* Combinatorial species-level thinking

---

# 19. Probability / Expected Value

## 🟢 Pre-Master

* Basic probability
* Linearity of expectation
* Conditional probability
* Expected number of events
* Random walks
* Expected DP
* Probability DP
* Geometric expectation
* Indicator variables

## 🔴 Post-Master

* Markov chains
* Absorbing Markov chains
* Probability generating functions
* Advanced random processes
* Randomized algorithms
* Probabilistic method
* Expected complexity
* Randomized hashing analysis

---

# 20. Game Theory

## 🟢 Pre-Master

* Winning/losing states
* Nim
* Sprague-Grundy basics
* XOR game
* Game DP
* Impartial games
* Grundy numbers

## 🔴 Post-Master

* Misère games
* Composite games
* Green Hackenbush concepts
* Combinatorial game theory
* Partizan games
* Advanced Grundy constructions
* Game + graph/DP hybrids

---

# 21. Matching / Flow

## 🟢 Pre-Master / Bridge

* Bipartite matching
* Kuhn algorithm
* Hopcroft-Karp
* Maximum flow
* Min-cut
* Dinic
* Flow modeling
* Vertex capacity
* Edge capacity
* Bipartite vertex cover
* Konig's theorem

### Important modeling patterns

* Assignment → matching
* Compatibility → matching
* Selection under constraints → flow
* Minimum cut as partition
* Maximum independent set in bipartite graph

## 🔴 Post-Master

* Min-cost max-flow
* Lower-bound flow
* Circulation
* Flow with demands
* Project selection
* Closure problems
* General matching
* Blossom algorithm
* Matching theory
* Flow + DP
* Flow + geometry
* Matroid intersection

---

# 22. Advanced Graph Algorithms

## 🔴 Mostly Post-Master

* Max-flow variants
* Min-cost flow
* General matching
* Blossom
* Dominator tree
* Heavy graph decomposition
* Dynamic MST
* Dynamic connectivity
* Offline graph deletion
* Link-cut tree graph applications
* DSU rollback
* Centroid decomposition on graph-derived structures
* Matroid concepts
* Matroid intersection
* Graph minors / structural techniques

---

# 23. Advanced Data Structures

## 🔴 Post-Master

A rough progression:

**Segment tree**

→ lazy segment tree

→ persistent segment tree

→ dynamic segment tree

→ merge-sort tree

→ wavelet tree

→ segment tree beats

→ Li Chao

→ treap

→ implicit treap

→ splay

→ link-cut tree

→ advanced persistence

→ specialized structures.

You don't need all of these to become Red, but eventually you'll encounter most of them.

---

# 24. Advanced Number Theory

## 🔴 Post-Master

This is where CP starts looking like competitive mathematics.

* Möbius inversion
* Dirichlet convolution
* Multiplicative functions
* Fast divisor transforms
* Prime counting
* Miller-Rabin
* Pollard Rho
* Primitive roots
* Discrete logarithm
* Baby-step giant-step
* Cipolla
* Tonelli-Shanks
* Quadratic residues
* Chinese remainder theorem
* Garner's algorithm
* Polynomial arithmetic
* Formal power series
* NTT
* FFT
* Berlekamp-Massey

---

# 25. Advanced Polynomial / Algebraic Algorithms

## 🔴 Post-Master

* Polynomial multiplication
* FFT
* NTT
* Polynomial inverse
* Polynomial logarithm
* Polynomial exponential
* Polynomial square root
* Polynomial derivative/integral
* Multipoint evaluation
* Multipoint interpolation
* Linear recurrence
* Berlekamp-Massey
* Matrix exponentiation
* Min-plus algebra
* XOR convolution
* AND convolution
* OR convolution
* Walsh-Hadamard transform

This is **very much later-stage CP**, not something I'd put on your immediate roadmap.

---

# 26. Meta-Techniques

This is the category I most want you to consciously train.

## 🟢 Pre-Master

### Reduction

> “Can I turn this problem into something I already know?”

Examples:

* Problem → graph
* Problem → shortest path
* Problem → matching
* Problem → DP
* Problem → binary search
* Problem → sorting
* Problem → prefix sums

### Contribution technique

Instead of computing:

> total answer

compute:

> contribution of each element.

### Complement thinking

Instead of:

> maximize X

consider:

> minimize what isn't X.

### Reverse thinking

Instead of:

> How do I build the answer?

ask:

> What must the final answer look like?

### Invariants

Ask:

> What cannot change?

### Monotonicity

Ask:

> If I increase X, can the answer only move one way?

### Extremal thinking

Ask:

> What happens to the largest/smallest element?

### Small-case analysis

Always.

### Brute force → pattern

One of the most powerful techniques:

> Write brute force for n ≤ 10 → generate answers → inspect structure → derive solution.

### Stress testing

* Random generator
* Brute solution
* Optimized solution
* Compare

### Reverse engineering

Given a valid output, ask:

> What property makes this output valid?

---

## 🔴 Post-Master meta-techniques

This is where the “red coder intuition” starts becoming visible.

### Problem transformation

Recognizing that a problem is secretly:

* a known theorem
* a graph problem
* a flow problem
* a matroid
* a convolution
* a shortest-path problem on an implicit graph
* a DP optimization

### Duality

* primal ↔ dual
* max ↔ min
* matching ↔ vertex cover
* flow ↔ cut
* counting ↔ complement

### Lagrangian relaxation

Convert:

> constrained optimization

into:

> unconstrained optimization + penalty.

### Parametric search

Turn optimization into decision.

### Divide-and-conquer thinking

Not just algorithmically, but conceptually:

> “Can I isolate an interaction at a midpoint?”

### Meet in the middle

Split problem into two independently manageable halves.

### Small-to-large

Always merge smaller structures into larger ones.

### Offline conversion

Turn dynamic problem into:

> “If I knew all queries beforehand, what becomes easy?”

### Reverse time

Process deletions as additions.

### Persistence

Turn history into a data structure.

### Randomization

When deterministic structure is hard:

> Can I make the probability of failure negligible?

### Algebraization

Turn combinatorial objects into:

* polynomials
* matrices
* vectors
* XOR bases
* convolutions

That's a major hallmark of higher-level CP.

---

# The progression I'd expect for you

Given that you reached **Expert in ~1 year**, then stopped for three months, I would *not* try to learn this entire list.

Your immediate target should be:

### Phase 1 — Reactivation

**Fundamentals + 1200–1600**

Revisit:

* implementation
* STL
* prefix/suffix
* sorting
* binary search
* two pointers
* greedy
* basic math
* basic graphs
* basic DP
* basic constructive

The goal isn't difficulty.

It's:

> **“Oh, I remember how to think about this.”**

---

### Phase 2 — Rebuild Expert

Then:

**1500–1900**

Focus heavily on:

* constructive
* greedy
* DP
* graphs
* binary search
* data structures
* number theory

And importantly, **upsolve rather than just solve more problems.**

---

### Phase 3 — Contest re-entry

Start doing virtuals around your old level.

After each virtual:

| Failure                            | What it means                 |
| ---------------------------------- | ----------------------------- |
| Didn't know technique              | Knowledge gap                 |
| Knew technique, didn't recognize   | Pattern-recognition gap       |
| Had idea, couldn't prove           | Reasoning gap                 |
| Had solution, couldn't code        | Implementation gap            |
| Solved after contest quickly       | Contest-pressure gap          |
| Couldn't solve even after solution | Fundamental understanding gap |

That distinction is incredibly valuable.

---

# And specifically for your constructive problem issue

I actually **wouldn't make “constructive” a separate side quest anymore.**

I'd make it one of your **four pillars** during the comeback:

**Greedy + Constructive + DP + Graphs**

because constructive is teaching you something you don't get from memorizing algorithms:

> **How to generate ideas when there is no obvious algorithmic framework.**

And that is precisely the skill you've been worrying about since our earlier conversations.

The mistake would be trying to fix it by doing 100 constructive problems mechanically.

Instead, for every constructive problem you upsolve, record:

**1. What was the final construction?**
**2. What observation made it possible?**
**3. What failed approaches did I try?**
**4. What clue in the statement/examples could have led me there?**
**5. What other problems could use the same idea?**

That fifth question is where the real compounding happens.

---

# One final thing: don't try to “complete” this map

This list is deliberately overwhelming because you asked for exhaustive.

**Do not interpret it as a syllabus.**

You do *not* need to know all of this before becoming Master. And you certainly don't need all of it before returning to contests.

Think of it as a **map of the territory**.

Your actual progression should look more like:

> **Reactivation → Expert again → stabilize → CM → Master → expand into advanced techniques → GM/Red**

And after three months away, I'd expect your first few contests to feel **way worse than your old rating**. That's normal. Your knowledge hasn't disappeared; your retrieval speed, contest rhythm and pattern recognition have gone rusty.

So I would actually make your comeback goal:

> **Don't try to prove you're still Expert. Try to become comfortable being bad for 2–3 weeks while your brain reloads the library.**

That mindset is especially important given the self-doubt we've talked about before. Your first few virtuals should be **diagnostic**, not a referendum on whether you are capable of reaching Master/Red.
