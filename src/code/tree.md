# Tree Algorithm



## Disjoint Set Union

支援操作：

1. `void init(int n)`
    - 初始化點集合為 $[0, n]$，代表 $0$-base 或 $1$-base 皆可
2. `int R(int x)`
    - **均攤** $\Ord(\log n)$ 回傳 $x$ 所在的集合的 boss 並路徑壓縮
3. `int U(int x, int y)`
    - **均攤** $\Ord(\log n)$ 合併 $x$ 與 $y$ 所在的集合，合併成功回傳 $1$，否則回傳 $0$

<details><summary>Code</summary>

```cpp
{{ #include ./tree/dsu.cpp }}
```

</details>



## Lowest Common Ancestor

- <https://contest.yandex.com/contest/70295/problems/E/>
    - $\Ord(n \log C)$ 次詢問某個樹的點集 subset 上離某個點最遠的點距離

支援操作：

1. `void init(int n)`
    - 初始化點集合為 $[0, n]$，代表 $0$-base 或 $1$-base 皆可
2. `void add_edge(int u, int v)`
    - 加無向不帶權的邊 $(u, v)$
3. `void build()`
    - $\langle \Ord(n \log n), \Ord(n \log n) \rangle$ DFS + 建 Sparse Table
4. `int lca(int u, int v)`
    - $\Ord(1)$ 找 $u$ 與 $v$ 的最近共同祖先
5. `int lca_jump(int u, int v)`
    - $\Ord(\log n)$ 找 $u$ 與 $v$ 的最近共同祖先，需要把 `anc[][]` 相關的註解拿掉
6. `int jump(int u, int k)` ***untested***
    - $\Ord(\log n)$ 找 $u$ 往上第 $k$ 個祖先，需要把 `anc[][]` 相關的註解拿掉
7. `int dist(int u, int v)`
    - $\Ord(1)$ 找 $u$ 與 $v$ 的距離

<div class="warning">

支援不連通的森林，但在做 LCA 時，請確保 $u$ 與 $v$ 連通

</div>

<details><summary>Code</summary>

```cpp
{{ #include ./tree/lca.cpp }}
```

</details>



## Lowest Common Ancestor with Information on Edges

支援操作（基本同上）：

1. `void init(int n)`
    - 初始化點集合為 $[0, n]$，代表 $0$-base 或 $1$-base 皆可
2. `void add_edge(int u, int v, const Info &info)`
    - 加無向不帶權的邊 $(u, v)$，邊上帶有資訊 `info`
3. `void build()`
    - $\langle \Ord(n \log n), \Ord(n \log n) \rangle$ DFS + 建跳表
4. `pair<int, Info> lca_jump(int u, int v)`
    - $\Ord(\log n)$ 找 $u$ 與 $v$ 的最近共同祖先
5. `Info get_info(int u, int v)`
    - $\Ord(\log n)$ 回傳 $u$ 與 $v$ 之間的邊上的資訊（只是 call 了一次 `lca_jump`）
6. `int jump(int u, int k)` ***untested***
    - $\Ord(\log n)$ 找 $u$ 往上第 $k$ 個祖先
7. `int dist(int u, int v)`
    - $\Ord(1)$ 找 $u$ 與 $v$ 的距離

<div class="warning">

需要自定義 `struct Info`，並實作

- `Info()` (default constructor)
- `Info& operator += (const Info &rhs)`
- `friend Info operator + (Info lhs, const Info &rhs)`

</div>

<div class="warning">

此處的資訊是無向的，必須滿足交換律才能使用，否則還需稍作修改

</div>

<details><summary>Code</summary>

```cpp
{{ #include ./tree/lca_with_info.cpp }}
```

</details>
