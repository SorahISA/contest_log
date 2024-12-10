# Data Structure



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
{{ #include ./data_structure/dsu.cpp }}
```

</details>



## Disjoint Set Union with Undo

- <https://oj.ntucpc.org/problems/856>
    - DSU with Undo 好題

支援操作：

1. `void init(int n)`
    - 初始化點集合為 $[0, n]$，代表 $0$-base 或 $1$-base 皆可
2. `int R(int x)`
    - $\Ord(\log n)$ 回傳 $x$ 所在的集合的 boss
3. `int U(int x, int y)`
    - $\Ord(\log n)$ **啟發式** 合併 $x$ 與 $y$ 所在的集合，合併成功回傳 $1$，否則回傳 $0$
4. `void undo()`
    - 回復上一次的有效 `U(x, y)` 操作

<details><summary>Code</summary>

```cpp
{{ #include ./data_structure/dsu_with_undo.cpp }}
```

</details>

<details><summary>Code with 離散化</summary>

```cpp
{{ #include ./data_structure/dsu_with_undo_and_disc.cpp }}
```

</details>



## Interval Container

- <https://oj.ntucpc.org/problems/853>
    - 區間修改，區間移除並計算每個數字的出現次數平方和
- <https://codeforces.com/contest/896/problem/C>
    - 珂朵莉樹模板

宣告：

- `IntervalContainer<int> itv;`
    - 儲存 `int` 型別的資訊

支援操作：

1. `void cut(int p)`
    - 將 $p-1$ 跟 $p$ 切開（helper function，應該不會被直接呼叫）
2. `void modify(int l, int r, T v)`
    - 將 $[\ell, r]$ 區間的值修改為 $v$
3. `vector<pair<pii, T>> get(int l, int r)`
    - 取得 $[\ell, r]$ 區間的值
4. `vector<pair<pii, T>> remove(int l, int r)`
    - 將 $[\ell, r]$ 區間的值移除，並回傳被移除的區間與值

<details><summary>Code</summary>

```cpp
{{ #include ./data_structure/interval_container.cpp }}
```

</details>
