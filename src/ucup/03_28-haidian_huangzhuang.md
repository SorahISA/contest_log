# The 3rd Universal Cup. Stage 28: Haidian Huangzhuang

- 連結：[https://qoj.ac/contest/1903](https://qoj.ac/contest/1903)
- 時間：2025 Feb 2, 02:00-07:00
- 團隊：ネクロマンサー (SorahISA)
- 成績：0 / 11, Penalty 0, dirt 0% (
  <b style="color:red">A</b>
  <b style="color:red">B</b>
  <b style="color:red">C</b>
  <b style="color:red">D</b>
  <b style="color:red">E</b>
  <b style="color:red">F</b>
  <b style="color:red">G</b>
  <b style="color:red">H</b>
  <b style="color:red">I</b>
  <b style="color:red">J</b>
  <b style="color:red">K</b>
)

感冒所以只打快三個小時，但一題都沒做出來





## [Problem A. Iron Warrior](https://qoj.ac/contest/1903/problem/9690)





## [Problem B. Little, Cyan, Fish!](https://qoj.ac/contest/1903/problem/9691)





## [Problem C. Currency](https://qoj.ac/contest/1903/problem/9692)

##### Tags: `min-cut`

> 有一張 $2 \times n$ 個點的網格圖，點的編號為 $(i, j)$（$1 \le i \le 2$、$1 \le j \le n$），且 $(i, j)$ 跟 $(i', j')$ 之間有一條帶正權無向邊當且僅當 $|i - i'| + |j - j'| = 1$。
> 
> 接著有 $m$ 個限制 $(i, j, c)$，表示若同時走了 $(1, i) \to (1, i+1)$ 跟 $(2, j) \to (2, j+1)$ 兩條邊，則需要花費額外代價 $c$。
> 
> 請求出從 $(1, 1)$ 走到 $(2, n)$ 的最小代價。
> 
> * $n \le 500$、$m \le 1000$、$1 \le$ 權重 $\le 10^9$

網路流最小割經典題。

首先，對每個 $i$，$(1, i) \to (1, i+1)$ 跟 $(2, i) \to (2, i+1)$ 只會走其中恰好一個，否則路徑必然出現環。

因此，對 $(*, i) \to (*, i+1)$ 的邊建立一個點 $i$。令走上方為 $\mathbf{A}$、走下方為 $\mathbf{B}$，則可以建立 $\mathbf{A} \to i$ 跟 $i \to \mathbf{B}$ 的邊並求出 $\mathcal{C} = \min\mathop{\text{cut}}(\mathbf{A}, \mathbf{B})$。如果割掉 $\mathcal{C}$ 之後 $i$ 跟 $\mathbf{A}$ 相連，則代表 $(1, i) \to (1, i+1)$ 這條邊被選擇，反之亦然。

權重的設定也很簡單，$\mathbf{A} \to i$ 的權重就是下方該條邊的權重，$i \to \mathbf{B}$ 的權重就是上方該條邊的權重。會走直線 $(1, i) \leftrightarrow (2, i)$ 的情況只會發生在 $i$ 跟 $i+1$ 不同邊（被切開了），於是可以在 $i \leftrightarrow i+1$ 雙向的建一條邊，權重就是直走邊的權重。不過要注意的是，可能會發生第一條邊走下面或最後一條邊走上面的情況，於是需要將方格左右各拓寬一格，讓 $\mathbf{A} \to 0$ 跟 $n \to \mathbf{B}$ 的權重設為 $\infty$。

最後的 $m$ 個限制，只要建立 $i \to j$ 權重為 $c$ 的單向邊即可。該權重只有在 $i$ 連著 $\mathbf{A}$ 且 $j$ 連著 $\mathbf{B}$ 時才會被計算進去。

於是把 Dinic 模板貼上、按上所述的建好邊、跑 $\mathbf{A} \to \mathbf{B}$ 的最大流即可。





## [Problem D. Widely Known Problem](https://qoj.ac/contest/1903/problem/9693)





## [Problem E. Light Drinking and Low Singing](https://qoj.ac/contest/1903/problem/9694)





## [Problem F. Trash Problem](https://qoj.ac/contest/1903/problem/9695)





## [Problem G. Analysis](https://qoj.ac/contest/1903/problem/9696)





## [Problem H. Algebra](https://qoj.ac/contest/1903/problem/9697)





## [Problem I. Twenty-two](https://qoj.ac/contest/1903/problem/9698)





## [Problem J. Loving You in My Humble Way](https://qoj.ac/contest/1903/problem/9699)





## [Problem K. Ying's Cup](https://qoj.ac/contest/1903/problem/9700)


