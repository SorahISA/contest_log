# The 3rd Universal Cup. Stage 3: Ukraine

- 連結：[https://qoj.ac/contest/1714](https://qoj.ac/contest/1714)
- 時間：[2024 Oct 30, 17:40-22:40](https://www.timeanddate.com/worldclock/fixedtime.html?msg=The+3rd+Universal+Cup.+Stage+3%3A+Ukraine&iso=20241030T1740&p1=3910&ah=5)
- 團隊：ネクロマンサー (SorahISA)
- 成績：7 / 12, Penalty 910, dirt 12% (
  <b style="color:lime">A</b>
  <b style="color:red">B</b>
  <b style="color:lime">C</b>
  <b style="color:lime">D</b>
  <b style="color:lime">E</b>
  <b style="color:red">F</b>
  <b style="color:lime">G</b>
  <b style="color:lime">H</b>
  <b style="color:red">I</b>
  <b style="color:lime">J</b>
  <b style="color:red">K</b>
  <b style="color:red">L</b>
)

第一篇做題筆記，不以時間軸的方式記錄比賽，只記錄解題過程。

這場難度在 UCup 中算很低，最強的 USA1 甚至在兩個小時以內就破台了。

## [Problem A. Aibohphobia](https://contest.ucup.ac/contest/1714/problem/8829)

##### Tags: `casework`, `palindrome`  

> 給定字串 $s$，請將其重新排列使每個長度 $\ge 2$ 的前綴都不是回文。
> 
> * 多筆測資、$\sum |s| \le 10^6$

顯然只有一種字元無解，當有兩種字元的時候要 $s_1 \ne s_2$、$s_1 \ne s_3$、$\ldots$，可以得到必須要有某個字元只出現一次，否則無解。

當有三種以上的字元時，將字串排序並 `reverse(1 + ALL(s))` 後輸出即可。

## [Problem B. Breaking Bad](https://contest.ucup.ac/contest/1714/problem/8830)

待補

> 給定一個 $n \times n$ 的矩陣 $A$，請問在所有 $1, 2, \ldots, n$ 的排列 $\sigma$ 中，$\left( \sum_{i=1}^{n} A_{i, \sigma_i} \right) \bmod 5$ 可能有哪些值。
>
> * $n \le 1000$

## [Problem C. Chemistry Class](https://contest.ucup.ac/contest/1714/problem/8831)

##### Tags: `greedy`

> 給定 $2n$ 個整數 $a_1 < a_2 < \cdots < a_{2n}$，請將其兩兩配對滿足
> 
> - 不存在差距 $> A$ 的配對（*不合法*）
> - 差距 $\ge B$ 的配對數量盡量多（*好配對*）
> 
> * 多筆測資、$\sum n \le 200\,000$、值域 $[1, 10^{18}]$

以下令差距在 $(B, A]$ 之間的配對為 *壞配對*。

以下令 $i_1 < i_2 < i_3 < i_4$，觀察：

- 當配對 $(i_1, i_3)$ 及 $(i_2, i_4)$ 合法，則改成 $(i_1, i_2)$ 及 $(i_3, i_4)$ 也合法。
- 當配對 $(i_1, i_4)$ 及 $(i_2, i_3)$ 都是好配對，則改成 $(i_1, i_2)$ 及 $(i_3, i_4)$ 也是好配對。
- 當配對 $(i_1, i_4)$ 及 $(i_2, i_3)$ 都是壞配對，則改成 $(i_1, i_2)$ 及 $(i_3, i_4)$ 也仍然合法。

因此，可以得出以下性質：

1. 配對不會相交，可以看成括弧序列。
2. 好配對不會包著任意配對，也就是說好配對一定是 $(p, p+1)$ 的形式。
3. 壞配對只可能包著好配對，也就是說一定是 `BGG...GGB` 中間有偶數個 `G` 的形式。

採用 greedy 配對的方式，由左至右配對 `GG`，當不會讓壞配對 `B...GGB` 差距超過 $A$ 時就配對，否則就配對壞配對。

因為這總是保證了最多的好配對，所以 greedy 可以得到最佳解。

## [Problem D. Daily Disinfection](https://contest.ucup.ac/contest/1714/problem/8832)

##### Tags: `casework`

> 給定長度 $n$ 的 $01$ 字串 $s$，每次可以交換相鄰兩個字元，求最少交換次數使每個位置都出現過至少一次 `0`。
> 
> * 多筆測資、$\sum n \le 200\,000$

每個 `1` 都一定要移開，假設 $s_1 =$ `0` 那每個 `1` 都一定能往右移動。

觀察到只有在 `1.101.101.101.1` 這種 case（頭尾都是 `1` 且沒有連續的 `0`）才會讓 `1` 必須被挪動第二次，此時一定是挪動最小塊的連續 `1`。

## [Problem E. Equalizer Ehrmantraut](https://contest.ucup.ac/contest/1714/problem/8833)

##### Tags: `math`

> 請求出有多少個長度為 $n$ 的整數序列對 $(\Arr{a}, \Arr{b})$ 滿足 $1 \le a_i, b_i \le m$ 且對所有 $1 \le i < j \le n$ 皆有 $\min(a_i, b_j) = \min(a_j, b_i)$。
> 
> 模 $998\,244\,353$ 輸出。
> 
> * $1 \le n, m \le 10^6$

長一樣當然都是合法的，考慮當有數字不同的時候，W.L.O.G. $a_p > b_p$ 是第一個不同的位置且 $\Arr{a}$ 非嚴格遞增：

- 此時 $b_{p+1}$ 一定等於 $b_p$，否則 $[ b_p < a_p \le a_{p+1} ] \implies [ \min(a_{p+1}, b_p) = b_p = a_p = \min(a_p, b_{p+1}) \ne b_{p+1} ]$ 矛盾。

也就是合法的序列對長相是 $(\Arr{a}, \Arr{\min(a, x)})$。枚舉 $\Arr{a}$ 中的最大值 $x$ 後可以得到答案：

$$
\sum_{x=1}^{m} (x^n - (x-1)^n) \cdot (2x-1)
$$

即可 $\Ord(m \log n)$ 求解。

## [Problem F. Formal Fring](https://contest.ucup.ac/contest/1714/problem/8834)

待補

> 定義 $f(n)$ 是非負整數集合 $S$ 的數量，滿足 $\sum_{s \in S} 2^s = n$ 且不存在 $\emptyset \subsetneq T \subsetneq S$ 使得 $\floor{ \log_2 \left( \sum_{t \in T} 2^t \right) } = \floor{ \log_2 \left( \sum_{u \in T \backslash S} 2^u \right) }$。
>
> 請求出 $f(1), f(2), \ldots, f(X)$ 模 $998\,244\,353$ 的值。
>
> * $X \le 10^6$

## [Problem G. Goodman](https://contest.ucup.ac/contest/1714/problem/8835)

AC 但還不會證明，待補

> 定義兩個 $1, 2, \ldots, n$ 的 permutation $p, q$ 的複合 $\Arr{p \circ q}$ 為 $(p_{q_1}, p_{q_2}, \ldots, p_{q_n})$。
>
> 給定一個排列 $p$，請求出一個排列 $q$ 使 $\lvert \text{LCS}(\Arr{q}, \Arr{p \circ q}) \rvert$ 最大。
>
> * 多筆測資、$\sum n \le 10^6$

## [Problem H. Highway Hoax](https://contest.ucup.ac/contest/1714/problem/8836)

##### Tags: `dp`, `ntt`

> 給一棵 $n$ 個點的樹，邊是有向的，一開始有某些位置各有一個棋子，每次操作可以將一個棋子沿著出邊移到相鄰的點，但移動完後會將邊反轉。
> 
> 定義合法狀態是每個點的棋子數量皆 $\le 1$，求從原始盤面可以抵達多少種合法狀態。
> 
> 模 $998\,244\,353$ 輸出。
> 
> * $2 \le n \le 200\,000$

先觀察到任意邊 $(u, v)$ 只會有至多一次的 $u \to v$ 操作，移回去再移回來並沒有意義。當對這棵樹定根後，會具有以下性質：

- 合法狀態下，每個子樹的棋子數量必定是原始棋子數量 $\pm 1$ 以內，取決於跟父親連邊的方向。

這就會想使用 DP 解決：令 $\texttt{dp}_{v, +/0/-}$ 代表以 $v$ 為根的子樹，且 $v$ 有多一個 / 剛剛好 / 少一個棋子的合法狀態數量。這樣就可以得到以下轉移：

待補

每個小孩的 DP 值對應到多項式 $(\texttt{dp}_{v, +}) \cdot x^1 + (\texttt{dp}_{v, 0}) \cdot x^0 + (\texttt{dp}_{v, -}) \cdot x^{-1}$。

轉移可以把所有小孩的多項式 offset 一個 $x^1$ 之後 NTT 乘起來，但要注意要每次挑最短的兩個多項式做 NTT，否則複雜度仍會退化為 $\Ord(n^2)$。

一個方便的 $\Ord(n \log^2 n)$ trick 是把所有多項式丟進 queue（deque）裡，每次取出前兩個做事之後再放到最後面，這個的複雜度可以透過參考線段樹的長相感性證明。

## [Problem I. Increasing Income](https://contest.ucup.ac/contest/1714/problem/8837)

待補

> 定義兩個 $1, 2, \ldots, n$ 的 permutation $p, q$ 的複合 $\Arr{p \circ q}$ 為 $(p_{q_1}, p_{q_2}, \ldots, p_{q_n})$。
>
> 給定一個排列 $p$，請求出一個排列 $q$ 使 $f(\Arr{q}) + f(\Arr{p \circ q})$ 最大。
> 
> - $f(a_1, a_2, \ldots, a_k)$ 是 $\# \{ i : \forall j < i. a_i > a_j \}$，也就是前綴最大值數量。
>
> * 多筆測資、$\sum n \le 10^6$

## [Problem J. Jesse's Job](https://contest.ucup.ac/contest/1714/problem/8838)

##### Tags: N/A

> 給定一個排列 $\sigma$，你要將排列中的元素塗上黃色 `Y` 或紅色 `R`（至少各一），並最大化將黃色跟紅色分別排序之後的 $\#\{ \sigma_i' = i \}$。
>
> * 多筆測資、$\sum n \le 10^6$

先建 $i \to \sigma_i$ 的有向邊，此時圖會被分成許多個環。觀察到如果圖有兩個以上的連通塊，對各自分別排序就能將整個陣列排序。以下考慮圖只有一個連通塊的情況。

如果把環切成 $\Arr{i}, \Arr{j}$ 兩個部分：$i_1 \to i_2 \to \cdots \to i_k \to j_1 \to j_2 \to \cdots \to j_{n-k} \to i_1$，滿足 $i_1 = 1, j_1 = 2$，則可以發現：

- 選了位置 $i_p$ 會選到數字 $i_{p+1}$（選了位置 $i_k$ 會選到數字 $j_1 = 2$）。
- 選了位置 $j_q$ 會選到數字 $j_{q+1}$（選了位置 $j_{n-k}$ 朏選到數字 $i_1 = 1$）。

因為 $1$ 跟 $2$ 比所有其他數字都還要小，所以把位置 $\Arr{i}$ 排序後只會讓 $\sigma_{i_1}' = 2$，$\sigma_{i_p}' = i_p$；把位置 $\Arr{j}$ 排序後只會讓 $\sigma_{j_1}' = 1$，$\sigma_{j_q}' = j_q$。

至此，就得到了排好 $n-2$ 個數字的方法，而顯然在只有一個環的情況下不存在排好恰 $n-1$ 或 $n$ 個數字的方法。

## [Problem K. Knocker](https://contest.ucup.ac/contest/1714/problem/8839)

待補

> 給定正整數陣列 $\Arr{a}$，你可以選擇若干數字 $p_1, p_2, \ldots, p_k$ 並令 $a_i' = ((a_i \bmod p_1) \bmod p_2) \cdots \bmod p_k$，請問有幾種可能的 $\Arr{a'}$？
>
> 模 $998\,244\,353$ 輸出。
>
> * $n \le 500$、$a_i \le 500$

## [Problem L. Lalo's Lawyer Lost](https://contest.ucup.ac/contest/1714/problem/8840)

待補

> 給定一棵 $2n$ 個點的仙人掌，定義 $d(u, v)$ 是兩點的最短距離，請將這些點分成 $n$ 個 pair，使得 $\sum d(u_i, v_i)$ 最大。
>
> * 多筆測資、$\sum n \le 100\,000$、$\sum m \le 400\,000$
