Here’s the content formatted in a `README.md` for C++ Standard Library headers useful for programming competitions:

````markdown
# C++ Standard Library for Programming Competitions

This document provides an essential list of C++ Standard Library headers and their key utilities, particularly for competitive programming.

---

### **Core Headers**

1. **`<algorithm>`**

   - **Sorting**: `sort`, `stable_sort`, `partial_sort`
   - **Searching**: `lower_bound`, `upper_bound`, `binary_search`
   - **Min/Max**: `min_element`, `max_element`, `min`, `max`
   - **Permutations**: `next_permutation`, `prev_permutation`
   - **Useful**: `reverse`, `rotate`, `swap`, `fill`, `unique`

2. **`<vector>`**

   - **Dynamic arrays**: `vector<T>` (resizable, cache-friendly)
   - **Key methods**: `push_back`, `pop_back`, `reserve`, `emplace_back`

3. **`<queue>`**

   - **FIFO**: `queue<T>` (BFS)
   - **Priority Queue**: `priority_queue<T>` (max-heap by default; use `greater<T>` for min-heap).
   - **Deque**: `deque<T>` (fast insert/delete at both ends).

4. **`<utility>`**

   - **Pairs**: `pair<T1, T2>` (used in sorting, graphs, maps, etc.).

5. **`<set>` / `<map>`**

   - **Ordered containers**: `set<T>`, `map<K,V>` (log-time operations, sorted order).
   - **Multisets**: `multiset<T>`, `multimap<K,V>`.

6. **`<unordered_set>` / `<unordered_map>`**
   - **Hash-based containers**: O(1) average lookup (no ordering).

---

### **I/O & Strings**

7. **`<iostream>`**

   - **Basic I/O**: `cin`, `cout`, `cerr`.
   - **Speed tip**: `ios_base::sync_with_stdio(false); cin.tie(nullptr);`.

8. **`<string>`**

   - **String operations**: `substr`, `find`, `compare`, `+=`.

9. **`<cstdio>`** (Optional)
   - **Faster I/O**: `scanf`, `printf` (useful for large inputs).

---

### **Advanced Utilities**

10. **`<bitset>`**

    - **Fixed-size bit manipulation**: `bitset<N>` (e.g., `count`, `set`, `flip`).

11. **`<numeric>`**

    - **Math**: `gcd`, `lcm` (C++17+), `accumulate`, `partial_sum`, `iota`.

12. **`<functional>`**

    - **Comparators**: `greater<T>`, `less<T>`, `hash<T>`.
    - **Lambdas**: Useful with algorithms like `sort`.

13. **`<cmath>`**

    - **Math functions**: `sqrt`, `pow`, `abs`, `ceil`, `floor`.

14. **`<stack>`**
    - **LIFO**: `stack<T>` (DFS, expression evaluation).

---

### **Common Use Cases**

- **Sorting + Custom Comparators**
  ```cpp
  sort(v.begin(), v.end(), [](auto &a, auto &b) { return a[0] < b[0]; });
  ```
````

- **Priority Queue of Pairs**

  ```cpp
  priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq; // min-heap
  ```

- **Hash Map for Frequency Counting**

  ```cpp
  unordered_map<int, int> freq;
  for (auto x : arr) freq[x]++;
  ```

- **Binary Search**
  ```cpp
  auto it = lower_bound(v.begin(), v.end(), target);
  if (it != v.end() && *it == target) cout << "Found";
  ```

---

### **Pro Tips**

- **Use `auto` and Range-based Loops**

  ```cpp
  for (auto &x : vec) { ... } // faster to type
  ```

- **Prefer `emplace_back` over `push_back`**
  Avoids unnecessary copies (e.g., `vec.emplace_back(a, b);` for `pair<int,int>`).

- **Reserve Vector Size**

  ```cpp
  vector<int> v; v.reserve(1e5); // avoids reallocations
  ```

- **Bitmasking with `bitset`**
  ```cpp
  bitset<32> mask(42); // 32-bit mask for the number 42
  ```

---
