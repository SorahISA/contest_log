# The 3rd Universal Cup. Stage 16: Nanjing

- 連結：[https://qoj.ac/contest/1828](https://qoj.ac/contest/1828)
- 時間：2024 Nov 10, 02:00-07:00
- 團隊：ネクロマンサー (SorahISA)
- 成績：4 / 13, Penalty 565, dirt 0% (
  <b style="color:red">A</b>
  <b style="color:lime">B</b>
  <b style="color:red">C</b>
  <b style="color:red">D</b>
  <b style="color:lime">E</b>
  <b style="color:red">F</b>
  <b style="color:red">G</b>
  <b style="color:red">H</b>
  <b style="color:red">I</b>
  <b style="color:lime">J</b>
  <b style="color:lime">K</b>
  <b style="color:red">L</b>
  <b style="color:red">M</b>
)

這場打的太混了 QwQ

整場都沒看計分板，因此一直覺得 L 可做，還有漏掉 G 是二元樹的性質。





## [Problem A. Hey, Have You Seen My Kangaroo?](https://qoj.ac/contest/1828/problem/9564)

待補





## [Problem B. Birthday Gift](https://qoj.ac/contest/1828/problem/9565)

##### Tags: `observation`

> 給定只包含 `012` 的字串 $s$，你可以不斷刪除 **不為** `01` 或 `10` 的 substring，問字串最短長度。
> 
> * 多筆測資、$\sum |s| \le 500\,000$

先考慮只有 `01` 的做法：可以 greedy 的遇到相同字元就刪掉（用 stack 維護）。

在這題也可以用類似的方法，維護把相鄰 `00` 跟 `11` 刪去的字串，會得到被 `2` 切開來，每段都是 `01` 交錯的字串。

而這就可以使用 DP，維護以 `0` 跟 `1` 結尾的字串的所有長度，遇到 `2` 就將其換成 `0` 或 `1`（一樣當遇到連續相同字元就刪掉），因為可以構造出來的長度是連續的，於是可以只維護最小最大值。具體實作可以參考 [submission](https://qoj.ac/submission/734254)。

以下是題解給出的天才解法：

令 $S'$ 為把 $S$ 所有偶數 position 的 `01` 字元反轉形成的字串，那 $S$ 中刪掉 `00` 或 `11` 就會變成 $S'$ 中刪掉 `01` 或 `10`。

一樣先假設沒有 `2` 的情形，可以發現只有當 $S'$ 字串全部字元相同時才不存在 `01` 或 `10`，因此答案就是 $S'$ 中 `0` 跟 `1` 的數量差。

如今我們只在意數量差了，那麼自然有 `2` 就可以往數量少的那邊補，[這份 code](https://qoj.ac/submission/734261) 只有短短 8 行。





## [Problem C. Topology](https://qoj.ac/contest/1828/problem/9566)

待補





## [Problem D. Toe-Tac-Tics](https://qoj.ac/contest/1828/problem/9567)

待補





## [Problem E. Left Shifting 3](https://qoj.ac/contest/1828/problem/9568)

水題，跳過





## [Problem F. Subway](https://qoj.ac/contest/1828/problem/9569)

待補





## [Problem G. Binary Tree](https://qoj.ac/contest/1828/problem/9570)

##### Tags: `interactive`

待補





## [Problem H. Border Jump 2](https://qoj.ac/contest/1828/problem/9571)

待補





## [Problem I. Bingo](https://qoj.ac/contest/1828/problem/9572)

##### Tags: `inclusive-exclusive`, `ntt`

> 給你 $a_1, a_2, \ldots, a_{nm}$，你要將其由左上至右下填入 $n \times m$ 的表格 $G$ 中。定義一個表格的 *bingo 數* 是
> 
> $$\min\left( \min_{1 \le r \le n}\left( \max_{1 \le c \le m}{ G_{r,c} } \right), \min_{1 \le c \le m}\left( \max_{1 \le r \le n}{ G_{r,c} } \right) \right)$$
> 
> 請計算所有 $(nm)!$ 種 $a$ 的排列的 bingo 數之和，模 $998\,244\,353$。
> 
> * $n \cdot m \le 200\,000$

min of max 很不好算，能不能把他換成只有 max 呢？

答案是可以的！用 min-max 排容：

$$
\min_{x \in S} x = \sum_{\emptyset \subsetneq T \subseteq S} (-1)^{|T|+1} \max_{y \in T} y
$$

以上算式的感性證明就是當 max 是第 $k$ 小的時候你有 $2^{k-1}$ 種其他東西的取法，而這些除了在 $k = 1$ 的時候都會正負消掉。

固定 $a_p$ 為 $\max T$，並枚舉 $T$ 中包含了幾個 row max、幾個 column max，可以得到以下算式：

$$
\sum_{p=1}^{nm} a_p \sum_{r=1}^{n}\sum_{c=1}^{m} (-1)^{r+c+1} \binom{n}{r} \binom{m}{c} \binom{p-1}{k-1} k! (nm-k)! \qquad (\text{where } k = rm + cn - rc)
$$

其中 $k$ 代表的是被 $T$ 裡的 row 跟 column 覆蓋的格子數量，max of max 讓我們只需要計算這 $k$ 個格子的 max 恰好是 $a_p$ 的排列數量就好。

直接做是 $\Ord(n^2 m^2)$，得想辦法加速。令

$$
f_k = \sum_{p=1}^{nm} a_p \cdot \binom{p-1}{k-1} \cdot k! \cdot (nm-k)!
$$

那麼答案就是

$$
\sum_{r=1}^{n}\sum_{c=1}^{m} (-1)^{r+c+1} \binom{n}{r} \binom{m}{c} \cdot f_k \qquad (\text{where } k = rm + cn - rc)
$$

把二項式拆開，$f_k$ 可以整理成如下形式，注意下標從 $k$ 開始：

$$
f_k = \sum_{p=\red{k}}^{nm} \frac{a_p \cdot (p-1)! \cdot k \cdot (nm-k)!}{(p-k)!}
$$

把只跟 $k$ 有關的提出來變成 $z_k$，剩下的式子能整理成 $f_k = z_k \cdot \sum_{p=k}^{nm} x_p \cdot y_{p-k}$ 的形式，感覺跟卷積很像了？

- $x_p = a_p \cdot (p-1)!$
- $y_{p-k} = (p-k)!^{-1}$
- $z_k = k \cdot (nm-k)!$

$\Arr{x}, \Arr{y}, \Arr{z}$ 都是能預處理的，於是我們將 $\Arr{x}$ 先 reverse 讓 $\sum$ 裡面變成 $x_{nm-p} \cdot y_{p-k}$ 的形式，讓 $f_k = z_k \cdot (x * y)_{nm-k}$，這題就能開心的用 NTT 解決掉了！

時間複雜度：$\Ord(nm \log(nm))$。





## [Problem J. Social Media](https://qoj.ac/contest/1828/problem/9573)

##### Tags: N/A

水題，跳過





## [Problem K. Strips](https://qoj.ac/contest/1828/problem/9574)

##### Tags: `greedy`

水題，跳過





## [Problem L. $P \oplus Q = R$](https://qoj.ac/contest/1828/problem/9575)

待補





## [Problem M. Ordainer of Inexorable Judgment](https://qoj.ac/contest/1828/problem/9576)

待補

