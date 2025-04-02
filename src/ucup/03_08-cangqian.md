# The 3rd Universal Cup. Stage 8: Cangqian

- 連結：[https://qoj.ac/contest/1780](https://qoj.ac/contest/1780)
- 時間：2025 Apr 2, 07:00-12:00
- 團隊：SorahISA
- 成績：5 / 13, Penalty 596, dirt 44% (
  <b style="color:red">A</b>
  <b style="color:red">B</b>
  <b style="color:lime">C</b>
  <b style="color:red">D</b>
  <b style="color:lime">E</b>
  <b style="color:lime">F</b>
  <b style="color:red">G</b>
  <b style="color:red">H</b>
  <b style="color:red">I</b>
  <b style="color:lime">J</b>
  <b style="color:red">K</b>
  <b style="color:red">L</b>
  <b style="color:lime">M</b>
)

在 A 大坐牢，寫了 python 不知道為什麼會 RE 卡了一個小時。





## [Problem A. Bingo](https://qoj.ac/contest/1780/problem/8932)

待補





## [Problem B. Simulated Universe](https://qoj.ac/contest/1780/problem/8933)

待補





## [Problem C. Challenge NPC](https://qoj.ac/contest/1780/problem/8934)

##### Tags: `constructive`

> 構造一張簡單無向圖 $G$ 使得存在一個正整數 $c$ 滿足最小點著色數 $\le c$ 且 greedy 解至少要用 $c + k$ 個顏色。
> 
> - Greedy 解：對 $i = 1, 2, \ldots, n$，將點 $i$ 著 $\mex\{ c_u : u < i \land (u, i) \in E(G) \}$ 的顏色（此處的 $\mex$ 為 $1$-based）。
> 
> * $k \le 500$、$n \le 1024$

$k$ 這麼大，感覺就可以弄一張二分圖做到 $2$ 跟 $n/2$，所以就做完了。

只要把第 $k$ 小的奇數／偶數連向第 $1, 2, \ldots, k-1$ 小的偶數／奇數就可以了。

- 因為是二分圖，所以最佳解顯然是 $2$。
- 第 $k$ 小的奇數／偶數會被 greedy 解填上顏色 $k$。





## [Problem D. Puzzle: Easy as Scrabble](https://qoj.ac/contest/1780/problem/8935)

待補





## [Problem E. Team Arrangement](https://qoj.ac/contest/1780/problem/8936)

##### Tags: `greedy`, `bit operation`

> 要把 $n$ 個人分成若干組，第 $i$ 個人希望自己在的小組有 $[\ell_i, r_i]$ 個人。如果一種分組方法每一組分別有 $c_1, c_2, \ldots, c_k$ 個人，那麼總價值就是 $\sum\limits_{j=1}^{k} w_{c_j}$。
> 
> 請求出最大價值的分組，或判斷其不可能達成。
> 
> * $n \le 60$、$|w_i| \le 10^7$

第一直覺是先枚舉每一組的大小，再判斷該分組能不能被達成。$n$ 個人的分組數量是 $p(n)$，而 $p(60) = 966\,467$，於是大概要一個 $\Ord(n)$ 的方法來判斷。

最簡單的方法是 greedy：先將區間們依照右界小到大排序，再每次取 $\ell_i$ 的 lower bound 出來。用 multiset 果不其然的吃了 TLE，改成 map 之後有稍微改善，但複雜度仍然有一個 $\log n$。

注意到這題 $n \le 60$，每一組的大小也只有 $60$ 以下，可以用一個 `uint64_t` 來儲存！

- 跟用 map 的做法一樣，存在 $x$ $\Longleftrightarrow$ `(val >> x) & 1`。
- 求 $\ell$ 的 lower bound 可以用 `__builtin_ctzll(val >> l << l)` 來做，這樣就可以在 $\Ord(1)$ 的時間內找到。
  - 注意 `__builtin_ctzll(0)` 會是 undefined behavior，可以特判，或是一開始就放 `1 << (n+1)` 進 `val` 裡面。

於是這樣的複雜度就變成 $\Ord(p(n) \cdot n^2 / w) = \Ord(p(n) \cdot n)$ 了。





## [Problem F. Stage: Agausscrab](https://qoj.ac/contest/1780/problem/8937)

水題，跳過





## [Problem G. Crawling on a Tree](https://qoj.ac/contest/1780/problem/8938)

待補





## [Problem H. Permutation](https://qoj.ac/contest/1780/problem/8939)

待補





## [Problem I. Piggy Sort](https://qoj.ac/contest/1780/problem/8940)

待補





## [Problem J. Even or Odd Spanning Tree](https://qoj.ac/contest/1780/problem/8941)

##### Tags: `mst`, `lca`

> 給一張帶正邊權的 $n$ 點 $m$ 邊無向圖 $G$，求 weight 分別是奇數跟偶數的最小生成樹，輸出 weight 即可（不存在則輸出 $-1$）。
> 
> * 多筆測資、$\sum n \le 200\,000$、$\sum m \le 500\,000$

顯然有一邊的答案就是 MST 本身。

- $\Claim{1}$ 令 $f(k)$ 是選了 $k$ 條奇邊的最小生成樹 weight，如果最小生成樹選了 $a$ 條奇邊，那答案一定是 $f(a-1)$ 或 $f(a+1)$。

<details><summary><i>Proof</i></summary>

根據經典 Aliens 題「黑白生成樹」可以證明 $f$ 有凸性。

</details>

- $\Claim{2}$ 要得到 $f(a \pm 1)$ 只要枚舉樹外邊 $(u, v)$ 跟 $u \leadsto v$ 路徑上奇偶性相異的最大值換就好。

<details><summary><i>非常不嚴謹的 Proof</i></summary>

隨意抓一棵最小生成樹 $T$，其權重是 $f(a) = \min\limits_{0 \le i \le n-1}{f(i)}$。

考慮原本 $T$ 中 $u \leadsto v$ 路徑上的一條邊 $e_1 = (a_{11}, a_{12}, w_1)$ 被拔掉，替換成 $e_2 = (a_{21}, a_{22}, w_2)$，從而使 $e_3 = (a_{31}, a_{32}, w_3)$ 這條邊成為 $u \leadsto v$ 路徑的新最大值。把 $e_2$ 邊加進來之後的 $T'$ 會變成一棵基環樹，環上包含 $e_1, e_2, e_3$ 三條邊跟其他一些邊。

這樣做會使答案變好的條件是 $(e_3 - e_1) - (e_2 - e_1) > 0 \implies e_3 > e_2$，但這種情況下 $T - e_3 + e_2$ 會是權重更小的 MST，與原假設不符。

應該可以推廣到替換任意條邊的情況，但我推不出來。

順帶一提，官解用「這是擬陣的性質」一筆帶過，但我不熟擬陣不會證。有機會再補證明。

</details>

於是只要用 LCA 維護路徑上的奇數 weight、偶數 weight 最大值是多少就可以了。

時間複雜度：$\Ord(m \log n)$。





## [Problem K. Sugar Sweet 3](https://qoj.ac/contest/1780/problem/8942)

待補





## [Problem L. Challenge Matrix Multiplicatio](https://qoj.ac/contest/1780/problem/8943)

待補





## [Problem M. Triangles](https://qoj.ac/contest/1780/problem/8944)

待補


