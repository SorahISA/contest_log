# Data Structure



## Interval Container

- <https://oj.ntucpc.org/problems/853>
    - 區間修改，區間移除並計算每個數字的出現次數平方和
- <https://codeforces.com/contest/896/problem/C>
    - 珂朵莉樹模板

宣告：

- `IntervalContainer<int> ic`
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
