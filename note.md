# 📘 Competitive Programming Data Structures Reference

## 🔑 Associative Containers

### `map<Key, Value>`
- **Properties**: Ordered key-value pairs (Red-Black Tree).
- **Common functions**:
  - `m[key]` → access/insert `O(log n)`
  - `m.find(key)` → iterator or `m.end()` if not found `O(log n)`
  - `m.lower_bound(key)` → first element `>= key` `O(log n)`
  - `m.upper_bound(key)` → first element `> key` `O(log n)`
  - `m.erase(key/it)` → remove element `O(log n)`
  - Iteration → sorted by key
- **Use cases**: frequency count, ordered queries, coordinate compression.

---

### `set<Key>`
- **Properties**: Stores unique sorted keys.
- **Common functions**:
  - `s.insert(x)` → `O(log n)`
  - `s.erase(x/it)` → `O(log n)`
  - `s.find(x)` → `O(log n)`
  - `s.lower_bound(x)`, `s.upper_bound(x)` → `O(log n)`
  - `*s.begin(), *s.rbegin()` → smallest/largest
- **Use cases**: dynamic order stats, unique storage, greedy/interval problems.

---

### `unordered_map<Key, Value>`
- **Properties**: Hash table, unsorted key-value pairs.
- **Common functions**:
  - `um[key]` → access/insert `O(1)` avg
  - `um.find(key)` → iterator `O(1)` avg
  - `um.erase(key/it)` → remove `O(1)` avg
  - `um.count(key)` → presence check
- **Use cases**: fast frequency table, memoization, adjacency lists.

---

### `unordered_set<Key>`
- **Properties**: Hash table, unique keys, no order.
- **Common functions**:
  - `us.insert(x)` → `O(1)` avg
  - `us.erase(x)` → `O(1)` avg
  - `us.find(x)` → `O(1)` avg
  - `us.count(x)` → 0/1 membership test
- **Use cases**: duplicate detection, fast membership checking.

---

## 📦 Linear Containers

### `queue<T>`
- **Properties**: FIFO (First-In-First-Out).
- **Common functions**:
  - `q.push(x)` → add to back `O(1)`
  - `q.pop()` → remove front `O(1)`
  - `q.front()` → access front `O(1)`
  - `q.back()` → access back `O(1)`
  - `q.empty()` → check if empty
  - `q.size()` → current size
- **Use cases**: BFS, task scheduling.

---

### `deque<T>`
- **Properties**: Double-ended queue.
- **Common functions**:
  - `dq.push_back(x)`, `dq.push_front(x)` → `O(1)` amortized
  - `dq.pop_back()`, `dq.pop_front()` → `O(1)` amortized
  - `dq.front()`, `dq.back()` → `O(1)`
  - `dq[i]` → random access `O(1)`
  - Iteration like vector
- **Use cases**: sliding window maximum/minimum, 0-1 BFS, monotonic queue tricks.

---

### `priority_queue<T>`
- **Properties**: Max-heap (default), min-heap with custom comparator.
- **Common functions**:
  - `pq.push(x)` → insert `O(log n)`
  - `pq.pop()` → remove top `O(log n)`
  - `pq.top()` → max/min element `O(1)`
  - `pq.empty()`, `pq.size()`
- **Use cases**: Dijkstra, Prim’s MST, greedy scheduling, k-largest elements.

---

## ⚡ Quick Summary Table

| Data Structure      | Insert     | Erase      | Search     | Access     | Notes              |
|---------------------|------------|------------|------------|------------|--------------------|
| `map`               | O(log n)   | O(log n)   | O(log n)   | O(log n)   | Sorted by key      |
| `set`               | O(log n)   | O(log n)   | O(log n)   | O(log n)   | Unique sorted      |
| `unordered_map`     | O(1) avg   | O(1) avg   | O(1) avg   | O(1) avg   | Hash table         |
| `unordered_set`     | O(1) avg   | O(1) avg   | O(1) avg   | O(1) avg   | Hash table         |
| `queue`             | O(1)       | O(1)       | -          | O(1)       | FIFO               |
| `deque`             | O(1) amort | O(1) amort | O(1)       | O(1)       | Double-ended queue |
| `priority_queue`    | O(log n)   | O(log n)   | -          | O(1)       | Heap               |

---
