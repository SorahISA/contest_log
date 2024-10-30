# The 3rd Universal Cup. Stage 3: Ukraine

- Link: <https://qoj.ac/contest/1714>
- 時間：2024-10-30 17:40-22:40 (UTC+8)
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

## [Problem A. Aibohphobia](https://contest.ucup.ac/contest/1714/problem/8829)

> Tags: `casework`, `palindrome`  
> Difficulty: ☆

> 給定字串 $s$，請將其重新排列使每個長度 $\ge 2$ 的前綴都不是回文。
> * 多筆測資、$\sum |s| \le 10^6$

顯然只有一種字元無解，當有兩種字元的時候要 $s_1 \ne s_2$、$s_1 \ne s_3$、$\ldots$，可以得到必須要有某個字元只出現一次，否則無解。

當有三種以上的字元時，將字串排序並 `reverse(1 + ALL(s))` 後輸出即可。

## [Problem B. Breaking Bad](https://contest.ucup.ac/contest/1714/problem/8830)

待補

## [Problem C. Chemistry Class](https://contest.ucup.ac/contest/1714/problem/8831)

> Tags: `greedy`  
> Difficulty: ★★

> 給定 $2n$ 個數字 $a_1 < a_2 < \cdots < a_{2n}$，請將其兩兩配對滿足
> - 不存在差距 $> A$ 的配對（*不合法*）
> - 差距 $\ge B$ 的配對數量盡量多（*好配對*）
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

> Tags: `casework`  
> Difficulty: ★

> 給定長度 $n$ 的 $01-$字串 $s$，每次可以交換相鄰兩個字元，求最少交換次數使每個位置都出現過一次 `0`。
> * 多筆測資、$\sum n \le 200\,000$

每個 `1` 都一定要移開，假設 $s_1 =$ `0` 那每個 `1` 都一定能往右移動。

觀察到只有在 `1.101.101.101.1` 這種 case（頭尾都是 `1` 且沒有連續的 `0`）才會讓 `1` 必須被挪動第二次，此時一定是挪動最小塊的連續 `1`。

## [Problem E. Equalizer Ehrmantraut](https://contest.ucup.ac/contest/1714/problem/8833)

> Tags: `math`  
> Difficulty: ★★☆

> 請求出有多少個長度為 $n$ 的整數序列對 $(\langle a \rangle, \langle b \rangle)$ 滿足 $1 \le a_i, b_i \le m$ 且對所有 $1 \le i < j \le n$ 皆有 $\min(a_i, b_j) = \min(a_j, b_i)$。
> 模 $998\,244\,353$ 輸出。
> * $1 \le n, m \le 10^6$

長一樣當然都是合法的，考慮當有數字不同的時候，W.L.O.G. $a_p > b_p$ 是第一個不同的位置且 $\langle a \rangle$ 非嚴格遞增：

- 此時 $b_{p+1}$ 一定等於 $b_p$，否則 $[ b_p < a_p \le a_{p+1} ] \implies [ \min(a_{p+1}, b_p) = b_p = a_p = \min(a_p, b_{p+1}) \ne b_{p+1} ]$ 矛盾。

也就是合法的序列對長相是 $(\langle a \rangle, \langle \min(a, x) \rangle)$。枚舉 $\langle a \rangle$ 中的最大值 $x$ 後可以得到答案：

$$
\sum_{x=1}^{m} (x^n - (x-1)^n) \cdot (2x-1)
$$

即可 $\Ord(m \log n)$ 求解。

## [Problem F. Formal Fring](https://contest.ucup.ac/contest/1714/problem/8834)

待補

## [Problem G. Goodman](https://contest.ucup.ac/contest/1714/problem/8835)

AC 但還不會證明，待補

## [Problem H. Highway Hoax](https://contest.ucup.ac/contest/1714/problem/8836)

> Tags: `dp`, `ntt`  
> Difficulty: ★★★☆

> 給一棵 $n$ 個點的樹，邊是有向的，一開始有某些位置各有一個棋子，每次操作可以將一個棋子沿著出邊移到相鄰的點，但移動完後會將邊反轉。
> 定義合法狀態是每個點的棋子數量皆 $\le 1$，求從原始盤面可以抵達多少種合法狀態。
> 模 $998\,244\,353$ 輸出。
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

## [Problem J. Jesse's Job](https://contest.ucup.ac/contest/1714/problem/8838)

AC 但不會證明，待補

## [Problem K. Knocker](https://contest.ucup.ac/contest/1714/problem/8839)

待補

## [Problem L. Lalo's Lawyer Lost](https://contest.ucup.ac/contest/1714/problem/8840)

待補
