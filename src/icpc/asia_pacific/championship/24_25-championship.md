# 2025 ICPC Asia Pacific Championship

- 連結：<https://codeforces.com/contest/2073>
- 時間：2025 Mar 1, 10:00-15:00
- 團隊：NYCU_MyGO!!! (SorahISA, ub33, nella17)
- 成績：7 / 13, Penalty 1025, dirt 50% (
  <b style="color:lime">A</b>
  <b style="color:red">B</b>
  <b style="color:red">C</b>
  <b style="color:lime">D</b>
  <b style="color:red">E</b>
  <b style="color:red">F</b>
  <b style="color:lime">G</b>
  <b style="color:lime">H</b>
  <b style="color:lime">I</b>
  <b style="color:lime">J</b>
  <b style="color:red">K</b>
  <b style="color:lime">L</b>
  <b style="color:red">M</b>
)





## A. Control Towers

##### Tags: `math`

> 給一個 $n \times m$ 的 grid，有些格子不能放置控制塔，請問有多少種放置四座相異控制塔的方法滿足以下條件：
> 
> - 編號 $i$ 跟 $i+1$ 的控制塔需要在同一行或同一列（$i = 1, 2, 3$）。
> 
> * $1 \le n, m \le 2000$

解法





## B. Three-Dimensional Embedding

##### Tags:

> 待補

解法





## C. Cactus Connectivity

##### Tags:

> 待補

解法





## D. Tower of Hanoi

##### Tags:

> 待補

解法





## E. Minus Operator

##### Tags:

> 待補

解法





## F. Hold the Star

##### Tags:

> 待補

解法





## G. Corrupted File

##### Tags: `greedy`

> 給定 $\texttt{01}$-字串 $S$，你可以不斷地選擇相鄰兩個字元合併成一個，合併後的結果是 $\text{AND}$ 操作的值。請問有沒有辦法變成字串 $T$？
> 
> * 多筆測資、$|T| \le |S|$、$\sum |S| \le 100\,000$

首先可以觀察到 $T$ 中的 $\texttt{1}$ 只能是 $S$ 中的 $\texttt{1+}$、$\texttt{0}$ 只能是 $S$ 中的 $\texttt{.}\ast\texttt{0.}\ast$。

將 $S$ 跟 $T$ 以 $\texttt{0}$ 切開後整理成「每段連續 $\texttt{1}$ 的長度」的形式（舉例來說：$\texttt{00111011011}$ 會變成 $[0, 0, 3, 2, 2]$），以下稱之為 $V_S$ 跟 $V_T$。

有幾個邊界 case 需要注意：

1. $|V_T|$ 不能超過 $|V_S|$，因為每個 $T$ 的 $\texttt{0}$ 至少要吃掉一個 $S$ 的 $\texttt{0}$。
2. $V_T[0] \le V_S[0]$ 且 $V_T[-1] \le V_S[-1]$，因為 $T$ 中第一段的 $V_T[0]$ 個 $\texttt{1}$ 只能對上 $S$ 的前面 $V_S[0]$ 個 $\texttt{1}$（$\texttt{1}$ 吃不掉 $\texttt{0}$），最後一段同理。

接著就可以貪心的對 $i = 1, 2, \ldots, |V_T|-2$ 找 $V_S$ 中 $\ge V_T[i]$ 的第一個位置。

- 可以 greedy 匹配的原因是 $T$ 中連續的 $\texttt{1}$ 只會匹配到 $S$ 中連續的 $\texttt{1}$，且對 $i < j$，$T_i$ 匹配到的位置一定在 $T_j$ 匹配到的位置之前。
- 也就是說要找到任意 $1 \le i_1 < i_2 < \cdots < i_{|V_T|-2} \le |V_S|-2$ 滿足 $\forall k.\ V_T[k] \le V_S[i_k]$，是經典的 greedy 問題。





## H. Secret Lilies and Roses

##### Tags: `interactive`, `binary search`

> 有一個隱藏的長度 $n$ 的字串 $S$，其中只包含 $\texttt{L}$ 跟 $\texttt{R}$ 兩種字元。請在 $Q$ 次詢問以內找到一個位置 $p \in [0, n]$ 滿足：
> 
> - 在 $S_1, S_2, \ldots, S_p$ 中的 $\texttt{L}$ 數量（$= \ell_p$）等於在 $S_{p+1}, S_{p+2}, \ldots, S_n$ 中的 $\texttt{R}$ 數量（$= r_p$）。
> 
> 你有兩種詢問操作可以做，分別是：
> 
> 1. 給定 $p \in [1, n]$，詢問 $S_p$。
> 2. 給定 $p \in [0, n]$，詢問 $m_p =_\text{def} \ell_p \times r_p$。
> 
> * 多筆測資、$n \le 100$、$Q = 10$

先觀察到 $c_p =_\text{def} r_p - \ell_p$ 在 $p = 0$ 時會是 $S$ 中 $\texttt{R}$ 的數量，且 $c_{p+1} = c_p - 1$（因為一定是多一個 $\texttt{L}$ 或少一個 $\texttt{R}$）。目標 $c_p = 0$ 的位置就剛好是 $p = \#\texttt{R}$。

如果能戳到第一個 $\texttt{L}$ 或最後一個 $\texttt{R}$ 得到他的 multi，就能直接知道某個 $p$ 的 $c_p$。

觀察 $m_p$ 的性質：他會有一個前綴後綴是 $0$、中間（可能為空）都是非 $0$。

為了得到 $0$ 跟非 $0$ 的交界，我們可以嘗試搜出一個 $\texttt{RL}$ substring，令 $\texttt{R}$ 的位置為 $p^*$，則

- $\ell_{p^*+1}$ 戳在 $\texttt{L}$ 右邊所以是 $\ell_{p^*} + 1$，$m_{p^* + 1} = m_{p^*} + r_{p^*}$；
- $r_{p^*-1}$ 戳在 $\texttt{R}$ 左邊所以是 $r_{p^*} + 1$，$m_{p^* - 1} = m_{p^*} + \ell_{p^*}$。

而要在陣列中搜出 $\texttt{RL}$ substring 是經典題（DOMJudge 測機題），可以用二分搜來做。假設 $S_0 = \texttt{R}$、$S_{n+1} = \texttt{L}$，則可以二分搜尋 $p$ 並更新左右界滿足區間是 $\texttt{R}\ldots\texttt{L}$。

注意特判搜到的 $p^*$ 是 $0$ 或 $n$ 的情況。





## I. Squares on Grid Lines

##### Tags:

> 待補

解法





## J. Gathering Sharks

##### Tags: `dp`

> 待補

經典區間 DP。

令 $\texttt{dp}[\ell][r]$ 表示把編號 $[\ell, r]$ 的人都移到編號 $\ell$ 的位置的最小代價。則有轉移式：

$$
\texttt{dp}[\ell][r] = \min_{\ell \le m < r} \left( \texttt{dp}[\ell][m] + \texttt{dp}[m+1][r] + \lvert \texttt{pos}_{\ell} - \texttt{pos}_{m+1} \rvert \right)
$$

按長度由小至大 DP 即可。





## K. Book Sorting

##### Tags:

> 待補

解法





## L. Boarding Queue

##### Tags: N/A

> 待補

對所有相鄰兩人 $(a, b)$ 檢查：如果 $a \le p$ 代表 $p$ 會走到 $a$ 的位置，面對的是 $b+p-a$，判斷該數字有沒有在 $[1, n]$ 即可。





## M. Can You Reach There?

##### Tags:

> 待補

解法




