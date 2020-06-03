# Reference

+ https://qiita.com/drken/items/e77685614f3c6bf86f44
+ https://qiita.com/drken/items/2f56925972c1d34e05d8
+ http://www.graco.c.u-tokyo.ac.jp/icpc-challenge/wp-content/uploads/2014/12/2014.pdf
+ https://qiita.com/e869120/items/eb50fdaece12be418faa -> [problems & answers](https://github.com/knknkn1162/blue_e869120_100)
+ https://qiita.com/e869120/items/acba3dd8649d913102b5

# problems

|TODO|idx|type|問題名|難易度|備考|方針/解答例|
|---|---|---|---|---|---|---|
|o|§ 1.1.1|example|くじ引き|||[半分全列挙]()|
||§ 1.1.1|exercise|[JOI 2007 本選 C ダーツ](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c)|||see § 3.1.1|
||§ 1.2.1|exercise|[ABC 128 B - Guidebook](https://atcoder.jp/contests/abc128/tasks/abc128_b)|||[qsort](https://atcoder.jp/contests/abc128/submissions/13587446)|
||§ 1.6.1|example|三角形|||[降順にソート-> 連続した3つを調べる](./1.6.1/triangle.c)|
||§ 1.6.1|exercise|[ABC 121 C - Energy Drink Collector](https://atcoder.jp/contests/abc121/tasks/abc121_c)|||[安い順にソート](https://atcoder.jp/contests/abc121/submissions/13685701)|
||§ 1.6.1|example|[ABC 115 C - Christmas Eve](https://atcoder.jp/contests/abc115/tasks/abc115_c)|||[ソート](https://atcoder.jp/contests/abc115/submissions/13676383)|
||§ 1.6.2|example|[ABC 169 C - Multiplication 3](https://atcoder.jp/contests/abc169/tasks/abc169_c)|||[100倍して整数として計算](https://atcoder.jp/contests/abc169/submissions/13939660)|
||§ 1.6.2|exercise|[Cable Master (POJ No.1064)](http://poj.org/problem?id=1064)|||see § 3.1.2|
||§ 1.6.2|exercise|[C - Sqrt Inequality](https://atcoder.jp/contests/panasonic2020/tasks/panasonic2020_c)|||[2乗して整数の形に](https://atcoder.jp/contests/panasonic2020/submissions/13942134)|
||§ 1.7.1|exercise|[C - Dice and Coin](https://atcoder.jp/contests/abc126/tasks/abc126_c)|||[確率](https://atcoder.jp/contests/abc126/submissions/13467645)|
||§ 1.8.1|exercise|[ABC 106 C - To Infinity](https://atcoder.jp/contests/abc106/tasks/abc106_c)|||[実装問題](https://atcoder.jp/contests/abc106/submissions/13744106)|
||§ 1.8.1|exercise|[AOJ 1193 - 連鎖消滅パズル](https://onlinejudge.u-aizu.ac.jp/problems/1193)|||[落ちゲー、実装問題、解くだけ](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1193/review/4320693/knknkn1162/C)|
||§ 1.8.1|exercise|[ABC 107 B - Grid Compression](https://atcoder.jp/contests/abc107/tasks/abc107_b)|||[実装問題](https://atcoder.jp/contests/abc107/submissions/13689326)|
||§ 1.8.1|exercise|[Square869120Contest #3 B - 石落としゲーム](https://atcoder.jp/contests/s8pc-3/tasks/s8pc_3_b)|||[落ちゲー, 実装問題、(WIDTH)×(HEIGHT-1)個シュミレート](https://atcoder.jp/contests/s8pc-3/submissions/11477560)|
||§ 1.8.1|exercise|[ABC 109 D - Make Them Even](https://atcoder.jp/contests/abc109/tasks/abc109_d)|||[構成問題、問題文を解釈、実装問題, 右端に寄せる](https://atcoder.jp/contests/abc109/submissions/13685267)|
||§ 1.8.1|exercise|[ABC 128 D - equeue](https://atcoder.jp/contests/abc128/tasks/abc128_d)|||[実装問題、シュミレート](https://atcoder.jp/contests/abc128/submissions/13589023)|
||§ 1.8.1|exercise|[ABC 090 D - Remainder Reminder](https://atcoder.jp/contests/abc090/tasks/arc091_b)|||[実装問題、K=0と≠0で場合分け](https://atcoder.jp/contests/abc090/submissions/13964782)|
||§ 1.8.1|exercise|[AOJ 1149 - ケーキカット](https://onlinejudge.u-aizu.ac.jp/problems/1149)|||[実装問題、連結リスト](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1149/review/4321489/knknkn1162/C)|
||§ 1.8.2|exercise|[ABC 092 D - Grid Components](https://atcoder.jp/contests/abc092/tasks/arc093_b)|||[構成問題、発想問題(パズル)](https://atcoder.jp/contests/abc092/submissions/13970569)|
||§ 1.9.1|exercise|[ALDS1_1_D 最大の利益](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_D)|||[min, maxを用いて適宜更新](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_1_D/review/4513248/knknkn1162/C)|
||§ 1.9.1|exercise|[ABC 107 C - Candles](https://atcoder.jp/contests/abc107/tasks/arc101_a)|||[長さKの区間を固定して,max,min使用](https://atcoder.jp/contests/abc107/submissions/13697949)|
||§ 1.9.1|exercise|[ABC 117 D - XXOR](https://atcoder.jp/contests/abc117/tasks/abc117_d)|||[maxを用いて適宜更新](https://atcoder.jp/contests/abc117/submissions/13596002)|
||§ 1.9.1|exercise|[ABC 102 C - Linear Approximation](https://atcoder.jp/contests/abc102/tasks/arc100_a)|||[中央値](https://atcoder.jp/contests/abc102/submissions/13756922)|
||§ 1.9.1|exercise|[ABC 094 C - Many Medians](https://atcoder.jp/contests/abc094/tasks/arc095_a)|||[中央値、ソート](https://atcoder.jp/contests/abc094/submissions/13910628)|
||§ 1.9.1|exercise|[Square869120Contest #6 B - AtCoder Markets](https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b)|||中央値。see §2.2.4|
||§ 2.1.0|exercise|[ABC 114 C - 755](https://atcoder.jp/contests/abc114/tasks/abc114_c)|||[再帰関数](https://atcoder.jp/contests/abc114/submissions/13677743)|
||§ 2.1.0|exercise|[ABC 161 D - Lunlun Number](https://atcoder.jp/contests/abc161/tasks/abc161_d)|||[再帰関数で条件を満たす数をstackに](https://atcoder.jp/contests/abc161/submissions/13688600)|
||§ 2.1.1|example|部分和問題|||[]()|
||§ 2.1.1|exercise|[B - Sum of Three Integers](https://atcoder.jp/contests/abc051/tasks/abc051_b)|||[全探索]() or [DP, 累積和](https://atcoder.jp/contests/abc051/submissions/12543729)|
||§ 2.1.1|exercise|[ABC 166 D - I hate Factorization](https://atcoder.jp/contests/abc166/tasks/abc166_d)|||[上限決めて全探索](https://atcoder.jp/contests/abc166/submissions/13701621)|
||§ 2.1.1|exercise|[ABC 112 C - Pyramid](https://atcoder.jp/contests/abc112/tasks/abc112_c)|||[解を仮定して全探索](https://atcoder.jp/contests/abc112/submissions/13678639)|
|o|§ 2.1.1|exercise|[ABC 088 C - Takahashi's Information](https://atcoder.jp/contests/abc088/tasks/abc088_c)|||[解を仮定して全探索]()|
||§ 2.1.1|exercise|[ARC 029 A - 高橋君とお肉](https://atcoder.jp/contests/arc029/tasks/arc029_1)|||[bit全探索](https://atcoder.jp/contests/arc029/submissions/8502963)|
||§ 2.1.1|exercise|[ABC 167 C - Skill Up](https://atcoder.jp/contests/abc167/tasks/abc167_c)|||[bit全探索](https://atcoder.jp/contests/abc167/submissions/13454752)|
||§ 2.1.1|exercise|[ABC 119 C - Synthetic Kadomatsu](https://atcoder.jp/contests/abc119/tasks/abc119_c)|||[`4**num`のbit全探索](https://atcoder.jp/contests/abc119/submissions/13564242)|
|o|§ 2.1.2|example|[Lake Counting (POJ No.2386)](http://poj.org/problem?id=2386)|||[]()|
|o|§ 2.1.3|exercise|迷路の最短路|||[BFS]()|
||§ 2.1.3|exercise|[E - チーズ (Cheese)](https://atcoder.jp/contests/joi2011yo/tasks/joi2011yo_e)|||[BFS](https://atcoder.jp/contests/joi2011yo/submissions/11007756)|
|o|§ 2.1.3|exercise|[ARC 005 C 器物損壊！高橋君](https://atcoder.jp/contests/arc005/tasks/arc005_3)|||[0-1 BFS](https://atcoder.jp/contests/arc005/submissions/8570403) or [Dijkstra]() or [dequeue]()|
||§ 2.1.4|example|特別な状態の列挙|||[next_permutationの実装](./2.1.4/)|
|o|§ 2.1.4|exercise|[AOJ ITP2_5_C Permutation](https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_5_C)|||[next_permutationの実装]()|
|o|§ 2.1.4|exercise|[AOJ ITP2_5_D Permutation Enumeration](https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_5_D)|||[permutation]()|
||§ 2.1.4|exercise|[ABC 167 D - Teleporter](https://atcoder.jp/contests/abc167/tasks/abc167_d)|||[permutation](https://atcoder.jp/contests/abc167/submissions/13702242)|
||§ 2.1.4|exercise|[ABC 054 C One-stroke Path](https://atcoder.jp/contests/abc054/tasks/abc054_c)|||[順列全探索](https://atcoder.jp/contests/abc054/submissions/12291613)|
||§ 2.1.4|exercise|[JOI 2009 予選 D カード並べ](https://atcoder.jp/contests/joi2010yo/tasks/joi2010yo_d)|||[bit全探索、順列全探索](https://atcoder.jp/contests/joi2010yo/submissions/12296618)|
|o|§ 2.1.4|exercise|[yukicoder No.133 カードゲーム](https://yukicoder.me/problems/199)||||
||§ 2.1.4|exercise|[Enumeration of Subsets I](https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_A)|||[bit列挙](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ITP2_11_A/review/4433122/knknkn1162/C)|
||§ 2.1.4|exercise|[Enumeration of Subsets II](https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_B)|||[bit列挙](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ITP2_11_B/review/4433178/knknkn1162/C)|
||§ 2.1.4|exercise|[Enumeration of Subsets III](https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/all/ITP2_11_C)|||[bit列挙](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ITP2_11_C/review/4433193/knknkn1162/C)|
||§ 2.1.4|exercise|[Enumeration of Combinations](https://onlinejudge.u-aizu.ac.jp/problems/ITP2_11_D)|||[組み合わせのbit全列挙](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ITP2_11_D/review/4433226/knknkn1162/C)|
||§ 2.1.4|exercise|[C - Many Requirements](https://atcoder.jp/contests/abc165/tasks/abc165_c)|||[発想問題、組み合わせの列挙](https://atcoder.jp/contests/abc165/submissions/12851420)|
|o|§ 2.1.4|exercise|[C - Numbering Blocks](https://atcoder.jp/contests/judge-update-202004/tasks/judge_update_202004_c)|||[組み合わせの列挙 -> 全探索]()|
||§ 2.1.4|exercise|[B - Buildings are Colorful!](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_b)|||[組み合わせの列挙 -> 全探索](https://atcoder.jp/contests/s8pc-4/submissions/10738108)|
||§ 2.2.1|example|硬貨の問題|||[]()|
||§ 2.2.1|exercise|[C - Strange Bank](https://atcoder.jp/contests/abc099/tasks/abc099_c)|||[貰うDP](https://atcoder.jp/contests/abc099/submissions/13764174) or [配るDP](https://atcoder.jp/contests/abc099/submissions/13765196)|
||§ 2.2.2|example|区間スケジューリング問題|||[end起点に昇順](./2.2.2/scheduling.c)|
||§ 2.2.2|exercise|[ALDS1_15_C 活動選択問題](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_15_C)|||[end起点に昇順](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_15_C/review/4495678/knknkn1162/C)|
||§ 2.2.2|exercise|[B - Robot Arms](https://atcoder.jp/contests/keyence2020/tasks/keyence2020_b)|||[end起点に昇順](https://atcoder.jp/contests/keyence2020/submissions/12551527)|
||§ 2.2.2|exercise|[A - 東京都](https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a)|||[前から探索](https://atcoder.jp/contests/kupc2015/submissions/12313760)|
||§ 2.2.2|exercise|[C - 白昼夢](https://atcoder.jp/contests/abc049/tasks/arc065_a)|||[後ろから](https://atcoder.jp/contests/abc049/submissions/12314491)|
||§ 2.2.2|exercise|[D - Islands War](https://atcoder.jp/contests/abc103/tasks/abc103_d)|||[start起点にソート->貪欲法](https://atcoder.jp/contests/abc103/submissions/12316726)|
||§ 2.2.2|exercise|[B. Clique Problem](http://codeforces.com/contest/528/problem/B)|||[区間スケジューリング問題に帰着](http://codeforces.com/contest/528/submission/78082567)|
||§ 2.2.3|example|[Best Cow Line](http://poj.org/problem?id=3617)|||[予め反転した文字列も用意して貪欲法](./2.2.3/poj3617.c)|
||§ 2.2.3|exercise|[C - Dubious Document 2](https://atcoder.jp/contests/abc076/tasks/abc076_c)|||[後ろから走査](https://atcoder.jp/contests/abc076/submissions/12324748)|
||§ 2.2.3|exercise|[B - 辞書式順序](https://atcoder.jp/contests/abc007/tasks/abc007_2)|||['a' or -1を出力](https://atcoder.jp/contests/abc007/submissions/12324882)|
|o|§ 2.2.3|exercise|[C - 辞書式順序ふたたび](https://atcoder.jp/contests/abc009/tasks/abc009_3)|||[]()|
||§ 2.2.3|exercise|[ABC 160 E - Red and Green Apples](https://atcoder.jp/contests/abc160/tasks/abc160_e)|||[ソート -> 貪欲法](https://atcoder.jp/contests/abc160/submissions/11773599)|
||§ 2.2.4|example|[Saruman's Army](http://poj.org/problem?id=3069)|||[昇順にソート->貪欲](./2.2.4/poj3069.c)|
||§ 2.2.4|exercise|[Square869120Contest #6 B - AtCoder Markets](https://atcoder.jp/contests/s8pc-6/tasks/s8pc_6_b)|||[発想問題、全探索(要工夫),中央値](https://atcoder.jp/contests/s8pc-6/submissions/10662359)|
||§ 2.2.4|exercise|[ABC 107 C - Candles](https://atcoder.jp/contests/abc107/tasks/arc101_a)|||see §1.9.1|
||§ 2.2.4|exercise|[ABC 117 C - Streamline](https://atcoder.jp/contests/abc117/tasks/abc117_c)|||[発想問題、区間のソート -> 貪欲](https://atcoder.jp/contests/abc117/submissions/13594719)|
||§ 2.2.4|exercise|[ABC 100 D - Patisserie ABC](https://atcoder.jp/contests/abc100/tasks/abc100_d)|||[発想問題、符号決め打ちでソート](https://atcoder.jp/contests/abc100/submissions/13889053)|
|o|§ 2.2.4|exercise|[ABC 123 D - Cake 123](https://atcoder.jp/contests/abc123/tasks/abc123_d)|||[解の候補を絞ってソート](https://atcoder.jp/contests/abc123/submissions/13557424) or [priority queue]() or [二分探索]()|
||§ 2.2.4|exercise|[C - K-th Substring](https://atcoder.jp/contests/abc097/tasks/arc097_a)|||[解の候補を絞ってソート](https://atcoder.jp/contests/abc097/submissions/13911362)|
||§ 2.2.4|exercise|[ABC 153 F - Silver Fox vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_f)|||see § 3.3.1|
||§ 2.2.4|exercise|[有理ナップサック問題](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_15_B)|||[貪欲法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_15_B/review/3980743/knknkn1162/C)|
||§ 2.2.4|exercise|[C - Multiple Gift](https://atcoder.jp/contests/abc083/tasks/arc088_a)|||[貪欲](https://atcoder.jp/contests/abc083/submissions/12356089)|
||§ 2.2.4|exercise|[C - 積み重ね](https://atcoder.jp/contests/arc006/tasks/arc006_3)|||[無駄が出ないように貪欲で](https://atcoder.jp/contests/arc006/submissions/12377963)|
||§ 2.2.4|exercise|[E - Colorful Hats 2](https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_e)|||[貪欲法](https://atcoder.jp/contests/sumitrust2019/submissions/11699547)|
|o|§ 2.2.4|exercise|[ABC 091 C - 2D Plane 2N Points](https://atcoder.jp/contests/abc091/tasks/arc092_a)|||[発想難、min(青のx座標)とmax(赤のy座標)を対応して貪欲法](https://atcoder.jp/contests/abc091/submissions/13956198) or [最大マッチング問題]()|
||§ 2.2.4.1|exrcise|[ALDS_1_4_B 二分探索](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_B)|||[ソート -> 尺取法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_4_B/review/4514396/knknkn1162/C)|
||§ 2.2.4.1|exercise|[C - おいしいたこ焼きの売り方](https://atcoder.jp/contests/abc005/tasks/abc005_3)|||[客を軸にして、尺取法っぽく](https://atcoder.jp/contests/abc005/submissions/13617416)|
||§ 2.2.4.1|exercise|[ABC 116 C - Grand Garden](https://atcoder.jp/contests/abc116/tasks/abc116_c)|||[貪欲、尺取法っぽく](https://atcoder.jp/contests/abc116/submissions/13607638)|
|o|§ 2.2.4.1|exercise|[ABC 102 D - Equal Cut](https://atcoder.jp/contests/abc102/tasks/arc100_b)|||[真ん中に区切る->最初の区切り方を尺取法で]()|
||§ 2.2.5|example|[POJ 3253 Fence Repair](http://poj.org/problem?id=3253)|||[priority queue, 型に注意](./2.2.5/poj3253.c)|
|o|§ 2.2.5|exercise|[C. Appleman and Toastman](http://codeforces.com/contest/462/problem/C)|||[]()|
||§ 2.2.5|exercise|[ALDS1_15_D ハフマン符号](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_15_D)|||[最小ヒープ, DFS](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_15_D/review/4495500/knknkn1162/C)|
||§ 2.2.6|exercise|[ABC 122 C - GeT AC](https://atcoder.jp/contests/abc122/tasks/abc122_c)|||[累積和](https://atcoder.jp/contests/abc122/submissions/13557759)|
||§ 2.2.6|exercise|[ABC 092 C - Traveling Plan](https://atcoder.jp/contests/abc092/tasks/arc093_a)|||[累積和](https://atcoder.jp/contests/abc092/submissions/13956843)|
||§ 2.2.6|exercise|[ABC 099 D - Good Grid](https://atcoder.jp/contests/abc099/tasks/abc099_d)|||前処理(map) see § 2.4.2|
||§ 2.2.6|exercise|[ABC 089 D - Practical Skill Test](https://atcoder.jp/contests/abc089/tasks/abc089_d)|||[前処理(累積和)](https://atcoder.jp/contests/abc089/submissions/13964940)|
||§ 2.2.6|exercise|[ABC 125 C - GCD on Blackboard](https://atcoder.jp/contests/abc125/tasks/abc125_c)|||[累積和、逆累積和](https://atcoder.jp/contests/abc125/submissions/13928488)|
||§ 2.2.6|exercise|[ABC 095 D - Static Sushi](https://atcoder.jp/contests/abc095/tasks/arc096_b)|||[環状、累積和、逆累積和](https://atcoder.jp/contests/abc095/submissions/13928203)|
||§ 2.2.6|exercise|[JOI 2011 本選 1 - 惑星探査](https://atcoder.jp/contests/joi2011ho/tasks/joi2011ho1)|||[二次元累積和](https://atcoder.jp/contests/abc106/submissions/11348226) or [区間DP](https://atcoder.jp/contests/abc106/submissions/11346781)|
||§ 2.2.6|exercise|[ABC 147 D - Xor Sum 4](https://atcoder.jp/contests/abc147/tasks/abc147_d)|||[xorの性質を利用して累積和](https://atcoder.jp/contests/abc147/submissions/13149768)|
||§ 2.2.6|exercise|[DSL_5_A The Maximum Number of Customers](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_5_A)|||[いもす法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_5_A/review/4467956/knknkn1162/C)|
||§ 2.2.6|exercise|[DSL_5_B The Maximum Number of Overlaps](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_5_B)|||[いもす法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_5_B/review/4467993/knknkn1162/C)|
||§ 2.2.6|exercise|[AtCoder Beginner Contest 014 C - AtColor](https://atcoder.jp/contests/abc014/tasks/abc014_3)|||[いもす法](https://atcoder.jp/contests/abc014/submissions/11362928)|
||§ 2.2.6|exercise|[AOJ 2013 - 大崎](https://onlinejudge.u-aizu.ac.jp/problems/2013)|||[いもす法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/2013/review/4306854/knknkn1162/C)|
||§ 2.2.6|exercise|[JOI 2015 本選 1 - 鉄道運賃](https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_a)|||[いもす法、添字に注意](https://atcoder.jp/contests/joi2015ho/submissions/11370150)|
||§ 2.2.6|exercise|[JOI 2010 本選 1 - 旅人](https://atcoder.jp/contests/joi2010ho/tasks/joi2010ho_a)|||[累積和, 添字に注意](https://atcoder.jp/contests/joi2010ho/submissions/11338148) or [いもす法](https://atcoder.jp/contests/joi2010ho/submissions/11746886)|
||§ 2.2.6|exercise|[JOI 2012 本選 4 - 釘](https://atcoder.jp/contests/joi2012ho/tasks/joi2012ho4)|||[いもす法, 3階差分](https://atcoder.jp/contests/joi2012ho/submissions/11421264)|
||§ 2.3.1|example|[0-1ナップザック問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_B)|||[DP(引き継ぎ有り)](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_B/review/4508309/knknkn1162/C)|
||§ 2.3.1|exercise|[TDPC A コンテスト](https://atcoder.jp/contests/tdpc/tasks/tdpc_contest)|||[DP](https://atcoder.jp/contests/tdpc/submissions/12701720)|
||§ 2.3.1|exercise|[ABC 115 D - Christmas](https://atcoder.jp/contests/abc115/tasks/abc115_d)|||[DP](https://atcoder.jp/contests/abc115/submissions/13677608)|
||§ 2.3.1|exercise|[D - 高橋くんの苦悩](https://atcoder.jp/contests/abc015/tasks/abc015_4)|
||§ 2.3.1|exercise|[JOI 2012 予選 D 暑い日々](https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_d)|||[DP](https://atcoder.jp/contests/joi2013yo/submissions/11071917)|
||§ 2.3.1|exercise|[JOI 2012 予選 4 - パスタ](https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_d)|||[DP, 三項間漸化式](https://atcoder.jp/contests/joi2012yo/submissions/11063373)|
||§ 2.3.1|exercise|[E - Active Infants](https://atcoder.jp/contests/abc163/tasks/abc163_e)|||[ソート, DP](https://atcoder.jp/contests/abc163/submissions/12805226)|
|o|§ 2.3.1|exercise|[TDPC E 数](https://atcoder.jp/contests/tdpc/tasks/tdpc_number)|||[]()|
||§ 2.3.1|exercise|[Educational DP Contest S - Digit Sum](https://atcoder.jp/contests/dp/tasks/dp_s)|||[桁DP](https://atcoder.jp/contests/dp/submissions/12427694)|
||§ 2.3.1|exercise(digit)|[D - 禁止された数字](https://atcoder.jp/contests/abc007/tasks/abc007_4)|||[桁を文字列とみなす, 桁DP](https://atcoder.jp/contests/abc007/submissions/12537048)|
||§ 2.3.1|exercise(digit)|[D - 1](https://atcoder.jp/contests/abc029/tasks/abc029_d)|||[桁DP](https://atcoder.jp/contests/abc029/submissions/12538690)|
||§ 2.3.1|exercise(digit)|[E - Payment](https://atcoder.jp/contests/abc155/tasks/abc155_e)|||[DP(桁)(繰り上がる?)](https://atcoder.jp/contests/abc155/tasks/abc155_e)|
||§ 2.3.1|exercise(digit)|[E - Almost Everywhere Zero](https://atcoder.jp/contests/abc154/tasks/abc154_e)|||[桁DP](https://atcoder.jp/contests/abc154/submissions/12545187)|
||§ 2.3.2|example|[最長共通部分列問題(LCS)](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_C)|||[2次元DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_10_C/review/4408455/knknkn1162/C)|
||§ 2.3.2|exercise|[編集距離](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_E)|||[DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_E/review/4427482/knknkn1162/C)|
||§ 2.3.2|exercise|[DPL_3_A 最大正方形](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_A)|||[DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_A/review/4517230/knknkn1162/C)|
||§ 2.3.3|example|[個数制限なしナップサック問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_C)|||[インライン1次元DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_C/review/4281702/knknkn1162/C)|
||§ 2.3.3|exercise|[ABC 118 D D - Match Matching](https://atcoder.jp/contests/abc118/tasks/abc118_d)|||[大きいものからインラインDP](https://atcoder.jp/contests/abc118/submissions/13573375)|
||§ 2.3.3|exercise|[ABC 153 E - Crested Ibis vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_e)|||[1次元DP](https://atcoder.jp/contests/abc153/submissions/12491440)|
|o|§ 2.3.4|exercise|[ABC 032 D ナップサック問題](https://atcoder.jp/contests/abc032/tasks/abc032_d)|||[価値固定で重さ最小に]()|
|o|§ 2.3.4|exercise|[AOJ DPL_1_F 0-1 ナップザック問題 II](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_F)|||[]()|
|o|§ 2.3.4|exercise|[Educational DP contest E - Knapsack 2](https://atcoder.jp/contests/dp/tasks/dp_e)|||[添字と値の入れ替え, DP]()|
||§ 2.3.4|exercise|[ARC 057 B 高橋君ゲーム](https://atcoder.jp/contests/arc057/tasks/arc057_b)|||[考察、DP](https://atcoder.jp/contests/arc057/submissions/13206104)|
||§ 2.3.5|example|個数制限付き部分和問題|||[残り個数をDPの中に持たせる](./2.3.5/example.c)|
|o|§ 2.3.5|example|[個数制限付きナップザック問題](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_G)|||[]()|
||§ 2.3.5|exercise|[Maximum-Cup 2018 D Many Go Round](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_d)|||[x周をDPの値にする](https://atcoder.jp/contests/maximum-cup-2018/submissions/12458575)|
|o|§ 2.3.5|exercise|[JOI 2013 本選 D フクロモモンガ](https://atcoder.jp/contests/joi2014ho/tasks/joi2014ho4)|||[]()|
||§ 2.3.6|example|[DPL_1_D - 最長増加部分列(LIS)](https://onlinejudge.u-aizu.ac.jp/problems/DPL_1_D)|||[インラインDP,  二分探索](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_D/review/4474200/knknkn1162/C) or [LIS, 座標圧縮、セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_D/review/4474526/knknkn1162/C)|
||§ 2.3.6|exercise|[ABC 006 D トランプ挿入ソート](https://atcoder.jp/contests/abc006/tasks/abc006_4)|||[LIS](https://atcoder.jp/contests/abc006/submissions/11331581)|
||§ 2.3.6|exercise|[ABC 038 D - プレゼント](https://atcoder.jp/contests/abc038/tasks/abc038_d)|||[高さ方向にソート -> LIS(DP版)](https://atcoder.jp/contests/abc038/submissions/13232584) or [高さ方向にまずソート -> LIS, セグメント木(RMQ)](https://atcoder.jp/contests/abc038/submissions/13231531)|
|o|§ 2.3.6|exercise|[TDPC K ターゲット](https://atcoder.jp/contests/tdpc/tasks/tdpc_target)|||[]()|
||§ 2.3.7|example|分割数|||[DP](./2.3.7/example.c)|
||§ 2.3.7|exercise|[No.269 見栄っ張りの募金活動](https://yukicoder.me/problems/no/269)|||[制約を取り除く -> 分割数](https://yukicoder.me/submissions/472404)|
||§ 2.3.7|exercise|[第4回 ドワンゴからの挑戦状 予選 C - Kill/Death](https://atcoder.jp/contests/dwacon2018-prelims/tasks/dwacon2018_prelims_c)|||[分割数とDPの組み合わせ](https://atcoder.jp/contests/dwacon2018-prelims/submissions/12493850)|
|o|§ 2.3.7|exercise|[JOI 2009 予選 F ビンゴ](https://atcoder.jp/contests/joi2009yo/tasks/joi2009yo_f)|||[]()|
|o|§ 2.3.7|exercise|[NTL_1_D オイラーのφ関数](https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D)|||[素因数分解 -> 公式](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_D/review/3981957/knknkn1162/C) or [包除原理]()|
||§ 2.3.8.0|exercise|[ボールと箱 1](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_A)|||[ボール: 区別可, 箱:区別可, 入れ方:制限なし: k^n](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_A/review/4431701/knknkn1162/C)|
||§ 2.3.8.0|exercise|[ボールと箱 2](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_B)|||[ボール: 区別可, 箱:区別可, 入れ方:一つ以下 : k_P_n](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_B/review/4431711/knknkn1162/C)|
|o|§ 2.3.8.0|exercise|[ボールと箱 3](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_C)|||[ボール: 区別可, 箱:区別可, 入れ方:一つ以上]()|
||§ 2.3.8.0|exercise|[ボールと箱 4](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_D)|||[ボール: 区別不可, 箱:区別可, 入れ方:制限なし : k_H_n](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_D/review/4431758/knknkn1162/C)|
||§ 2.3.8.0|exercise|[ボールと箱 5](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_E)|||[ボール: 区別不可, 箱:区別可, 入れ方:1つ以下 : k_C_n](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_E/review/4431769/knknkn1162/C)|
||§ 2.3.8.0|exercise|[ボールと箱 6](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_F)|||[ボール: 区別不可, 箱:区別可, 入れ方:1つ以上 n-1_C_k-1](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_F/review/4431791/knknkn1162/C)|
|o|§ 2.3.8.0|exercise|[ボールと箱 7](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_G)|||[ボール: 区別可, 箱:区別不可, 入れ方:制限なし]()|
||§ 2.3.8.0|exercise|[ボールと箱 8](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_H)|||[ボール: 区別可, 箱:区別不可, 入れ方:1つ以下 : 1 or 0](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_H/review/4431806/knknkn1162/C)|
|o|§ 2.3.8.0|exercise|[ボールと箱 9](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_I)|||[ボール: 区別可, 箱:区別不可, 入れ方:1つ以上]()|
||§ 2.3.8.0|exercise|[ボールと箱 10](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_J)|||[ボール: 区別不可, 箱:区別不可, 入れ方:制限なし : 分割数 P(k, n)](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_J/review/4431844/knknkn1162/C)|
||§ 2.3.8.0|exercise|[ボールと箱 11](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_K)|||[ボール: 区別不可, 箱:区別不可, 入れ方:1つ以下 : 1 or 0](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_K/review/4431814/knknkn1162/C)|
||§ 2.3.8.0|exercise|[ボールと箱 12](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_5_L)|||[ボール: 区別不可, 箱:区別不可, 入れ方:1つ以上 : 分割数: P(k, n-k)](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_5_L/review/4431852/knknkn1162/C)|
||§ 2.3.8.0|exercise|[D - RGB Triplets](https://atcoder.jp/contests/abc162/tasks/abc162_d)|||[1番目の組み合わせ - 2番目の条件を満たさないものを省く](https://atcoder.jp/contests/abc162/submissions/11913543)|
||§ 2.3.8|example|重複組み合わせ|||[DP + 累積和](./2.3.8/example.c)|
||§ 2.3.8|exercise|[D - Factorization](https://atcoder.jp/contests/abc110/tasks/abc110_d)|||[素因数分解、重複組み合わせ、逆元](https://atcoder.jp/contests/abc110/submissions/12515321)|
||§ 2.3.8|exercise|[D - 多重ループ](https://atcoder.jp/contests/abc021/tasks/abc021_d)|||[発想問題、重複組合せ, 逆元](https://atcoder.jp/contests/abc021/submissions/11687036)|
|o|§ 2.3.8|exercise|[D - 表現の自由 ( Freedom of expression )](https://atcoder.jp/contests/arc004/tasks/arc004_4)|||[]()|
||§ 2.3.8|exercise|[ABC 156 E - Roaming](https://atcoder.jp/contests/abc156/tasks/abc156_e)|||[重複組み合わせ](https://atcoder.jp/contests/abc156/submissions/13706356)|
||§ 2.3.8|exercise|[ABC 167 E - Colorful Blocks](https://atcoder.jp/contests/abc167/tasks/abc167_e)|||[重複組み合わせ](https://atcoder.jp/contests/abc167/submissions/13704646)|
||§ 2.3.9|exercise|[K - Stones](https://atcoder.jp/contests/dp/tasks/dp_k)|||[ゲームDP](https://atcoder.jp/contests/dp/submissions/12026820)|
||§ 2.3.9|exercise|[L - Deque](https://atcoder.jp/contests/dp/tasks/dp_l)|||[ゲームDP](https://atcoder.jp/contests/dp/submissions/12078699)|
||§ 2.3.10|exercise|[TDPC I イゥイ](https://atcoder.jp/contests/tdpc/tasks/tdpc_iwi)|||[区間DP](https://atcoder.jp/contests/tdpc/submissions/12484423)|
||§ 2.3.10|exercise|[ALDS_10_B - 連鎖行列積](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_B)|||[区間DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_10_B/review/4290616/knknkn1162/C)|
||§ 2.3.10|exercise|[JOI 2015 本選 2 - ケーキの切り分け 2](https://atcoder.jp/contests/joi2015ho/tasks/joi2015ho_b)|||[環状は二周確保,区間DP](https://atcoder.jp/contests/joi2015ho/submissions/11199863)|
|o|§ 2.3.10|exercise|[AOJ 2415 刺身](https://onlinejudge.u-aizu.ac.jp/problems/2415)|||[区間DP, Monge]()|
||§ 2.3.10|exercise|[ダルマ落とし](https://onlinejudge.u-aizu.ac.jp/problems/1611)|||[O(N^3)の区間DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1611/review/4296429/knknkn1162/C)|
||§ 2.3.11|exercise|[ABC 036 D - 塗り絵](https://atcoder.jp/contests/abc036/tasks/abc036_d)|||[ツリーDP(帰りがけ)](https://atcoder.jp/contests/abc036/submissions/12798698)
||§ 2.3.11|exercise|[ABC 070 D Transit Tree Path](https://atcoder.jp/contests/abc070/tasks/abc070_d)|||[ツリーDP(行きがけ)](https://atcoder.jp/contests/abc070/submissions/12811976)|
|o|§ 2.3.11|exercise|[TDPC N 木](https://atcoder.jp/contests/tdpc/tasks/tdpc_tree)|||[]()|
||§ 2.3.11|exercise|[ABC138 D - Ki](https://atcoder.jp/contests/abc138/tasks/abc138_d)|||[ツリーDP](https://atcoder.jp/contests/abc138/submissions/11952547)|
||§ 2.3.11|exercise|[木の直径](https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_A)|||[全方位木DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_5_A/review/4364257/knknkn1162/C)|
|o|§ 2.3.11|exercise|[木の高さ](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_5_B)|||[全方位木DP]()|
||§ 2.3.11|exercise|[F - Distributing Integers](https://atcoder.jp/contests/abc160/tasks/abc160_f)|||[全方位木DP](https://atcoder.jp/contests/abc160/submissions/11998682)|
||§ 2.3.12|exercise|[AOJ GRL_4_B トポロジカルソート](https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_4_B)|||[DFS, DAG DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_4_B/review/4474367/knknkn1162/C)|
||§ 2.3.12|exercise|[ABC 037 D 経路](https://atcoder.jp/contests/abc037/tasks/abc037_d)|||[out degreeに注意してDAG DP](https://atcoder.jp/contests/abc037/submissions/12767879)
||§ 2.3.12|exercise|[G - Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g)|||[DAG DP](https://atcoder.jp/contests/dp/submissions/12015134)|
||§ 2.3.12|exercise|[H - Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h)|||[DAG DP](https://atcoder.jp/contests/dp/submissions/12024953)|
|o|§ 2.3.13|exercise|[JOI 2006 予選 F 通学経路](https://atcoder.jp/contests/joi2007yo/tasks/joi2007yo_f)|||[グリッドDP]()|
|o|§ 2.3.14|exercise|[JOI 2012 予選 C 最高のピザ](https://atcoder.jp/contests/joi2012yo/tasks/joi2012yo_c)|||[]()|
||§ 2.3.15|example|部分文字列DP|[]()|||[貰うDP](./2.3.15/example.c) or [配るDP](./2.3.15/example2.c)|
|o|§ 2.3.15|exercise|[ARC 081 E Don't Be a Subsequence](https://atcoder.jp/contests/arc081/tasks/arc081_c)|||[]()|
||§ 2.3.15|exercise|[ABC 104 D - We Love ABC](https://atcoder.jp/contests/abc104/tasks/abc104_d)|||[部分文字列DP(重複を許すパターン)](https://atcoder.jp/contests/abc104/submissions/13758841)|
|o|§ 2.3.16|exercise|[TDPC O 文字列](https://atcoder.jp/contests/tdpc/tasks/tdpc_string)|||[]()|
||§ 2.3.17|exercise|[TDPC D サイコロ](https://atcoder.jp/contests/tdpc/tasks/tdpc_dice)|||[多次元DP(条件以上となるように計算)](https://atcoder.jp/contests/tdpc/submissions/12709413)|
||§ 2.3.17|exercise|[ABC 122 D - We Like AGC](https://atcoder.jp/contests/abc122/tasks/abc122_d)|||[多次元DP](https://atcoder.jp/contests/abc122/submissions/13558895)
||§ 2.3.17|exercise|[J - Sushi](https://atcoder.jp/contests/dp/tasks/dp_j)|||[期待値、多次元DP](https://atcoder.jp/contests/dp/submissions/12036657)|
||§ 2.4.1|example|[Expedition (POJ No.2431)](http://poj.org/problem?id=2431)|||[max heap, 燃料を後で消費する](./2.4.1/poj2431.c)|
||§ 2.4.1|exercise|[ABC 127 D - Integer Cards](https://atcoder.jp/contests/abc127/tasks/abc127_d)|||[操作を最後に消費する(not 二分探索)](https://atcoder.jp/contests/abc127/submissions/13570674)|
||§ 2.4.1|exercise|[ALDS1_9_C priority queue](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_9_C)|||[max heap](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_9_C/review/4495302/knknkn1162/C)|
||§ 2.4.1|exercise|[2017 CODE FESTIVAL THANKS C - Factory](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_c)|||[min heap](https://atcoder.jp/contests/code-thanks-festival-2017-open/submissions/12522002)|
||§ 2.4.1|exercise|[ABC 062 D - 3N Numbers](https://atcoder.jp/contests/arc074/tasks/arc074_b)|||[配列と逆配列をmin heap](https://atcoder.jp/contests/arc074/submissions/12810109)|
||§ 2.4.1|exercise|[ABC 116 D - Various Sushi](https://atcoder.jp/contests/abc116/tasks/abc116_d)|||[xをmaxから減らして貪欲法で、max heap](https://atcoder.jp/contests/abc116/submissions/13670407)|
||§ 2.4.2|exercise|[ABC 085 B Kagami Mochi](https://atcoder.jp/contests/abc085/tasks/abc085_b)|||[map](https://atcoder.jp/contests/abc085/submissions/7997905)|
||§ 2.4.2|exercise|[ABC 098 B - Cut and Count](https://atcoder.jp/contests/abc098/tasks/abc098_b)|||[map](https://atcoder.jp/contests/abc098/submissions/13929585)|
||§ 2.4.2|exercise|[ABC 111 C - /\/\/\/](https://atcoder.jp/contests/abc111/tasks/arc103_a)|||[map](https://atcoder.jp/contests/abc111/submissions/13679666)|
||§ 2.4.2|exercise|[ABC 099 D - Good Grid](https://atcoder.jp/contests/abc099/tasks/abc099_d)|||[前処理、colorに対して全探索、map](https://atcoder.jp/contests/abc099/submissions/13838264)|
||§ 2.4.2|exercise|[ABC 110 C - String Transformation](https://atcoder.jp/contests/abc110/tasks/abc110_c)|||[map2つ(1対1対応のチェック)](https://atcoder.jp/contests/abc110/submissions/13679923)|
||§ 2.4.2|exercise|[ABC 166 E - This Message Will Self-Destruct in 5s](https://atcoder.jp/contests/abc166/tasks/abc166_e)|||[hash](https://atcoder.jp/contests/abc166/submissions/13456209) or [mapで十分]()|
||§ 2.4.2|exercise|[ABC 143 D - Triangles](https://atcoder.jp/contests/abc143/tasks/abc143_d)|||[map, 累積和](https://atcoder.jp/contests/abc143/submissions/13893107)|
||§ 2.4.2|exercise|[ABC 105 D - Candy Distribution](https://atcoder.jp/contests/abc105/tasks/abc105_d)|||[累積和のmap](https://atcoder.jp/contests/abc105/submissions/13742036)|
|o|§ 2.4.2|exercise|[ABC 091 B Two Colors Card Game](https://atcoder.jp/contests/abc091/tasks/abc091_b)|||[]()|
|o|§ 2.4.2.1|exercise|[ABC 158 E - Divisible Substring](https://atcoder.jp/contests/abc158/tasks/abc158_e)|||[剰余、累積和のmap]()|
||§ 2.4.2.1|exercise|[ABC 164 D - Multiple of 2019](https://atcoder.jp/contests/abc164/tasks/abc164_d)|||[剰余、累積和のmap](https://atcoder.jp/contests/abc164/submissions/12546914)|
||§ 2.4.2.1|exercise|[ABC 096 D - Five, Five Everywhere](https://atcoder.jp/contests/abc096/submissions/13919563)|||[構成問題、発想問題、数学的考察、同じ剰余の数を集める, map](https://atcoder.jp/contests/abc096/submissions/13919563)|
||§ 2.4.3|example|[食物連鎖 (POJ No.1182)](http://poj.org/problem?id=1182)|||[3×numberのunion find](./2.4.3/poj1182.c)|
||§ 2.4.3|exercise|[ATC 001 B Union Find](https://atcoder.jp/contests/atc001/tasks/unionfind_a)|||[Union Find](https://atcoder.jp/contests/atc001/submissions/12844290)|
||§ 2.4.3|exercise|[ABC 049 D 連結](https://atcoder.jp/contests/abc049/tasks/arc065_b)|||[union find, ハッシュ](https://atcoder.jp/contests/abc049/submissions/12697315)|
||§ 2.4.3|exercise|[ABC 157 D - Friend Suggestions](https://atcoder.jp/contests/abc157/tasks/abc157_d)|||[Union Find](https://atcoder.jp/contests/abc157/submissions/11931508)|
||§ 2.4.3|exercise|[ARC 097 D Equals](https://atcoder.jp/contests/arc097/tasks/arc097_b)|||[Union Find](https://atcoder.jp/contests/arc097/submissions/12697803)|
||§ 2.4.3|exercise|[ARC 036 D 偶数メートル](https://atcoder.jp/contests/arc036/tasks/arc036_d)|||[2×num のUnion Find](https://atcoder.jp/contests/arc036/submissions/12701345)|
||§ 2.4.3|exercise|[ABC 126 E - 1 or 2](https://atcoder.jp/contests/abc126/tasks/abc126_e)|||[2×numのUnion Find](https://atcoder.jp/contests/abc126/submissions/13533399)|
||§ 2.4.3|exercise|[AtCoder Beginner Contest 120 D - Decayed Bridge](https://atcoder.jp/contests/abc120/tasks/abc120_d)|||[Union-Find, 累積和](https://atcoder.jp/contests/abc120/submissions/11458940)|
||§ 2.4.3|exercise|[重み付きUnion Find木](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B)|||[重み付きUnion Find木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_1_B/review/4432248/knknkn1162/C)|
||§ 2.4.3|exercise|[ABC 087 D People on a Line](https://atcoder.jp/contests/abc087/tasks/arc090_b)|||[重み付きUnion Find木](https://atcoder.jp/contests/abc087/submissions/12848387)|
||§ 2.5.1|example|二部グラフ判定|||[DFS](./2.5.1/example.c)|
||§ 2.5.1|exercise|[D - Even Relation](https://atcoder.jp/contests/abc126/tasks/abc126_d)|||[DFS](https://atcoder.jp/contests/abc126/submissions/12559729)|
||§ 2.5.1|exercise|[C - 3 Steps](https://atcoder.jp/contests/code-festival-2017-qualb/tasks/code_festival_2017_qualb_c)|||[考察、union find](https://atcoder.jp/contests/code-festival-2017-qualb/submissions/12826017)|
||§ 2.5.1|exercise|[C - 嘘つきな天使たち](https://atcoder.jp/contests/maximum-cup-2018/tasks/maximum_cup_2018_c)|||[二部グラフとして解く]() or [Union Find(食物連鎖と類似)](https://atcoder.jp/contests/maximum-cup-2018/submissions/12561301)|
|o|§ 2.5.2|example|[Roadblocks (POJ No.3255)](http://poj.org/problem?id=3255)|||[]()|
||§ 2.5.2|exercise|[JOI 2007 予選 F 船旅](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f)|||[ダイクストラ+ min heap](https://atcoder.jp/contests/joi2008yo/submissions/11579403)|
||§ 2.5.2|exercise|[ABC 035 D トレジャーハント](https://atcoder.jp/contests/abc035/tasks/abc035_d)|||[ダイクストラ法(往路と復路)](https://atcoder.jp/contests/abc035/submissions/12693567)|
||§ 2.5.3|exercise|[GRL_2_A - 最小全域木](https://onlinejudge.u-aizu.ac.jp/problems/GRL_2_A)|||[クラスカル法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_2_A/review/4333233/knknkn1162/C)|
||§ 2.5.3|exercise|[AOJ 1127 - Building a Space Station](https://onlinejudge.u-aizu.ac.jp/problems/1127)|||[クラスカル法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/1127/review/4333742/knknkn1162/C)|
||§ 2.5.3|exercise|[ABC 065 D Built?](https://atcoder.jp/contests/abc065/tasks/arc076_b)|||[ソート -> クラスカル法](https://atcoder.jp/contests/abc065/submissions/11662019)|
||§ 2.5.4|example|[Layout (POJ No.3169)](http://poj.org/problem?id=3169)|||[牛ゲー、ベルマンフォード法](./2.5.4/poj3169.c)|
||§ 2.5.4|exercise|[AOJ Course 単一始点最短経路（負の重みをもつ辺を含む）](https://onlinejudge.u-aizu.ac.jp/problems/GRL_1_B)|||[ベルマンフォード法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/GRL_1_B/review/4423742/knknkn1162/C)
||§ 2.5.4|exercise|[D - Score Attack](https://atcoder.jp/contests/abc061/tasks/abc061_d)|||[Bellman ford, 閉路検出](https://atcoder.jp/contests/abc061/submissions/12686297)|
|o|§ 2.5.4|exercise|[UTPC 2013 H Asteroids2](https://atcoder.jp/contests/utpc2013/tasks/utpc2013_08)|||[考察、牛ゲー, ベルマンフォード法]()|
||§ 2.5.5|exercise|[D - バスと避けられない運命](https://atcoder.jp/contests/abc012/tasks/abc012_4)|||[Warshal Fyold](https://atcoder.jp/contests/abc012/submissions/11640675)|
||§ 2.5.5|exercise|[D - joisino's travel](https://atcoder.jp/contests/abc073/tasks/abc073_d)|||[ワーシャルフロイド法, permutation](https://atcoder.jp/contests/abc073/submissions/12688097)|
|o|§ 2.5.5|exercise|[DPL_2_B 中国人郵便配達問題](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_2_B)|||[ワーシャルフロイド法、bitDP]()|
|o|§ 2.6.1|example|線分上の格子点の個数|||[]()|
||§ 2.6.1|exercise|[ABC 109 C - Skip](https://atcoder.jp/contests/abc109/tasks/abc109_c)|||[GCD](https://atcoder.jp/contests/abc109/submissions/13680345)|
||§ 2.6.1|exercise|[ABC 118 C - Monsters Battle Royale](https://atcoder.jp/contests/abc118/tasks/abc118_c)|||[GCD](https://atcoder.jp/contests/abc118/submissions/13571050)|
||§ 2.6.2|exercise|[AOJ Course NTL_1_E - 拡張ユークリッドの互除法](https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_E)|||[拡張ユークリッド法そのまま](https://onlinejudge.u-aizu.ac.jp/solutions/problem/NTL_1_E/review/4433567/knknkn1162/C)|
|o|§ 2.6.3|example|素数判定|||[]()|
||§ 2.6.3|exercise|[ABC 112 D - Partition](https://atcoder.jp/contests/abc112/tasks/abc112_d)|||[約数](https://atcoder.jp/contests/abc112/tasks/abc112_d)|
||§ 2.6.3|exercise|[C - Factors of Factorial](https://atcoder.jp/contests/abc052/tasks/arc067_a)|||[素因数分解、約数の個数](https://atcoder.jp/contests/abc052/submissions/12487335)|
||§ 2.6.3|exercise|[ABC 084 D 2017-like Number](https://atcoder.jp/contests/abc084/submissions/11665020)|||[素数, 累積和](https://atcoder.jp/contests/abc084/submissions/11665020)|
|o|§ 2.6.3|exercise|[AOJ 0009 素数](https://onlinejudge.u-aizu.ac.jp/problems/0009)|||[エラトステネスのふるい、累積和]()|
||§ 2.6.4|exercise|[A - 与えられた数より小さい素数の個数について](https://atcoder.jp/contests/tenka1-2012-qualc/tasks/tenka1_2012_9)|||[エラトステネスのふるい](https://atcoder.jp/contests/tenka1-2012-qualc/submissions/12817314)
||§ 2.6.4|exercise|[素数](https://onlinejudge.u-aizu.ac.jp/problems/0009)|||[エラトステネスのふるい](https://onlinejudge.u-aizu.ac.jp/solutions/problem/0009/review/4433621/knknkn1162/C)|
||§ 2.6.4|exercise|[ABC 169 D - Div Game](https://atcoder.jp/contests/abc169/tasks/abc169_d)|||[エラトステネスのふるい](https://atcoder.jp/contests/abc169/submissions/13950098)|
||§ 2.6.4|exercise|[ABC D - 756](https://atcoder.jp/contests/abc114/tasks/abc114_c)|||[素因数分解、再帰関数](https://atcoder.jp/contests/abc114/submissions/13678388)|
||§ 2.6.5|example|区間内の素数の個数|||[]()|
||§ 2.6.6|example|[Carmichael Numbers (Uva No.10006)](https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=947)|||[高速累乗](./2.6.6/uva10006.c)|
||§ 2.6.6|example|[Square869120Contest #1 E - 散歩](https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_e)|||[bit演算, いもす法, 高速累乗](https://atcoder.jp/contests/s8pc-1/submissions/11667270)|
||§ 2.6.7|exercise|[ABC 165 D - Floor Function](https://atcoder.jp/contests/abc165/tasks/abc165_d)|||[数学的考察](https://atcoder.jp/contests/abc165/submissions/12889778)|
||§ 2.6.7|exercise|[ABC 108 C - Triangular Relationship](https://atcoder.jp/contests/abc108/tasks/arc102_a)|||[数学的考察](https://atcoder.jp/contests/abc108/submissions/13687394)|
||§ 2.6.7|exercise|[ABC 105 C - Base -2 Number](https://atcoder.jp/contests/abc105/tasks/abc105_c)|||[数学的考察、普通の2進数表示 -> carry](https://atcoder.jp/contests/abc105/submissions/13712126)|
||§ 2.6.7|exercise|[ABC 121 D - XOR World](https://atcoder.jp/contests/abc121/tasks/abc121_d)|||[数学的考察](https://atcoder.jp/contests/abc121/submissions/13560004)|
||§ 2.6.7|exercise|[ABC 125 D - Flipping Signs](https://atcoder.jp/contests/abc125/tasks/abc125_d)|||[数学的考察](https://atcoder.jp/contests/abc125/submissions/13467844)|
||§ 2.6.7|exercise|[ABC 120 C - Unification](https://atcoder.jp/contests/abc120/tasks/abc120_c)|||[発想問題、考察](https://atcoder.jp/contests/abc120/submissions/13689906)|
||§ 2.6.7|exercise|[ABC 139 D - ModSum](https://atcoder.jp/contests/abc139/tasks/abc139_d)|||[数学的考察](https://atcoder.jp/contests/abc139/submissions/11487225)|
||§ 2.6.7|exercise|[ABC 094 D - Binomial Coefficients](https://atcoder.jp/contests/abc094/tasks/arc095_b)|||[数学的考察, `(n+1)_C_r > n_C_r`](https://atcoder.jp/contests/abc094/submissions/13923844)|
||§ 2.6.7|exercise|[ABC 101 C - Minimization](https://atcoder.jp/contests/abc101/tasks/arc099_a)|||[考察(数列の形によらない)](https://atcoder.jp/contests/abc101/submissions/13770626)|
||§ 2.6.7|exercise|[DDCC2020 予選 D - Digit Sum Replace](https://atcoder.jp/contests/ddcc2020-qual/tasks/ddcc2020_qual_d)|||[数学的考察(数字の遷移方法は2パターンのうちどれか)](https://atcoder.jp/contests/ddcc2020-qual/submissions/11700593)|
||§ 2.6.7|exercise|[ABC 126 F - XOR Matching](https://atcoder.jp/contests/abc126/tasks/abc126_f)|||[数学的考察](https://atcoder.jp/contests/abc126/submissions/13534345)|
||§ 2.6.7|exercise|[Tenka1 Programmer Beginner Contest D - Crossing](https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d)|||[構成問題、部分集合の要素数を決める, n=1も考慮](https://atcoder.jp/contests/tenka1-2018-beginner/submissions/11702203)|
||§ 2.7.1|example|[GCJ Problem A. Minimum Scalar Product](https://code.google.com/codejam/contest/32016/dashboard)|||[ソート, 貪欲法](./2.7.1/gcj32016.c)
|o|§ 3.1.1|example|lower bound|||[lower bound](./3.1.1/example.c)|
||§ 3.1.1|exercise|[ABC 077 C Snuke Festival](https://atcoder.jp/contests/abc077/tasks/arc084_a)|||[中部を軸にlower/upper bound](https://atcoder.jp/contests/abc077/submissions/10816319)|
||§ 3.1.1|exercise|[JOI 2007 本選 C ダーツ](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_c)|||[半分全列挙, 解を仮定して二分検索(upper bound)](https://atcoder.jp/contests/joi2008ho/submissions/10906780)|
||§ 3.1.1|exercise|[JOI 2008 本選 B ピザ](https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_b)|||[二分探索](https://atcoder.jp/contests/joi2009ho/submissions/10814537)
||§ 3.1.2|example|[Cable Master (POJ No.1064)](http://poj.org/problem?id=1064)|||[整数に。解を仮定して二分探索](./3.1.2/poj1064.c)|
||§ 3.1.2|exercise|[ABC 023 D 射撃王](https://atcoder.jp/contests/abc023/tasks/abc023_d)|||[解を仮定してで二分検索(lower bound)](https://atcoder.jp/contests/abc023/submissions/11029093)|
||§ 3.1.2|exercise|[ARC 037 C 億マス計算](https://atcoder.jp/contests/arc037/tasks/arc037_c)|||[ソート -> 解を仮定し二分探索(upper bound) -> 判定でも二分探索(upper bound)](https://atcoder.jp/contests/arc037/submissions/12878074)|
||§ 3.1.2|exercise|[AOJ ALDS1_4_D 割り当て](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_D)|||[解を仮定して二分探索 -> 各探索値で線形探索](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_4_D) or [累積和, 解を仮定して二分探索 -> 各探索値で線形探索](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_4_D/review/4344863/knknkn1162/C)|
||§ 3.1.2|exercise|[D - Calculating GCD](https://atcoder.jp/contests/judge-update-202004/tasks/judge_update_202004_d)|||[累積和(gcd) -> 二分探索](https://atcoder.jp/contests/judge-update-202004/submissions/12197056)|
||§ 3.1.2|exercise|[ABC 155 D - Pairs](https://atcoder.jp/contests/abc155/tasks/abc155_d)|||[]()|
||§ 3.1.2|exercise|[ARC 050 B 花束](https://atcoder.jp/contests/arc050/tasks/arc050_b)|||[解を仮定して二分探索](https://atcoder.jp/contests/arc050/submissions/12885103)|
||§ 3.1.2|exercise|[ABC 146 C - Buy an Integer](https://atcoder.jp/contests/abc146/tasks/abc146_c)|||[二分検索(lower bound), 型に注意](https://atcoder.jp/contests/abc146/submissions/12877286)|
||§ 3.1.3|example|[Aggressive Cows (POJ No.2456)](http://poj.org/problem?id=2456)|||[解を仮定して二分探索](./3.1.2/poj2456.c)|
||§ 3.1.3|exercise|[CODE FESTIVAL 2015 予選A D 壊れた電車](https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_d)|||[最大値の型と定め方に注意](https://atcoder.jp/contests/code-festival-2015-quala/submissions/12897314)|
||§ 3.1.3|exercise|[JOI 2013 本選 C バームクーヘン](https://atcoder.jp/contests/joi2014ho/tasks/joi2014ho3)|||[](https://atcoder.jp/contests/joi2014ho/submissions/12897638)|
||§ 3.1.4|exercise|[ABC 034 D - 食塩水](https://atcoder.jp/contests/abc034/tasks/abc034_d)|||[発想問題、解を仮定して二分探索](https://atcoder.jp/contests/abc034/submissions/12901092)|
||§ 3.1.4|exercise|[ARC 026 D 道を直すお仕事](https://atcoder.jp/contests/arc026/tasks/arc026_4)|||[解を仮定して二分探索、探索内部でUnion Find](https://atcoder.jp/contests/arc026/submissions/12904843)|
||§ 3.2.1|example|[Subsequence (POJ No.3061)](http://poj.org/problem?id=3061)|||[尺取法](./3.2.1/poj3061.c)|
||§ 3.2.1|exercise|[DSL_3_A The Smallest Window I](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_A)|||[尺取法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_A/review/4468038/knknkn1162/C)|
||§ 3.2.1|exercise|[DSL_3_B The Smallest Window II](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_B)|||[尺取法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_B/review/4468410/knknkn1162/C)|
||§ 3.2.1|exercise|[AOJ Course The Number of Windows](https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_C)|||[尺取法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_C/review/4473359/knknkn1162/C)
||§ 3.2.1|exercise|[ABC 032 C 列](https://atcoder.jp/contests/abc032/tasks/abc032_c)|||[尺取法](https://atcoder.jp/contests/abc032/submissions/12929277)|
||§ 3.2.1|exercise|[ABC 038 C 単調増加](https://atcoder.jp/contests/abc038/tasks/abc038_c)|||[尺取法](https://atcoder.jp/contests/abc038/submissions/12952989)|
||§ 3.2.1|exercise|[ARC 098 D Xor Sum 2](https://atcoder.jp/contests/arc098/tasks/arc098_b)|||[尺取法](https://atcoder.jp/contests/arc098/submissions/12953249)|
||§ 3.2.2|exercise|[Jessica's Reading Problem (POJ No.3320)](http://poj.org/problem?id=3320)|||[mapを用いて尺取法](./3.2.2/poj3320.c)|
||§ 3.2.2|exercise|[ARC 022 B 細長いお菓子](https://atcoder.jp/contests/arc022/tasks/arc022_2)|||[mapを使って尺取法](https://atcoder.jp/contests/arc022/submissions/12954764)|
||§ 3.2.2|exercise|[ABC 017 D - サプリメント](https://atcoder.jp/contests/abc017/tasks/abc017_4)|||[mapを使って尺取法, 累積和](https://atcoder.jp/contests/abc017/submissions/13220134)|
||§ 3.2.2|exercise|[ABC 119 D - Lazy Faith](https://atcoder.jp/contests/abc119/tasks/abc119_d)|||[尺取法っぽく、クエリに関しては二分探索](https://atcoder.jp/contests/abc119/submissions/13566020)|
|o|§ 3.2.2|exercise|[ABC 033 D 三角形の分類](https://atcoder.jp/contests/abc033/tasks/abc033_d)|||[]()|
||§ 3.2.3|example|[Face The Right Way (POJ No.3276)](http://poj.org/problem?id=3276)|||[flipの回数を保存](./3.2.3/poj3276.c)|
||§ 3.2.3|exercise|[ABC 048 C Boxes and Candies](https://atcoder.jp/contests/arc064/tasks/arc064_a)|||[貪欲, 番兵](https://atcoder.jp/contests/arc064/submissions/12968254)|
||§ 3.2.3|exercise|[ABC 083 D Wide Flip](https://atcoder.jp/contests/arc088/tasks/arc088_b)|||[境目でflip](https://atcoder.jp/contests/arc088/submissions/12973023)|
||§ 3.2.3|exercise|[JOI 2008 本選 1 - 碁石ならべ](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_a)|||[stack, ランレングス圧縮](https://atcoder.jp/contests/joi2008ho/submissions/11465819)|
||§ 3.2.3|exercise|[JOI 2012 本選 A 電飾](https://atcoder.jp/contests/joi2013ho/tasks/joi2013ho1)|||[stack, ランレングス圧縮](https://atcoder.jp/contests/joi2013ho/submissions/11466663)|
||§ 3.2.3|exercise|[ABC 124 D - Handstand](https://atcoder.jp/contests/abc124/tasks/abc124_d)|||[ランレングス圧縮](https://atcoder.jp/contests/abc124/submissions/13535422)|
|o|§ 3.2.3|exercise|[JOI 2008 本選 C あみだくじ](https://atcoder.jp/contests/joi2009ho/tasks/joi2009ho_c)|||[]()|
||§ 3.2.4|example|[Fliptile (POJ No.3279)](http://poj.org/problem?id=3279)|||[bit全探索、貪欲法(実装重)](./3.2.4/poj3279.c)|
||§ 3.2.4|exercise|[JOI 2007 予選 E おせんべい](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_e)|||[bit全探索、貪欲法](https://atcoder.jp/contests/joi2008yo/submissions/10734695)|
||§ 3.2.4|exercise|[ABC 159 E - Dividing Chocolate](https://atcoder.jp/contests/abc159/tasks/abc159_e)|||[bit全探索、貪欲法](https://atcoder.jp/contests/abc159/submissions/11922152)|
||§ 3.2.4|exercise|[ABC 018 D バレンタインデー](https://atcoder.jp/contests/abc018/tasks/abc018_4)|||[bit全探索、貪欲法](https://atcoder.jp/contests/abc018/submissions/12980160)|
||§ 3.2.4|exercise|[ABC 113 D - Number of Amidakuji](https://atcoder.jp/contests/abc113/tasks/abc113_d)|||[bit(あみだの棒)全探索、DP](https://atcoder.jp/contests/abc113/submissions/13951290)|
||§ 3.2.5|example|[Physics Experiment (POJ No.3684)](http://poj.org/problem?id=3684)|||[弾性衝突](./3.2.5/poj3684.cpp)|
||§ 3.2.6|example|[4 Values whose Sum is 0 (POJ No.2785)](http://poj.org/problem?id=2785)|||[半分全列挙](./3.2.6/poj2785.c)|
|o|§ 3.2.6|exercise|[DPL_4_A コインの組み合わせ](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_4_A)|||[]()|
||§ 3.2.7|example|[巨大ナップザック問題](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H)|||[半分全列挙](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_1_H/review/4450774/knknkn1162/C)|
|o|§ 3.2.7|exercise|[ABC 032 D - ナップサック問題](https://atcoder.jp/contests/abc032/tasks/abc032_d)|||[]()|
|o|§ 3.2.7|exercise|[CODE THANKS FESTIVAL 2017 G - Mixture Drug](https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_g)|||[]()|
|o|§ 3.2.7|exercise|[JOI 2015 予選 6 - 財宝](https://atcoder.jp/contests/joi2015yo/tasks/joi2015yo_f)|||[]()|
|o|§ 3.2.7|exercise|[DPL_4_B コインの組み合わせ II](https://onlinejudge.u-aizu.ac.jp/problems/DPL_4_B)|||[半分全列挙]()|
||§ 3.2.7|example|[C - String Coloring](https://atcoder.jp/contests/agc026/tasks/agc026_c)|||[]()|
||§ 3.2.8|example|座標圧縮|||[座標圧縮](./3.2.8/example.c)|
||§ 3.2.8|exercise|[ABC 036 C - 座圧](https://atcoder.jp/contests/abc036/tasks/abc036_c)|||[map, hash(座標圧縮)](https://atcoder.jp/contests/abc036/submissions/13150217)|
||§ 3.2.8|exercise|[ABC 113 C - ID](https://atcoder.jp/contests/abc113/tasks/abc113_c)|||[map, hash(座標圧縮)](https://atcoder.jp/contests/abc113/submissions/13151102)|
||§ 3.2.8|exercise|[DSL_4_A Union of Rectangles](https://onlinejudge.u-aizu.ac.jp/problems/DSL_4_A)|||[座標圧縮, imos法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_4_A/review/4464721/knknkn1162/C)|
||§ 3.2.8|exercise|[JOI 2007 本選 E ペンキの色](https://atcoder.jp/contests/joi2008ho/tasks/joi2008ho_e)|||[座標圧縮、imos法, BFS](https://atcoder.jp/contests/joi2008ho/submissions/13122755)|
|o|§ 3.2.8|exercise|[JOI 2012 予選 E 魚の生息範囲](https://atcoder.jp/contests/joi2013yo/tasks/joi2013yo_e)|||[3次元]()|
|o|§ 3.2.8|exercise|[AOJ 2426 宝探し](https://onlinejudge.u-aizu.ac.jp/problems/2426)|||[]()|
|o|§ 3.2.9|example|[Crane (POJ No.2991)](http://poj.org/problem?id=2991)|||[セグメント木(難)]()|
||§ 3.3.1|exercise|[DSL_2_A Range Minimum Query(RMQ)](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_A)|||[セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_A/review/4461035/knknkn1162/C)|
||§ 3.3.1|exercise|[DSL_2_B Range Sum Query(RSQ)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B)|||[セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_B/review/4465240/knknkn1162/C)|
||§ 3.3.1|exercise|[DSL_2_D Range Update Query(RUQ)](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_D)|||[更新順をセグメント木に持たせる](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_D/review/4465450/knknkn1162/C)|
||§ 3.3.1|exercise|[DSL_2_E Range Add Query(RAQ)](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_E)|||[セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_E/review/4495892/knknkn1162/C)|
|o|§ 3.3.1|exercise|[AGC 004 B - Colorful Slimes](https://atcoder.jp/contests/agc004/tasks/agc004_b)|||[]()|
||§ 3.3.1|exercise|[ABC 157 E - Simple String Queries](https://atcoder.jp/contests/abc157/tasks/abc157_e)|||[セグメント木、bit演算](https://atcoder.jp/contests/abc157/submissions/13210480)|
||§ 3.3.1|exercise|[ABC 153 F - Silver Fox vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_f)|||[昇順にソート -> 貪欲, 尺取法, セグメント木](https://atcoder.jp/contests/abc153/submissions/13222201) or [昇順にソート -> 貪欲,尺取法, いもす法](https://atcoder.jp/contests/abc153/submissions/13222079)|
|o|§ 3.3.1|exercise|[Japan Alumni Group Summer Camp 2013 Day 2 G Perm Query](https://atcoder.jp/contests/jag2013summer-day2/tasks/icpc2013summer_day2_g)|||[]()|
||§ 3.3.1|exercise|[ARC 008 D タコヤキオイシクナール](https://atcoder.jp/contests/arc008/tasks/arc008_4)|||[一次関数の合成関数、座標圧縮->セグメント木](https://atcoder.jp/contests/arc008/submissions/13185643)|
|o|§ 3.3.1|exercise|[みんなのプロコン 2017 D 工場](https://atcoder.jp/contests/yahoo-procon2017-qual/tasks/yahoo_procon2017_qual_d)|||[]()|
||§ 3.3.1|exercise|[Educational DP contest Q - Flowers](https://atcoder.jp/contests/dp/tasks/dp_q)|||[LIS, セグメント木](https://atcoder.jp/contests/dp/submissions/13228186)|
||§ 3.3.1|exercise|[JOI 2011 春合宿 day4-2 本棚](https://atcoder.jp/contests/joisc2011/tasks/joisc2011_bookshelf) [問題はここ](https://www.ioi-jp.org/camp/2011/2011-sp-tasks/2011-sp-day4.pdf)|||[LIS, セグメント木](https://atcoder.jp/contests/joisc2011/submissions/13505516)|
|o|§ 3.3.1|exercise|[ABC 136 F - Enclosed Points](https://atcoder.jp/contests/abc136/tasks/abc136_f)|||[]()|
|o|§ 3.3.1|exercise|[JOI 2011 本選 5 - 微生物実験]()|||[]()|
||§ 3.3.2|example|[バブルソートの交換回数(反転数)](https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_5_D)|||[反転数、座標圧縮、セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_5_D/review/4478150/knknkn1162/C) or [配列の逆順に反転数を導出](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_5_D/review/4521670/knknkn1162/C)|
||§ 3.3.2|exercise|[Indeedなう 2015 E Line up!](https://atcoder.jp/contests/indeednow-finalb-open/tasks/indeednow_2015_finalb_e)|||[座標圧縮, 転倒数、セグメント木](https://atcoder.jp/contests/indeednow-finalb-open/submissions/13257883)|
|o|§ 3.3.2|exercise|[AOJ 0365 - 文字列スワップ](https://onlinejudge.u-aizu.ac.jp/problems/0365)|||[]()|
|o|§ 3.3.2|exercise|[Tenka1 2017 E CARtesian Coodinate](https://atcoder.jp/contests/tenka1-2017/tasks/tenka1_2017_e)|||[]()|
|o|§ 3.3.2|exercise|[ARC 088 E Papple Sort](https://atcoder.jp/contests/arc088/tasks/arc088_c)|||[]()|
|o|§ 3.3.2|exercise|[第2回早稲田大学プログラミングコンテスト G だるま落とし](https://atcoder.jp/contests/wupc2nd/tasks/wupc_07)|||[]()|
||§ 3.3.3|exercise|[DSL_2_F RMQ and RUQ](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F)|||[遅延評価セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_F/review/4488807/knknkn1162/C)|
||§ 3.3.3|example|[DSL_2_G RSQ and RAQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_G)|||[遅延評価セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_G/review/4488815/knknkn1162/C)|
||§ 3.3.3|exercise|[DSL_2_H RMQ and RAQ](https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_H)|||[遅延評価セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_H/review/4491964/knknkn1162/C)|
||§ 3.3.3|exercise|[DSL_2_I RSQ and RUQ](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_I)|||[遅延評価セグメント木](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_I/review/4492093/knknkn1162/C)|
||§ 3.3.3|exercise|[全国統一プログラミング王決定戦本選-D Deforestation](https://atcoder.jp/contests/nikkei2019-final/tasks/nikkei2019_final_d)|||[発想問題、配列を逆順にして遅延セグメント木(RSQ & RUQ)](https://atcoder.jp/contests/nikkei2019-final/submissions/13646149)|
||§ 3.3.3|exercise|[CODE FESTIVAL 2015 決勝 D 足ゲームII](https://atcoder.jp/contests/code-festival-2015-final-open/tasks/codefestival_2015_final_d)|||[](https://atcoder.jp/contests/code-festival-2015-final-open/submissions/13663382)|
||§ 3.3.3|exercise|[square869120Contest #2 H Counting 1's](https://atcoder.jp/contests/s8pc-2/tasks/s8pc_2_h)|||[反転回数を遅延値として、遅延評価セグメント木(RSQ & RAQ)](https://atcoder.jp/contests/s8pc-2/submissions/13661888)|
|o|§ 3.3.3|exercise|[JOI 2008 春合宿 - Typhoon(台風)](https://atcoder.jp/contests/joisc2008/tasks/joisc2008_typhoon) ([問題はここ](https://www.ioi-jp.org/camp/2008/2008-sp-tasks/2008-sp_tr-day4_24.pdf#page=2))|||[]()|
|o|§ 3.3.3|exercise|[JOI 2012 春合宿 - Fortune Telling](https://atcoder.jp/contests/joisc2012/tasks/joisc2012_fortune_telling) ([問題はここ](https://www.ioi-jp.org/camp/2012/2012-sp-tasks/2012-sp-day3.pdf#page=1)|||[]()|
|△|§ 3.3.4|example|[POJ 2104 K-th Number](http://poj.org/problem?id=2104)|||[平方分割(ただしTLE)](./3.3.4/poj2104.c)|
||§ 3.3.4|exercise|[ARC 033 C データ構造](https://atcoder.jp/contests/arc033/tasks/arc033_3)|||[セグメント木, 二分探索](https://atcoder.jp/contests/arc033/submissions/13276065)|
||§ 3.3.5|example|[DSL_2_C 領域探索（kD 木）](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_C)|||[X軸とY軸で二分探索](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_2_C/review/4481646/knknkn1162/C)|
||§ 3.3.6|example|[巡回セールスマン問題](https://onlinejudge.u-aizu.ac.jp/problems/DPL_2_A)|||[bit DP](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_2_A/review/4300234/knknkn1162/C)|
||§ 3.3.6|example|[Educational DP contest U - Grouping](https://atcoder.jp/contests/dp/tasks/dp_u)|||[bitDP, 部分集合の導出](https://atcoder.jp/contests/dp/submissions/13521889)|
||§ 3.3.6|exercise|[JOI 2016 予選 D ぬいぐるみの整理](https://atcoder.jp/contests/joi2017yo/tasks/joi2017yo_d)|||[bitDP, 累積和](https://atcoder.jp/contests/joi2017yo/submissions/11263795)|
||§ 3.3.6|exercise|[ABC 041 D 徒競走](https://atcoder.jp/contests/abc041/tasks/abc041_d)|||[bit DP](https://atcoder.jp/contests/abc041/submissions/13310523)|
||§ 3.6.1|example|[Jack Straws (POJ No.1127)](http://poj.org/problem?id=1127)|||[]()|
||§ 3.6.1|exercise|[ABC 100 D - Patisserie ABC](https://atcoder.jp/contests/abc100/tasks/abc100_d)|||重心計算、see §2.2.4|
||§ 4.4.1|example|[DPL_3_C ヒストグラムの中の最大長方形](https://onlinejudge.u-aizu.ac.jp/problems/DPL_3_C)|||[stack](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_C/review/4517877/knknkn1162/C)|
||§ 4.4.1|exercise|[DPL_3_B 最大長方形](https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_3_B)|||[stack](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_B/review/4517704/knknkn1162/C) or [O(N^3)の解法](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DPL_3_B/review/4517487/knknkn1162/C)|
||§ 4.4.1|exercise|[Areas on the Cross-Section Diagram](https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_3_D)|||[stack 2つ](https://onlinejudge.u-aizu.ac.jp/solutions/problem/ALDS1_3_D/review/4519048/knknkn1162/C)|
|o|§ 4.4.1|exercise|[KUPC 2013 D カーペット](https://atcoder.jp/contests/kupc2013/tasks/kupc2013_d)|||[]()|
|o|§ 4.4.1|exercise|[ARC 081 F Flip and Rectangles](https://atcoder.jp/contests/arc081/tasks/arc081_d)|||[]()|
|o|§ 4.4.1|exercise|[ABC 064 D Insertion](https://atcoder.jp/contests/abc064/tasks/abc064_d)|||[]()|
|o|§ 4.4.1|exercise|[ARC 076 E Connected?](https://atcoder.jp/contests/arc076/tasks/arc076_c)|||[]()|
||§ 4.4.2|example|[DSL_3_D Sliding Minimum Element(スライド最小値)](https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_3_D)|||[deque, (二分探索)](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_D/review/4476479/knknkn1162/C) or [セグメント木(RMQ)](https://onlinejudge.u-aizu.ac.jp/solutions/problem/DSL_3_D/review/4480940/knknkn1162/C)|
|o|§ 4.4.2|exercise|[ARC 077 C pushpush](https://atcoder.jp/contests/arc077/tasks/arc077_a)||[]()|
||misc|exercise|[ABC 123 C - Five Transportations](https://atcoder.jp/contests/abc123/tasks/abc123_c)|||[ボトルネックを考える](https://atcoder.jp/contests/abc123/submissions/13536398)|
