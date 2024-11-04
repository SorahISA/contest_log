# Tree Algorithm

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
