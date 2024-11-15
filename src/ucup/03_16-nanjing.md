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

待補

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

