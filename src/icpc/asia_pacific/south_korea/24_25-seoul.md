# 2024 ICPC Asia Seoul Regional Programming Contest

- 連結：<https://www.acmicpc.net/category/detail/4348>
- 時間：2024 Nov 17, 09:30-14:30
- 團隊：ネクロマンサー (SorahISA)
- 成績：4 / 12, Penalty 185, dirt 33% (
  <b style="color:lime">A</b>
  <b style="color:lime">B</b>
  <b style="color:red">C</b>
  <b style="color:red">D</b>
  <b style="color:red">E</b>
  <b style="color:red">F</b>
  <b style="color:red">G</b>
  <b style="color:red">H</b>
  <b style="color:red">I</b>
  <b style="color:lime">J</b>
  <b style="color:red">K</b>
  <b style="color:lime">L</b>
)





## A. Bottles

##### Tags: `prefix sum`

> 有 $n$ 個人在比賽，編號為 $i$ 的人會在時間 $0$ 從區域 $1$ 出發，在時間 $\sum_{k=1}^{j} t_{i,k}$ 抵達區域 $j+1$。
> 
> 在不考慮整數點時間的情況下，請問每個區域最多同時有多少人？
> 
> * $n \le 100$、$m \le 300$、$t_{i,j} \le 10\,000$

水題，跳過





## B. Cards Flipping

##### Tags: N/A

> 給定兩個長度 $n$ 的序列 $\Arr{a}, \Arr{b}$，請對每個 $i$ 選擇 $c_i := a_i$ 或 $c_i := b_i$ 使得 $\lvert \{ c_i \} \rvert$ 最大。
> 
> * $n \le 200\,000$、$0 \le a_i, b_i \le 1\,000\,000$

建圖，建了 $(a_i, b_i)$ 的邊之後相當於是要對每條邊選周圍的一個點。

觀察到如果一個大小為 $k$ 的連通塊是樹，那麼隨意定根並讓所有邊選擇較低的點就能做到 $k-1$。

如果該連通塊有至少 $k$ 條邊，那麼可以把邊拔到剩下 $k$ 條變成基環樹，讓環上的邊互指，樹上的邊往下指就能做到 $k$。

用 DSU 維護連通塊大小以及邊的數量即可，時間複雜度 $\Ord(n \alpha(n))$。





## C. Colorful Quadrants

##### Tags:

> meow
> 
> * meow

待補





## D. Ladder Update

##### Tags:

> meow
> 
> * meow

待補





## E. Mausoleum

##### Tags:

> meow
> 
> * meow

待補





## F. Pair Sorting

##### Tags:

> meow
> 
> * meow

待補





## G. Palindromic Length

##### Tags:

> meow
> 
> * meow

待補





## H. Protecting Kingdom

##### Tags:

> meow
> 
> * meow

待補





## I. Square Stamping

##### Tags:

> meow
> 
> * meow

待補





## J. Street Development

##### Tags:

> meow
> 
> * meow

待補





## K. String Rank

##### Tags:

> meow
> 
> * meow

待補





## L. Triangle

##### Tags: N/A

> 給定一個頂點都在整數點的三角形 $\triangle ABC$，請求出在三條邊 $\overline{AB}, \overline{BC}, \overline{CA}$ 上各選一個整數點（不含頂點）圍成三角形的最大面積 $S_\text{max}$ 以及最小面積 $S_\text{min}$。
> 
> 輸出 $2 \cdot S_\text{max}, 2 \cdot S_\text{min}$ 即可，如果無解請輸出 $-1$。
> 
> * $\lvert\!$ 座標 $\!\rvert$ $\le 10^9$

顯然最大面積就是三角形的面積，但不能取頂點，所以要想辦法取盡量靠近的點；最小面積就是三條邊的中點連線，但中點不一定是整數點，所以要找到最接近的整數點。

$\overline{AB}$ 上的所有點會是 $\left( A_x + k \cdot \frac{B_x - A_x}{d}, A_y + k \cdot \frac{B_y - A_y}{d} \right)$ 的形式（其中 $0 \le k \le d$ 且 $k, d$ 都是整數），而要滿足他是整數點就必須滿足 $d \mid (B_x - A_x)$ 且 $d \mid (B_y - A_y)$，所以取 $d = \gcd(B_x - A_x, B_y - A_y)$。

於是就可以在三條邊上分別取 $k = 1, \floor{d/2}, \ceil{d/2}, d-1$ 四個點計算三角形面積即可。

時間複雜度 $\Ord(4^3)$。
