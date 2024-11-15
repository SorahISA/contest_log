# The 3rd Universal Cup. Stage 14: Harbin

- 連結：[https://qoj.ac/contest/1817](https://qoj.ac/contest/1817)
- 時間：2024 Oct 27, 02:00-07:00
- 團隊：ネクロマンサー (SorahISA)
- 成績：6 / 13, Penalty 774, dirt 0% (
  <b style="color:red">A</b>
  <b style="color:red">B</b>
  <b style="color:lime">C</b>
  <b style="color:red">D</b>
  <b style="color:red">E</b>
  <b style="color:red">F</b>
  <b style="color:lime">G</b>
  <b style="color:red">H</b>
  <b style="color:purple">I</b>
  <b style="color:lime">J</b>
  <b style="color:lime">K</b>
  <b style="color:red">L</b>
  <b style="color:lime">M</b>
)

沒看計分板以為 I 是水題就 AC 了，結果看了記分板之後才發現是測資太爛 + 自己不會估複雜度！？





## [A. Build a Computer](https://qoj.ac/contest/1817/problem/9519)

#### Tags: 

> 請構造一個至多 $100$ 個點的自動機，該自動機需要且只能 accept $[L, R]$ 間數字沒有前導零的二進位表示法。
> 
> - 舉例來說，當 $(L, R) = (3, 5)$ 時，自動機需要且只能接受 $11, 100, 101$ 這三個字串。
> 
> * $1 \le L \le R \le 10^6$，你構造的圖只能有一個起點和一個終點，且不能有環

待補





## [B. Concave Hull](https://qoj.ac/contest/1817/problem/9520)

#### Tags: `convex hull`

> 給定 $n$ 個點，求其所有不是 convex 的 simple polygon 的最大面積 $\times 2$。
> 
> * 多筆測資、$\sum n \le 200\,000$、$|x_i|, |y_i| \le 10^9$、沒有三點共線

待補





## [C. Giving Directions in Harbin](https://qoj.ac/contest/1817/problem/9521)

水題，跳過





## [D. A Simple String Problem](https://qoj.ac/contest/1817/problem/9522)

#### Tags: 

> 題目
> 
> * 測資

待補





## [E. Marble Race](https://qoj.ac/contest/1817/problem/9523)

#### Tags: 

> 題目
> 
> * 測資

待補





## [F. 1D Galaxy](https://qoj.ac/contest/1817/problem/9524)

#### Tags: 

> 題目
> 
> * 測資

待補





## [G. Welcome to Join the Online Meeting!](https://qoj.ac/contest/1817/problem/9525)

#### Tags: 

> 題目
> 
> * 測資

待補





## [H. Subsequence Counting](https://qoj.ac/contest/1817/problem/9526)

#### Tags: 

> 題目
> 
> * 測資

待補





## [I. A Brand New Geometric Problem](https://qoj.ac/contest/1817/problem/9527)

#### Tags: 

> 題目
> 
> * 測資

待補





## [J. New Energy Vehicle](https://qoj.ac/contest/1817/problem/9528)

#### Tags: `greedy`

> 你在一維數線上開車，出發點是座標 $0$，有 $n$ 個油箱分別能裝 $a_1, \ldots, a_n$ 公升的油。有 $m$ 個加油站，第 $j$ 個加油站在座標 $x_j$ 處，並能夠幫你加滿第 $t_j$ 個油箱。你的車每行駛 $1$ 單位距離需要消耗 $1$ 公升的油，問最遠可以開到哪裡（用完油剛好到加油站也可以加油並繼續行駛）。
> 
> * 多筆測資、$\sum n \le 200\,000$、$\sum m \le 200\,000$、$a_i, x_j \le 10^9$

待補





## [K. Farm Management](https://qoj.ac/contest/1817/problem/9529)

#### Tags: 

> 給定 $n$ 個工作 $(\ell_i, r_i, w_i)$ 跟時間 $m$，請找到一個 schedule $\Arr{t}$ 使得
> 
> - $\sum_{i=1}^{n} t_i = m$ 且 $t_i$ 是整數
> - $\ell_i \le t_i \le r_i$
> - $\sum_{i=1}^{n} w_i \cdot t_i$ 收益最大
> 
> 你可以將至多一個工作修改成 $(0, m, w_i)$，求收益最大值。
> 
> * $n \le 10^5$、$m \le 10^{11}$、$w_i \le 10^6$、$\ell_i \le r_i \le 10^6$、$\sum \ell_i \le m \le \sum r_i$

待補





## [L. A Game On Tree](https://qoj.ac/contest/1817/problem/9530)

#### Tags: 

> 題目
> 
> * 測資

待補





## [M. Weird Ceiling](https://qoj.ac/contest/1817/problem/9531)

#### Tags: `math`

> 求
> 
> $$\sum_{i=1}^{n} \frac{n}{ \max\{ k : k \le i \land n \bmod k = 0 \} }$$
> 
> * 測資數量 $\le 1000$、$n \le 10^9$

$\Ord(\sqrt{n})$ 枚舉因數即可。

